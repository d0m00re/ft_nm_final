/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:58:58 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:08:59 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint64_t			swap64(uint64_t r)
{
	uint64_t		res;

	res = (r << 56) & 0xff00000000000000;
	res += (r << 36) & 0x00ff000000000000;
	res += (r << 24) & 0x0000ff0000000000;
	res += (r << 8) & 0x000000ff00000000;
	res += (r >> 8) & 0x00000000ff000000;
	res += (r >> 24) & 0x0000000000ff0000;
	res += (r >> 36) & 0x000000000000ff00;
	res += (r >> 56) & 0x00000000000000ff;
	return (res);
}

unsigned int		swap32(unsigned int x)
{
	unsigned int	n;

	n = (x << 24) & 0xff000000;
	n += (x << 8) & 0x00ff0000;
	n += (x >> 24) & 0x000000ff;
	n += (x >> 8) & 0x0000ff00;
	return (n);
}

short				swap16(short x)
{
	return ((x << 8 & 0xff00) | (x >> 8 & 0x00ff));
}

uint64_t			swap_gen(uint64_t value, unsigned int type_swap)
{
	if (type_swap == 64)
		return (swap64(value));
	else if (type_swap == 32)
		return (swap32(value));
	else if (type_swap == 16)
		return (swap16(value));
	return (value);
}
