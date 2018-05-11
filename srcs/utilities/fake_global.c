/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:29:45 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/14 20:30:17 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*g_test = 0;

void		set_testouille(char *mabite)
{
	if (!g_test)
		g_test = mabite;
}

char		*get_testouille(void)
{
	return (g_test);
}

void		reset_testouille(void)
{
	g_test = 0;
}
