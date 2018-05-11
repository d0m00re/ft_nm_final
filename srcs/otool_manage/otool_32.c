/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:31:28 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/31 15:31:30 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool_manage.h"
#include "utilities.h"
#include "nm_manage.h"
#include "corrupted_checker.h"
#include "generic_nm.h"

static void					fucking_display(char *ptr, uint64_t addr,\
uint32_t offset, uint64_t size)
{
	uint64_t				c;
	unsigned char			tmp;

	c = 0;
	while (&(ptr[c]) < get_testouille() && c < size)
	{
		if (c % 16 == 0 && c != 0)
			ft_putchar('\n');
		if (c % 16 == 0)
		{
			ft_putstr_same_char('0', 8 - nb_digit_buint64(addr + c));
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
}

static void					basic_init(uint64_t *a, uint64_t *b)
{
	*a = 0;
	*b = 0;
}



static void					fucking_display2(char *ptr, uint64_t addr,\
uint32_t offset, uint64_t size)
{
	uint64_t				c_tmp;
	uint64_t				c;
	unsigned char			tmp;

	basic_init(&c_tmp, &c);
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

static void					analyse_data(char *ptr,\
struct load_command *lc, int rev)
{
	unsigned int			i;
	struct segment_command	*sc;
	struct section			*s32;

	i = 0;
	sc = (void *)lc;
	s32 = (void *)sc + sizeof(*sc);
	while (i < swap32_if(sc->nsects, rev))
	{
		if (ft_strcmp(s32->sectname, "__text") == 0 &&\
		ft_strcmp(s32->segname, "__TEXT") == 0)
		{
			if (!rev)
				fucking_display(ptr, swap32_if(s32->addr, rev),\
				swap32_if(s32->offset, rev), swap32_if(s32->size, rev));
			else
				fucking_display2(ptr, swap32_if(s32->addr, rev),\
				swap32_if(s32->offset, rev), swap32_if(s32->size, rev));
		}
		s32 = (struct section *)((char *)s32 + sizeof(struct section));
		i++;
	}
}

void						otool_32(char *ptr, int rev, char *name_file, unsigned int is_dis_arch)
{
	unsigned int			i;
	struct mach_header		*header;
	struct load_command		*lc;

	if (main_checker(ptr, get_testouille() - ptr))
	{
		ft_error_file("./ft_otool", " : .", " : corruted file\n");
		return ;
	}
	i = 0;
	header = (struct mach_header *)ptr;
	lc = (void *)ptr + sizeof(*header);
	if (is_dis_arch)
		display_cpu(name_file, is_dis_arch);
	else
	{
		ft_putstr(name_file);
		ft_putstr(":\n");
	}
	ft_putstr("Contents of (__TEXT,__text) section\n");
	while (i < swap32_if(header->ncmds, rev))
	{
		if (swap32_if(lc->cmd, rev) == LC_SEGMENT)
			analyse_data(ptr, lc, rev);
		lc = (void *)lc + swap32_if(lc->cmdsize, rev);
		i++;
	}
	ft_putchar('\n');
}
