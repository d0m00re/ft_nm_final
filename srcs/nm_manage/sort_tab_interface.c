/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab_interface.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:40:53 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:41:25 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_manage.h"
#include "utilities.h"

void				sort_tab_interface(t_nm *nm)
{
	unsigned int	c;
	unsigned int	tmp;

	c = 0;
	while (c < nm->nb_elem)
	{
		nm->sort_elem[c] = c;
		c++;
	}
	c = 0;
	while (c < nm->nb_elem - 1)
	{
		if (ft_strcmp(nm->elem[nm->sort_elem[c]].name,\
		nm->elem[nm->sort_elem[c + 1]].name) > 0)
		{
			tmp = nm->sort_elem[c];
			nm->sort_elem[c] = nm->sort_elem[c + 1];
			nm->sort_elem[c + 1] = tmp;
			c = 0;
		}
		else
			c++;
	}
}

void				sort_tab_interface_addr_bt(t_nm *nm,\
unsigned int begin, unsigned int end)
{
	unsigned int	c;
	unsigned int	tmp;

	c = begin;
	while (c < end)
	{
		if (nm->elem[nm->sort_elem[c]].n_value >\
		nm->elem[nm->sort_elem[c + 1]].n_value)
		{
			tmp = nm->sort_elem[c];
			nm->sort_elem[c] = nm->sort_elem[c + 1];
			nm->sort_elem[c + 1] = tmp;
			c = begin;
		}
		else
			c++;
	}
}

void				sort_same_str(t_nm *nm)
{
	char			*tmp;
	unsigned int	c;
	unsigned int	c2;

	tmp = 0;
	c = 0;
	c2 = 0;
	while (c < nm->nb_elem - 1)
	{
		tmp = nm->elem[nm->sort_elem[c]].name;
		c2 = c + 1;
		while (c2 < nm->nb_elem && ft_strcmp(nm->elem[nm->sort_elem[c]].name,\
nm->elem[nm->sort_elem[c2]].name) == 0)
		{
			c2++;
		}
		if (c < c2 - 1)
		{
			sort_tab_interface_addr_bt(nm, c, c2 - 1);
			c = c2;
		}
		c++;
	}
}
