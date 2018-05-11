/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_manage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:20:59 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/09 19:17:46 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_MANAGE_H
# define NM_MANAGE_H

# include <stdlib.h>

# include <mach-o/loader.h>
# include <mach-o/nlist.h>

/*
** manage section
*/

typedef struct		s_section_elem
{
	char			*sectname;
	char			*segname;
}					t_section_elem;

typedef struct		s_sect
{
	unsigned int	nb_elem;
	unsigned int	max_elem;
	t_section_elem	*elem;
}					t_sect;

t_sect				*init_sect(int size_max);

void				free_sect_elem(t_sect *sect);

int					realloc_sect(t_sect *sect);

void				add_elem_sect(t_sect *sect,\
		char *sectname, char *segname);

/*
** GLOBAL NM MANAGING
*/

typedef struct		s_nm_elem
{
	char			*name;
	char			*end_delete;
	void			*addr;
	char			c;
	uint8_t			n_type;
	uint8_t			n_sect;
	uint64_t		n_value;
	int				stab;
	int				pext;
	int				type;
	int				ext;
}					t_nm_elem;

typedef struct		s_nm
{
	char			*ptr_file;
	int				magic;
	unsigned int	nb_elem;
	t_nm_elem		*elem;
	unsigned int	*sort_elem;
	t_sect			*sect;
}					t_nm;

void				nm_free_in(t_nm *nm);

t_nm_elem			*make_nm_elem(char *name, void *addr, char c);

void				display_elem_64(t_nm_elem *elem);
void				display_elem_32(t_nm_elem *elem);

void				sort_tab_interface(t_nm *nm);

void				sort_tab_interface_addr_bt(t_nm *nm,\
		unsigned int begin, unsigned int end);
void				sort_same_str(t_nm *nm);

/*
** manage ntype and char symbol
*/

void				find_ntype(t_nm_elem *elem);

void				get_n_type_symbol(t_nm *main, unsigned int id);

/*
** manage handle 64 - binary 64
*/

void				store_nlist_64(t_nm *nm, int symoff,\
int stroff, int strsize);

void				store_data_segment_section_64(t_nm *nm,\
struct load_command *lc);

void				handle_64(t_nm *nm);

void				store_nlist_32(t_nm *nm, int symoff,\
int stroff, int strsize);

void				store_data_segment_section_32(t_nm *nm,\
struct load_command *lc);

void				handle_32(t_nm *nm);

/*
** cigam
*/

void				handle_r_32(t_nm *nm);

void				store_nlist_r_64(t_nm *nm, int symoff,\
int stroff, int strsize);
void				store_data_segment_section_r_64(t_nm *nm,\
struct load_command *lc);
void				handle_r_64(t_nm *nm);

/*
** displaying
*/

void				display_nm(t_nm *nm, int num);

void				debug_nm(t_nm *nm);

#endif
