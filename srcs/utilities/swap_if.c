/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:06:57 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:07:18 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "utilities.h"

uint64_t			swap64_if(uint64_t x, int s)
{
	if (s)
		return (swap64(x));
	return (x);
}

unsigned int		swap32_if(unsigned int x, int s)
{
	if (s)
		return (swap32(x));
	return (x);
}

short				swap16_if(short x, int s)
{
	if (s)
		return (swap16(x));
	return (x);
}

uint64_t			swap_if_gen(uint64_t value, unsigned int type_swap, int s)
{
	if (s)
		return (swap_gen(value, type_swap));
	return (value);
}
