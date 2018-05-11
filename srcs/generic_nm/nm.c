/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:04:44 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/09 19:48:48 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_manage.h"
#include <sys/mman.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "utilities.h"
#include "generic_nm.h"
#include <mach-o/fat.h>

void				nm(char *ptr, char *name_file, unsigned int size)
{
	unsigned int	magic;

	magic = *(unsigned int *)ptr;
	set_testouille(&(ptr[size - 1]));
	if (magic == MH_MAGIC_64)
		nm_64(ptr);
	else if (magic == MH_MAGIC)
		nm_32(ptr);
	else if (magic == MH_CIGAM_64)
		nm_r_64(ptr);
	else if (magic == MH_CIGAM)
	{
		nm_r_32(ptr);
	}
	else if (magic == FAT_MAGIC)
	{
		while (1)
			ft_putstr("john32");
		nm_fat_32(ptr, name_file, 0, size);
	}
	else if (magic == FAT_CIGAM)
	{
		//while (1){ft_putstr("Salope");}
		nm_fat_32(ptr, name_file, 1, size);
	}
	else if (magic == FAT_MAGIC_64)
	{
		while(1)
			ft_putstr("coucou64");
		nm_fat_64(ptr, name_file, 0, size);
	}
	else if (magic == FAT_CIGAM_64)
	{
		while(1)
                        ft_putstr("coucou46");
		nm_fat_64(ptr, name_file, 1, size);
	}
	else
	{
		ft_putstr(name_file);
		ft_putstr(" The file was not recognized as a valid object file\n");
	}
}
