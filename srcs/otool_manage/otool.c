/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:37:24 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/09 19:51:52 by alhelson         ###   ########.fr       */
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
#include "otool_manage.h"
#include <mach-o/fat.h>

void				otool(char *ptr, char *name_file, unsigned int is_dis_arch)
{
	unsigned int	magic;

	magic = *(unsigned int *)ptr;
	if (magic == MH_MAGIC_64)
		otool_64(ptr, 0, name_file, is_dis_arch);
	else if (magic == MH_MAGIC)
		otool_32(ptr, 0, name_file, is_dis_arch);
	else if (magic == MH_CIGAM_64)
		otool_64(ptr, 1, name_file, is_dis_arch);
	else if (magic == MH_CIGAM)
		otool_32(ptr, 1, name_file, is_dis_arch);
	else if (magic == FAT_CIGAM)
		fat_otool_32(ptr, name_file, 1);
	else if (magic == FAT_MAGIC)
		fat_otool_32(ptr, name_file, 0);
	else if (magic == FAT_CIGAM_64)
		fat_otool_64(ptr, name_file, 1);
	else if (magic == FAT_MAGIC_64)
		fat_otool_64(ptr, name_file, 0);
	else
	{
		ft_putstr(name_file);
		ft_putstr(" The file was not recognized as a valid object file\n");
	}
}
