/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nm_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:43:43 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 18:43:52 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_manage.h"

t_nm_elem		*make_nm_elem(char *name, void *addr, char c)
{
	t_nm_elem	*elem;

	if (!(elem = malloc(sizeof(t_nm_elem))))
		return (0);
	elem->name = name;
	elem->addr = addr;
	elem->c = c;
	return (elem);
}
