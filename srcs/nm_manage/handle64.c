/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:45:12 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:46:41 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "nm_manage.h"
#define BIBITCH "bad string index"

void							store_nlist_64(t_nm *nm,\
		int symoff, int stroff, int strsize)
{
	unsigned int				i;
	char						*string_table;
	struct nlist_64				*array;

	if (!nm || !(nm->elem) || !(nm->sort_elem))
		return ;
	i = 0;
	array = (void *)nm->ptr_file + symoff;
	string_table = nm->ptr_file + stroff;
	while (i < nm->nb_elem)
	{
		nm->elem[i].c = ' ';
		nm->elem[i].n_type = array[i].n_type;
		nm->elem[i].n_sect = array[i].n_sect;
		nm->elem[i].n_value = array[i].n_value;
		if (array[i].n_un.n_strx <= (unsigned int)strsize)
			nm->elem[i].name = string_table + array[i].n_un.n_strx;
		else
		{
			nm->elem[i].name = BIBITCH;
			nm->elem[i].c = '?';
		}
		i++;
	}
}

void							store_data_segment_section_64(t_nm *nm,\
		struct load_command *lc)
{
	unsigned int				i;
	struct segment_command_64	*sc;
	struct section_64			*s64;

	i = 0;
	sc = (void *)lc;
	s64 = (void *)sc + sizeof(*sc);
	while (i < sc->nsects)
	{
		add_elem_sect(nm->sect, s64->sectname, s64->segname);
		s64 = (struct section_64 *)((char *)s64 + sizeof(struct section_64));
		i++;
	}
}

void							handle_64(t_nm *nm)
{
	unsigned int				i;
	struct mach_header_64		*header;
	struct load_command			*lc;
	struct symtab_command		*sym;

	i = 0;
	header = (struct mach_header_64 *)nm->ptr_file;
	lc = (void *)nm->ptr_file + sizeof(*header);
	while (nm->nb_elem == 0 || i < nm->nb_elem)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			nm->nb_elem = sym->nsyms;
			nm->elem = malloc(sizeof(t_nm_elem) * nm->nb_elem);
			nm->sort_elem = malloc(sizeof(unsigned int) * nm->nb_elem);
			store_nlist_64(nm, sym->symoff, sym->stroff, sym->strsize);
			break ;
		}
		else if (lc->cmd == LC_SEGMENT_64)
			store_data_segment_section_64(nm, lc);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}
