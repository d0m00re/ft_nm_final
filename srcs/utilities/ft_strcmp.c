/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:59:59 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/28 22:00:10 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	count;

	count = 0;
	while (s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}

int		ft_strncmp(const char *s1, const char *s2, int size_max)
{
	int count;

	count = 0;
	while (count < size_max && s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}

int		ft_strcmp_limit(const char *s1, const char *s2)
{
	int	count;

	count = 0;
	while (s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
