/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_free_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:15:51 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/09 19:15:59 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "nm_manage.h"

void	nm_free_in(t_nm *nm)
{
	if (!nm)
		return ;
	if (nm->elem)
		free(nm->elem);
	if (nm->sort_elem)
		free(nm->sort_elem);
	if (nm->sect->elem)
		free(nm->sect->elem);
	if (nm->sect)
		free(nm->sect);
}
