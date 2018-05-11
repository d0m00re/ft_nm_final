/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:00:25 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/28 22:00:37 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

unsigned int		ft_strlen_limit(const char *s, char *limit)
{
	unsigned int	count;

	count = 0;
	while (s[count] && &(s[count]) < limit)
		count++;
	return (count);
}
