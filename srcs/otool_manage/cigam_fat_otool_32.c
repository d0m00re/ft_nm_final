/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cigam_fat_otool_32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:35:21 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/17 17:17:53 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "otool_manage.h"
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

/*
** return (0) if we read all architecture
** return (id + 1) : always > 0 : pour obtenir l emplacemeng
** de l archi on ait ret - 1
*/

unsigned int			find_emplacement_bin_32(char *ptr, int rev)
{
	struct fat_header	*fh;
	struct fat_arch		*fa;
	unsigned int		c;

	c = 0;
	fh = (struct fat_header *)ptr;
	fa = (void *)(fh) + sizeof(struct fat_header);
	while (c < swap32_if(fh->nfat_arch, rev))
	{
		if (swap32_if(fa->cputype, rev) == CPU_TYPE_X86_64)
			return (c + 1);
		fa = (void *)fa + sizeof(struct fat_arch);
		c++;
	}
	return (0);
}

void					fat_otool_32(char *ptr, char *name, int rev)
{
	unsigned int		c;
	struct fat_header	*fh;
	struct fat_arch		*fa;
	unsigned int		find;

	find = find_emplacement_bin_32(ptr, rev);
	c = 0;
	fh = (struct fat_header *)ptr;
	fa = (void *)(fh) + sizeof(struct fat_header);
	while (c < swap32_if(fh->nfat_arch, rev))
	{
		if (find == 0)
			otool((char *)(ptr + swap32_if(fa->offset, rev)),\
			name, swap32_if(fa->cputype, rev));
		else if (c == find - 1)
			otool((char *)(ptr + swap32_if(fa->offset, rev)), name, 0);
		fa = (void *)fa + sizeof(struct fat_arch);
		c++;
	}
}

unsigned int			find_emplacement_bin_64(char *ptr, int rev)
{
	struct fat_header	*fh;
	struct fat_arch_64	*fa;
	unsigned int		c;

	c = 0;
	fh = (struct fat_header *)ptr;
	fa = (void *)(fh) + sizeof(struct fat_header);
	while (c < swap32_if(fh->nfat_arch, rev))
	{
		if (swap32_if(fa->cputype, rev) == CPU_TYPE_X86_64)
			return (c + 1);
		fa = (void *)fa + sizeof(struct fat_arch_64);
		c++;
	}
	return (0);
}

void					fat_otool_64(char *ptr, char *name, int rev)
{
	unsigned int		c;
	struct fat_header	*fh;
	struct fat_arch_64	*fa;
	unsigned int		find;

	find = find_emplacement_bin_64(ptr, rev);
	c = 0;
	fh = (struct fat_header *)ptr;
	fa = (void *)(fh) + sizeof(struct fat_header);
	while (c < swap32_if(fh->nfat_arch, rev))
	{
		if (find == 0)
			otool((char *)(ptr + swap64_if(fa->offset, rev)),\
			name, swap32_if(fa->cputype, rev));
		else if (c == find - 1)
			otool((char *)(ptr + swap64_if(fa->offset, rev)), name, 0);
		fa = (void *)fa + sizeof(struct fat_arch);
		c++;
	}
}
