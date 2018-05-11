/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:06:11 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:06:16 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_ui(unsigned int nb, unsigned int base)
{
	if (nb > base - 1)
	{
		ft_putnbr_base_ui(nb / base, base);
		ft_putnbr_base_ui(nb % base, base);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
		nb = 0;
	}
}

void	ft_putnbr_base_ui64(uint64_t nb, unsigned int base)
{
	if (nb > base - 1)
	{
		ft_putnbr_base_ui64(nb / base, base);
		ft_putnbr_base_ui64(nb % base, base);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
		nb = 0;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > 9)
	{
		ft_putnbr(nbb / 10);
		ft_putnbr(nbb % 10);
	}
	else
	{
		ft_putchar(nbb + '0');
		nbb = 0;
	}
}
