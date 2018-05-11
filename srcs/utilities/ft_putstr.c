/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:09:10 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:09:16 by alhelson         ###   ########.fr       */
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
