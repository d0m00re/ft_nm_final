/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:32:39 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/08 22:35:42 by alhelson         ###   ########.fr       */
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
#include "corrupted_checker.h"

#include "otool_manage.h"

#include <mach-o/fat.h>

int				main(int ac, char **av)
{
	int			fd;
	int			ret;
	char		*ptr;
	struct stat buf;

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (fstat(fd, &buf) < 0)
		return (EXIT_FAILURE);
	if ((ptr = mmap(0, buf.st_size,\
	PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (EXIT_FAILURE);
	if ((ret = main_checker(ptr, buf.st_size)))
	{
		ft_putstr("Corrupted file : "); ft_putnbr(ret); ft_putchar('\n');
	}
	else
		ft_putstr("Good file :)\n");
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	return (1);
}
