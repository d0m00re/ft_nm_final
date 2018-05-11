/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:04:19 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:04:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "utilities.h"

unsigned int		nb_digit_buint64(uint64_t value)
{
	unsigned int	nb;

	nb = 0;
	while (value)
	{
		value /= 16;
		nb++;
	}
	return (nb);
}

void				ft_putstr_same_char(char ch, unsigned int rep)
{
	unsigned int	c;

	c = 0;
	while (c < rep)
	{
		ft_putchar(ch);
		c++;
	}
}
