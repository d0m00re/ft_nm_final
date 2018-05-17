/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_nm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:18:54 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/17 17:31:32 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_NM_H
# define GENERIC_NM_H

# include "nm_manage.h"

# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "utilities.h"
# include <mach-o/fat.h>
# include <mach/machine.h>

typedef struct			s_elem_arch
{
	int					actual_size;
	int					max_size;
	int					total_diff;
	int					*type;
}						t_elem_arch;

typedef struct			s_universal_bin
{
	char				*ptr;
	char				*name;
	int					total;
	struct fat_header	*header;
	struct fat_arch		*arch_first;
	struct fat_arch_64	*arch_first_64;
	t_elem_arch			*arch_desc;
}						t_univ_bin;

void					nm_64(char *ptr);

void					nm_32(char *ptr);

void					nm_r_64(char *ptr);

void					nm_r_32(char *ptr);

void					nm_fat_32(char *ptr,\
char *name_file, int rev, unsigned int size);

void					nm_fat_64(char *ptr,\
char *name_file, int rev, unsigned int size);

void					display_cpu_type(char *name, int cpu_type);

/*
** arch universal binaries managing
*/

t_elem_arch				*init_elem_arch(int size_max);

void					add_elem_arch(t_elem_arch *arch, int type);

void					count_nb_diff_arch(t_elem_arch *arch);

void					nm(char *str, char *name_file, unsigned int size);

/*
** check we hav different archive to check into fat header
*/

/*
** for 64
*/

char					*check_if_own_archi_64(t_univ_bin *univ, int rev,\
uint32_t *size_sub, uint32_t size);

void					univ_bin_load_data_64(t_univ_bin *univ,\
		char *ptr, char *name, int rev);

/*
** for 32
*/

char					*check_if_own_archi_32(t_univ_bin *univ, int rev,\
uint32_t *size_sub, uint32_t size);

void					univ_bin_load_data_32(t_univ_bin *univ,\
		char *ptr, char *name, int rev);

#endif
