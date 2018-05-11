/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:35:39 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/15 15:51:36 by alhelson         ###   ########.fr       */
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
#include "corrupted_checker.h"
#include <unistd.h>

static int		launch_otool(char *name)
{
	int			fd;
	char		*ptr;
	struct stat	buf;

	if ((fd = open(name, O_RDONLY)) < 0)
		return (ft_error_file("./ft_otool ", name, ERR_EX));
	if (fstat(fd, &buf) < 0)
		return (ft_error_file("./ft_otool ", name, "error fstat"));
	if (buf.st_size == 0)
		return (ft_error_file("./ft_otool ", name, ERR_OBJ));
	if ((ptr = mmap(0, buf.st_size, PROT_READ,\
	MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ft_error_file("./ft_otool ", name, " : error mmap.\n"));
	set_testouille(&(ptr[buf.st_size - 1]));
	if (main_checker(ptr, buf.st_size))
		return (ft_error_file("./ft_otool ",\
	name, " : error corrupted file.\n"));
	else
		otool(ptr, name, 0);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	close(fd);
	return (0);
}

int				main(int ac, char **av)
{
	int			ret;
	int			c;

	ret = 0;
	if (ac < 2)
	{
		ft_putstr("Usage: ./ft_nm <object file>\n");
		return (0);
	}
	c = 1;
	while (c < ac)
	{
		ret |= launch_otool(av[c]);
		reset_testouille();
		if (ret)
			return (1);
		c++;
	}
	return (ret);
}
