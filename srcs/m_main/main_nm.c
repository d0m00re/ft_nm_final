/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:50:20 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/17 19:59:18 by alhelson         ###   ########.fr       */
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
#include "corrupted_checker.h"
#include <unistd.h>

static int		launch_nm(char *name)
{
	int			fd;
	int			ret;
	char		*ptr;
	struct stat	buf;

	ret = 0;
	if ((fd = open(name, O_RDONLY)) < 0)
		return (ft_error_file("./ft_nm ", name, ERR_EX));
	if (fstat(fd, &buf) < 0)
		return (ft_error_file("./ft_nm ", name, "error fstat"));
	if (buf.st_size == 0)
		return (ft_error_file("./ft_nm ", name, ERR_OBJ));
	if ((ptr = mmap(0, buf.st_size, PROT_READ,\
	MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ft_error_file("./ft_nm ", name, " : error mmap.\n"));
	if (main_checker(ptr, buf.st_size))
		return (ft_error_file("./ft_nm ",\
		name, " : error corrupted file.\n"));
	else
		nm(ptr, name, buf.st_size);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	close(fd);
	return (ret);
}

int				main(int ac, char **av)
{
	int			c;
	int			ret;

	ret = 0;
	if (ac < 2)
		return (launch_nm("./a.out"));
	c = 1;
	while (c < ac)
	{
		if (ac >= 3)
		{
			ft_putstr("\n");
			ft_putstr(av[c]);
			ft_putstr(":\n");
		}
		ret |= launch_nm(av[c]);
		reset_testouille();
		c++;
	}
	return (ret);
}
