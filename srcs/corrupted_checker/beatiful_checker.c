/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beatiful_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:03:47 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/09 19:52:45 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corrupted_checker.h"
#include "utilities.h"
#include "generic_nm.h"

int						beatiful_checker(char *ptr, t_ctr_consis *consis)
{
	unsigned int		magic;
	int					tmp;

	tmp = 0;
	magic = *(unsigned int *)ptr;
	if (magic == MH_MAGIC_64)
		tmp = check_64bits(ptr, 0, consis);
	else if (magic == MH_MAGIC)
		tmp = check_32bits(ptr, 0, consis);
	else if (magic == MH_CIGAM_64)
		tmp = check_64bits(ptr, 1, consis);
	else if (magic == MH_CIGAM)
		tmp = check_32bits(ptr, 1, consis);
	else if (magic == FAT_CIGAM)
		tmp = checker_fat_32(ptr, 1, consis);
	else if (magic == FAT_MAGIC)
		tmp = checker_fat_32(ptr, 0, consis);
	else if (magic == FAT_CIGAM_64)
		tmp = checker_fat_64(ptr, 1, consis);
	else if (magic == FAT_MAGIC_64)
		tmp = checker_fat_64(ptr, 0, consis);
	return (tmp);
}
