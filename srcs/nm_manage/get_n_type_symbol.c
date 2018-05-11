/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_type_symbol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:11:37 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/14 21:26:56 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "nm_manage.h"

void			find_ntype(t_nm_elem *elem)
{
	if (!elem)
		return ;
	elem->stab = 0;
	elem->pext = 0;
	elem->type = 0;
	elem->ext = 0;
	if (elem->n_type & N_STAB)
		elem->stab = 1;
	if (elem->n_type & N_PEXT)
		elem->pext = 1;
	if (elem->n_type & N_TYPE)
		elem->type = 1;
	if (elem->n_type & N_EXT)
		elem->ext = 1;
}

static void		manage_data_section(t_nm *main, t_nm_elem *elem)
{
	if (elem->n_sect > 0 && elem->n_sect <= main->sect->nb_elem)
	{
		if (ft_strcmp_limit(main->sect->elem[elem->n_sect - 1].segname,\
		"__TEXT") == 0 &&\
		ft_strcmp_limit(main->sect->elem[elem->n_sect - 1].sectname,\
		"__text") == 0)
			elem->c = 't';
		else if (ft_strcmp_limit(main->sect->elem[elem->n_sect - 1].segname,\
		"__DATA") == 0)
		{
			if (ft_strcmp_limit(main->sect->elem[elem->n_sect - 1].sectname,\
			"__bss") == 0)
				elem->c = 'b';
			else if (ft_strcmp_limit(main->sect->elem[elem->n_sect -\
			1].sectname, "__data") == 0)
				elem->c = 'd';
			else
				elem->c = 's';
		}
		else
			elem->c = 's';
	}
}

static void		manage_undf(t_nm_elem *elem)
{
	elem->c = 'u';
	if ((elem->n_value) != 0)
		elem->c = 'c';
}

void			get_n_type_symbol(t_nm *main, unsigned int id)
{
	uint64_t	res;
	t_nm_elem	*elem;

	elem = &(main->elem[id]);
	res = elem->n_type & N_TYPE;
	find_ntype(elem);
	if (res == N_UNDF)
		manage_undf(elem);
	else if (res == N_PBUD)
		elem->c = 'u';
	else if (res == N_ABS)
		elem->c = 'a';
	else if (res == N_SECT)
		manage_data_section(main, elem);
	else if (res == N_INDR)
		elem->c = 'i';
	else
		elem->c = '?';
	if (elem->c >= 'a' && elem->c <= 'z' && elem->ext)
		elem->c = elem->c - 'a' + 'A';
	if (((ft_strcmp(elem->name, "bad string index") == 0) ||\
	((ft_strcmp(elem->name, "") == 0))) && elem->c <= 'z' && elem->c >= 'a')
		elem->c = '?';
}
