/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:02:50 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/09 19:15:39 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "nm_manage.h"

t_sect				*init_sect(int size_max)
{
	t_sect			*sect;

	if (!(sect = malloc(sizeof(t_sect))))
		return (0);
	sect->max_elem = size_max;
	if (!(sect->elem = malloc(sizeof(t_section_elem) * size_max)))
		return (0);
	sect->nb_elem = 0;
	return (sect);
}

void				free_sect_elem(t_sect *sect)
{
	if (sect && sect->elem)
		free(sect->elem);
}

int					realloc_sect(t_sect *sect)
{
	unsigned int	c;
	t_section_elem	*s;

	if (!(sect) || !(s = malloc(sizeof(t_section_elem) * (sect->max_elem * 2))))
		return (1);
	c = 0;
	while (c < sect->nb_elem)
	{
		s[c].sectname = sect->elem[c].sectname;
		s[c].segname = sect->elem[c].segname;
		c++;
	}
	if (sect && sect->elem)
		free(sect->elem);
	sect->elem = s;
	sect->max_elem *= 2;
	return (0);
}

void				add_elem_sect(t_sect *sect, char *sectname, char *segname)
{
	if (sect->nb_elem + 1 == sect->max_elem)
	{
		if (realloc_sect(sect))
			return ;
	}
	sect->elem[sect->nb_elem].sectname = sectname;
	sect->elem[sect->nb_elem].segname = segname;
	sect->nb_elem += 1;
}
