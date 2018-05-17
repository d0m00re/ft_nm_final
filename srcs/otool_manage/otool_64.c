/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:33:37 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 19:14:28 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool_manage.h"
#include "utilities.h"
#include "nm_manage.h"
#include "corrupted_checker.h"

static void						fucking_display(char *ptr, uint64_t addr,\
		uint32_t offset, uint64_t size)
{
	uint64_t					c;
	unsigned char				tmp;

	c = 0;
	while (&(ptr[c]) < get_testouille() && c < size)
	{
		if (c % 16 == 0 && c != 0)
			ft_putchar('\n');
		if (c % 16 == 0)
		{
			ft_putstr_same_char('0', 16 - nb_digit_buint64(addr + c));
			if (addr + c)
				ft_putnbr_base_ui64(addr + c, 16);
			ft_putchar('\t');
		}
		tmp = *(char *)(ptr + offset + c);
		if (tmp < 16)
			ft_putchar('0');
		ft_putnbr_base_ui((unsigned int)tmp, 16);
		ft_putchar(' ');
		c++;
	}
	ft_putchar('\n');
}

static void						basic_init(uint64_t *a, uint64_t *b)
{
	*a = 0;
	*b = 0;
}

static void						fucking_display2(char *ptr, uint64_t addr,\
uint32_t offset, uint64_t size)
{
	uint64_t					c_tmp;
	uint64_t					c;
	unsigned char				tmp;

	basic_init(&c, &c_tmp);
	while (&(ptr[c]) < get_testouille() && c < size)
	{
		if (c % 16 == 0 && c != 0)
			ft_putchar('\n');
		if (c % 16 == 0)
		{
			c_tmp = 1;
			ft_putstr_same_char('0', 8 - nb_digit_buint64(addr + c));
			ft_putnbr_base_ui64(addr + c, 16);
			ft_putchar('\t');
		}
		tmp = *(char *)(ptr + offset + c);
		if (tmp < 16)
			ft_putchar('0');
		ft_putnbr_base_ui((unsigned int)tmp, 16);
		if (c_tmp && (c_tmp % 4 == 0))
			ft_putchar(' ');
		c++;
		c_tmp++;
	}
}

static void						analyse_data(char *ptr,\
struct load_command *lc, int rev)
{
	unsigned int				i;
	struct segment_command_64	*sc;
	struct section_64			*s64;

	i = 0;
	sc = (void *)lc;
	s64 = (void *)sc + sizeof(*sc);
	while (i < swap32_if(sc->nsects, rev))
	{
		if (ft_strcmp(s64->sectname, "__text") == 0 &&\
		ft_strcmp(s64->segname, "__TEXT") == 0)
		{
			if (!rev)
				fucking_display(ptr, swap64_if(s64->addr, rev),\
swap32_if(s64->offset, rev), swap64_if(s64->size, rev));
			else
				fucking_display2(ptr, swap64_if(s64->addr, rev),\
swap32_if(s64->offset, rev), swap64_if(s64->size, rev));
		}
		s64 = (struct section_64 *)((char *)s64 + sizeof(struct section_64));
		i++;
	}
}

void							otool_64(char *ptr, int rev,\
char *name_file, unsigned int is_dis_arch)
{
	unsigned int				i;
	struct mach_header_64		*header;
	struct load_command			*lc;

	is_dis_arch = 0;
	if (main_checker(ptr, get_testouille() - ptr))
	{
		ft_error_file("./ft_otool", " : .", " : corruted file\n");
		return ;
	}
	i = 0;
	header = (struct mach_header_64 *)ptr;
	lc = (void *)ptr + sizeof(*header);
	ft_putstr(name_file);
	ft_putstr(":\nContents of (__TEXT,__text) section\n");
	while (i < swap32_if(header->ncmds, rev))
	{
		if (lc->cmd == LC_SEGMENT_64)
			analyse_data(ptr, lc, rev);
		lc = (void *)lc + swap32_if(lc->cmdsize, rev);
		i++;
	}
}
