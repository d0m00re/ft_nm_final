/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat_cigam_32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:02:24 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/17 17:12:40 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic_nm.h"
#include "corrupted_checker.h"

static void				generate_arch(t_univ_bin *univ, int rev)
{
	int					c;
	struct fat_arch		*fa;
	unsigned int		magic;
	char				*begining;

	c = 0;
	univ->arch_desc = init_elem_arch(100);
	fa = univ->arch_first;
	while (c < univ->total)
	{
		begining = univ->ptr + swap32_if(fa->offset, rev);
		magic = *(unsigned int *)(begining);
		add_elem_arch(univ->arch_desc, magic);
		c++;
		fa = (void *)fa + sizeof(struct fat_arch);
	}
	count_nb_diff_arch(univ->arch_desc);
}

char					*check_if_own_archi_32(t_univ_bin *univ, int rev,\
uint32_t *size_sub, uint32_t size)
{
	int					c;
	struct fat_arch		*fa;
	unsigned int		magic;
	char				*begining;

	c = 0;
	fa = univ->arch_first;
	while (c < univ->total)
	{
		begining = univ->ptr + swap32_if(fa->offset, rev);
		magic = *(unsigned int *)(begining);
		if (magic == MH_MAGIC_64)
		{
			*size_sub = size - (size - swap32_if(fa->offset, rev));
			return (begining);
		}
		c++;
		fa = (void *)fa + sizeof(struct fat_arch);
	}
	return (0);
}

static void				manage_all_architecture(t_univ_bin univ,\
		char *ptr, int rev, unsigned int size)
{
	int					c;
	struct fat_arch		*fa;

	c = 0;
	fa = univ.arch_first;
	while (c < univ.total)
	{
		if (c == 0 || univ.arch_desc->type[c] != univ.arch_desc->type[c - 1])
		{
			if (univ.arch_desc->total_diff > 1)
				display_cpu_type(univ.name, swap32_if(fa->cputype, rev));
			nm((char *)(ptr + swap32_if(fa->offset, rev)), univ.name, size);
			fa = (void *)fa + sizeof(struct fat_arch);
		}
		c++;
	}
}

void					univ_bin_load_data_32(t_univ_bin *univ,\
char *ptr, char *name, int rev)
{
	univ->ptr = ptr;
	univ->name = name;
	univ->header = (struct fat_header *)ptr;
	univ->total = swap32_if(univ->header->nfat_arch, rev);
	univ->arch_first = (void *)(univ->header) + sizeof(struct fat_header);
	generate_arch(univ, rev);
}

void					nm_fat_32(char *ptr, char *name,\
int rev, unsigned int size)
{
	t_univ_bin			univ;
	char				*tmp;
	uint32_t			size_sub;

	univ_bin_load_data_32(&univ, ptr, name, rev);
	if ((tmp = check_if_own_archi_32(&univ, rev, &size_sub, size)))
		nm(tmp, name, size_sub);
	else
		manage_all_architecture(univ, ptr, rev, size);
	free(univ.arch_desc->type);
	free(univ.arch_desc);
}
