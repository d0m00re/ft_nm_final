/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:09:10 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/17 17:29:32 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utilities.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putstr_limit(char *str, char *end)
{
	unsigned int size;

	size = ft_strlen_limit(str, end);
	write(1, str, size);
}

void	ft_putstr2(char *str, char *str2)
{
	ft_putstr(str);
	ft_putstr(str2);
}
