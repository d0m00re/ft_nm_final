/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:07:28 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 18:30:04 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <mach-o/fat.h>
#include "otool_manage.h"
#include "corrupted_checker.h"

static int				return_function(t_ctr_consis *consis)
{
	consis->error = 8;
	return (1);
}

int						checker_fat_32(char *ptr,\
int rev, t_ctr_consis *consis)
{
	unsigned int		c;
	struct fat_header	*fh;
	struct fat_arch		*fa;

	if (consis->size_file < sizeof(*fh))
		return (return_function(consis));
	c = 0;
	fh = (struct fat_header *)ptr;
	if (consis->size_file < sizeof(*fh) +\
	sizeof(*fa) * swap32_if(fh->nfat_arch, rev))
		return (return_function(consis));
	fa = (void *)(fh) + sizeof(struct fat_header);
	while (c < swap32_if(fh->nfat_arch, rev))
	{
		if (swap32_if(fa->align, rev) > 15 || swap32_if(fa->offset,\
		rev) > consis->size_file)
		{
			consis->error = 20;
			return (1);
		}
		fa = (void *)fa + sizeof(struct fat_arch);
		c++;
	}
	return (consis->error);
}

int						checker_fat_64(char *ptr,\
int rev, t_ctr_consis *consis)
{
	unsigned int		c;
	struct fat_header	*fh;
	struct fat_arch_64	*fa;

	if (consis->size_file < sizeof(*fh))
		return (return_function(consis));
	c = 0;
	fh = (struct fat_header *)ptr;
	if (consis->size_file < sizeof(*fh) +\
	sizeof(*fa) * swap32_if(fh->nfat_arch, rev))
		return (return_function(consis));
	fa = (void *)(fh) + sizeof(struct fat_header);
	while (c < swap32_if(fh->nfat_arch, rev))
	{
		if (swap32_if(fa->align, rev) > 15 ||\
		swap64_if(fa->offset, rev) > consis->size_file)
		{
			consis->error = 18;
			return (1);
		}
		fa = (void *)fa + sizeof(struct fat_arch_64);
		c++;
	}
	return (consis->error);
}
