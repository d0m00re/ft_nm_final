/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:58:55 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/09 19:45:35 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic_nm.h"
#include "corrupted_checker.h"

void				nm_32(char *ptr)
{
	unsigned int	i;
	t_nm			nm;

	i = 0;
	nm.ptr_file = ptr;
	if (main_checker(ptr, get_testouille() - ptr))
	{
		ft_error_file("./ft_nm", " : .", " : corruted file\n");
		return ;
	}
	nm.magic = *(int *)ptr;
	nm.nb_elem = 0;
	nm.elem = 0;
	nm.sect = init_sect(100);
	handle_32(&nm);
	while (i < nm.nb_elem)
	{
		get_n_type_symbol(&nm, i);
		i++;
	}
	sort_tab_interface(&nm);
	sort_same_str(&nm);
	display_nm(&nm, 32);
	nm_free_in(&nm);
}
