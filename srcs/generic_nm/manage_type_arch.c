/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_type_arch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:06:34 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 13:07:32 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic_nm.h"

t_elem_arch			*init_elem_arch(int size_max)
{
	t_elem_arch		*elem;
	int				c;

	c = 0;
	if (!(elem = malloc(sizeof(t_elem_arch))))
		return (0);
	elem->type = malloc(sizeof(int) * size_max);
	while (c < size_max)
	{
		elem->type[c] = 0;
		c++;
	}
	elem->actual_size = 0;
	elem->max_size = size_max;
	return (elem);
}

void				add_elem_arch(t_elem_arch *arch, int type)
{
	if (arch->actual_size == arch->max_size - 1)
	{
		ft_putstr("Error no moore space.\n");
		return ;
	}
	arch->type[arch->actual_size] = type;
	arch->actual_size += 1;
}

void				count_nb_diff_arch(t_elem_arch *arch)
{
	int				c;

	c = 1;
	arch->total_diff = 1;
	while (c < arch->actual_size)
	{
		if (arch->type[c] != arch->type[c - 1])
			arch->total_diff += 1;
		c++;
	}
}
