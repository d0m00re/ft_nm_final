/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:03:13 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 18:03:25 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corrupted_checker.h"
#include <stdlib.h>

int					main_checker(char *ptr, unsigned int size)
{
	int				tmp;
	t_ctr_consis	consis;

	consis.size_file = size;
	consis.error = 0;
	tmp = beatiful_checker(ptr, &consis);
	return (tmp);
}
