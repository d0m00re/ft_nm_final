/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cpu_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:05:47 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 13:05:55 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic_nm.h"

void	display_cpu_type(char *name, int cpu_type)
{
	ft_putstr("\n");
	ft_putstr(name);
	if (cpu_type == CPU_TYPE_POWERPC)
		ft_putstr(" (for architecture ppc):\n");
	else if (cpu_type == CPU_TYPE_X86)
		ft_putstr(" (for architecture i386):\n");
	else if (cpu_type == CPU_TYPE_X86_64)
		ft_putstr(" (for architecture X86_64):\n");
	else
	{
		ft_putstr(" (unkown architecture : ");
		ft_putnbr(cpu_type);
		ft_putstr(")\n");
	}
}
