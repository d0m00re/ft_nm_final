/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_32bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:11:47 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/15 13:46:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corrupted_checker.h"
#include "utilities.h"
#include "generic_nm.h"
#include <stdlib.h>

static int					check_symbol_validity(\
t_ctr_consis *consis, struct symtab_command *sym, int rev)
{
	unsigned int			i;

	if (swap32_if(sym->stroff, rev) > consis->size_file ||\
	swap32_if(sym->symoff, rev) > consis->size_file)
	{
		consis->error = 7;
		return (1);
	}
	i = 0;
	return (0);
}

#include <stdio.h>

static void					check_segment_validity(\
t_ctr_consis *consis, struct load_command *lc, int rev)
{
	unsigned int			i;
	struct segment_command	*sc;
	struct section			*s32;

	i = 0;
	sc = (void *)lc;
	if (swap32_if(sc->fileoff, rev) > consis->size_file)//swap32_if(sc->fileoff, rev) + sizeof(*sc) + sizeof(*s32) * swap32_if(sc->nsects, rev) >= consis->size_file)
	{
		consis->error = 5;
	}
}

static int					check_header_validity(t_ctr_consis *consis,\
struct mach_header *header, struct load_command *lc, int rev)
{
	if (sizeof(*header) > consis->size_file)
	{
		consis->error = 2;
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
		consis->error = 4;
		return (1);
	}
	return (0);
}

static void					spe_lc_manage(struct load_command *lc,\
int rev, t_ctr_consis *consis)
{
	if (swap32_if(lc->cmd, rev) == LC_SYMTAB)
		check_symbol_validity(consis,\
		(struct symtab_command *)lc, rev);
	else if (swap32_if(lc->cmd, rev) == LC_SEGMENT)
		check_segment_validity(consis, lc, rev);
}

int							check_32bits(char *ptr,\
int rev, t_ctr_consis *consis)
{
	uint64_t				actual_offset;
	unsigned int			i;
	struct mach_header		*header;
	struct load_command		*lc;

	i = 0;
	lc = 0;
	header = (struct mach_header *)ptr;
	check_header_validity(consis, header, lc, rev);
	actual_offset = sizeof(*header);
	lc = (void *)ptr + sizeof(*header);
	if (consis->size_file < swap32_if(lc->cmdsize, rev))
		return (spe_return_error(88, consis));
	while (i < swap32_if(header->ncmds, rev))
	{
		spe_lc_manage(lc, rev, consis);
		actual_offset += swap32_if(lc->cmdsize, rev);
		if (actual_offset > consis->size_file)
			return (spe_return_error(1, consis));
		lc = (void *)lc + swap32_if(lc->cmdsize, rev);
		i++;
	}
	return (consis->error);
}
