/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:45:15 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/14 21:09:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "nm_manage.h"
#define BIBITCH "bad string index"

static void					store_nlist_r_32(t_nm *nm,\
uint32_t symoff, uint32_t stroff, uint32_t strsize)
{
	unsigned int			i;
	char					*string_table;
	struct nlist			*array;

	if (!nm || !(nm->nb_elem) || !(nm->sort_elem))
		return ;
	i = 0;
	array = (void *)nm->ptr_file + swap32(symoff);
	string_table = nm->ptr_file + swap32(stroff);
	while (i < nm->nb_elem)
	{
		nm->elem[i].c = ' ';
		nm->elem[i].n_type = array[i].n_type;
		nm->elem[i].n_sect = array[i].n_sect;
		nm->elem[i].n_value = swap32(array[i].n_value);
		nm->elem[i].name = string_table + swap32(array[i].n_un.n_strx);
		if (swap32(array[i].n_un.n_strx) <= swap32(strsize))
			nm->elem[i].name = string_table + swap32(array[i].n_un.n_strx);
		else
		{
			nm->elem[i].name = BIBITCH;
			nm->elem[i].c = '?';
		}
		i++;
	}
}

static void					store_data_segment_section_r_32(t_nm *nm,\
		struct load_command *lc)
{
	unsigned int			i;
	struct segment_command	*sc;
	struct section			*s32;

	i = 0;
	sc = (void *)lc;
	s32 = (void *)sc + sizeof(*sc);
	while (i < swap32(sc->nsects))
	{
		add_elem_sect(nm->sect, s32->sectname, s32->segname);
		s32 = (struct section *)((char *)s32 + sizeof(struct section));
		i++;
	}
}

void						handle_r_32(t_nm *nm)
{
	unsigned int			i;
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	i = 0;
	header = (struct mach_header *)nm->ptr_file;
	lc = (void *)nm->ptr_file + sizeof(*header);
	while (nm->nb_elem == 0 || i < nm->nb_elem)
	{
		if (swap32(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			nm->nb_elem = swap32(sym->nsyms);
			nm->elem = malloc(sizeof(t_nm_elem) * nm->nb_elem);
			nm->sort_elem = malloc(sizeof(unsigned int) * nm->nb_elem);
			store_nlist_r_32(nm, sym->symoff, sym->stroff, sym->strsize);
			break ;
		}
		else if (swap32(lc->cmd) == LC_SEGMENT)
			store_data_segment_section_r_32(nm, lc);
		lc = (void *)lc + swap32(lc->cmdsize);
		i++;
	}
}
