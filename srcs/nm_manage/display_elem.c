/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:38:46 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 18:38:53 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_manage.h"
#include "utilities.h"

void	display_elem_64(t_nm_elem *elem)
{
	if (elem->n_value || elem->c == 't' || elem->c == 'T' ||\
	elem->c == '?' || elem->c == 'b')
	{
		if (elem->n_value)
		{
			ft_putstr_same_char('0', 16 - nb_digit_buint64(elem->n_value));
			ft_putnbr_base_ui64(elem->n_value, 16);
		}
		else
			ft_putstr_same_char('0', 16 - nb_digit_buint64(elem->n_value));
		ft_putchar(' ');
	}
	else
		ft_putstr("                 ");
	ft_putchar(elem->c);
	ft_putchar(' ');
	ft_putstr_limit(elem->name, get_testouille());
	ft_putchar('\n');
}

void	display_elem_32(t_nm_elem *elem)
{
	if (elem->n_value || elem->c == 't' || elem->c == 'T' || elem->c == '?')
	{
		if (elem->n_value)
			ft_putstr_same_char('0', 8 - nb_digit_buint64(elem->n_value));
		else
			ft_putstr_same_char('0', 8);
		ft_putnbr_base_ui64(elem->n_value, 16);
		ft_putchar(' ');
	}
	else
		ft_putstr("         ");
	ft_putchar(elem->c);
	ft_putchar(' ');
	ft_putstr_limit(elem->name, get_testouille());
	ft_putchar('\n');
}
