/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_64bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:22:24 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/15 14:36:42 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corrupted_checker.h"
#include "utilities.h"
#include "generic_nm.h"
#include <stdlib.h>

static int						check_symbol_validity(\
		t_ctr_consis *consis, struct symtab_command *sym, int rev)
{
	if (swap32_if(sym->stroff, rev) > consis->size_file ||\
	swap32_if(sym->symoff, rev) > consis->size_file)
	{
		consis->error = 7;
		return (1);
	}
	return (0);
}

static void						check_segment_validity(\
t_ctr_consis *consis, struct load_command *lc, int rev)
{
	unsigned int				i;
	struct segment_command_64	*sc;

	i = 0;
	sc = (void *)lc;
	if (swap64_if(sc->fileoff, rev) > consis->size_file)
		consis->error = 5;
}

static int						check_header_validity(t_ctr_consis *consis,\
		struct mach_header_64 *header, struct load_command *lc, int rev)
{
	if (sizeof(*header) > consis->size_file)
	{
		consis->error = 4;
		return (1);
	}
	if (swap32_if(header->sizeofcmds, rev) > consis->size_file)
	{
		consis->error = 3;
		return (1);
	}
	if (sizeof(*header) + swap32_if(header->ncmds, rev) *\
sizeof(*lc) > consis->size_file)
	{
		consis->error = 2;
		return (1);
	}
	return (0);
}

static void						spe_lc_manage(struct load_command *lc,\
		int rev, t_ctr_consis *consis)
{
	if (swap32_if(lc->cmd, rev) == LC_SYMTAB)
		check_symbol_validity(consis, (struct symtab_command *)lc, rev);
	else if (swap32_if(lc->cmd, rev) == LC_SEGMENT_64)
		check_segment_validity(consis, lc, rev);
}

int								check_64bits(char *ptr, int rev,\
		t_ctr_consis *consis)
{
	uint64_t					actual_offset;
	unsigned int				i;
	struct mach_header_64		*header;
	struct load_command			*lc;

	i = 0;
	lc = 0;
	header = (struct mach_header_64 *)ptr;
	check_header_validity(consis, header, lc, rev);
	lc = (void *)ptr + sizeof(*header);
	actual_offset = sizeof(*header);
	if (consis->size_file < swap32_if(lc->cmdsize, rev))
		return (spe_return_error(88, consis));
	while (i < swap32_if(header->ncmds, rev))
	{
		spe_lc_manage(lc, rev, consis);
		actual_offset += swap32_if(lc->cmdsize, rev);
		if (actual_offset > consis->size_file || !(swap32_if(lc->cmdsize, rev)))
			return (spe_return_error(1, consis));
		lc = (void *)lc + swap32_if(lc->cmdsize, rev);
		i++;
	}
	return (consis->error);
}
