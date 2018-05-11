/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_return_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:11:05 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/15 14:11:12 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corrupted_checker.h"
#include "utilities.h"
#include "generic_nm.h"
#include <stdlib.h>

int	spe_return_error(int value_error,\
t_ctr_consis *consis)
{
	consis->error = value_error;
	return (1);
}
