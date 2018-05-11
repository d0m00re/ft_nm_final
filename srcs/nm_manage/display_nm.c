/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:51:19 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 18:51:30 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_manage.h"

void				display_nm(t_nm *nm, int num)
{
	unsigned int	i;

	i = 0;
	if (!nm)
		return ;
	while (i < nm->nb_elem)
	{
		if (nm->elem[nm->sort_elem[i]].stab == 0)
		{
			if (num == 32)
				display_elem_32(&(nm->elem[nm->sort_elem[i]]));
			else if (num == 64)
				display_elem_64(&(nm->elem[nm->sort_elem[i]]));
		}
		i++;
	}
}
