/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:31:22 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/08 22:31:23 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	ft_error_file(char *name_exe, char *name_file, char *error)
{
	ft_putstr(name_exe);
	ft_putstr(name_file);
	ft_putstr(error);
	return (1);
}
