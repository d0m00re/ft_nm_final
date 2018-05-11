/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrupted_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:16:55 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 19:17:39 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORRUPTED_CHECKER_H
# define CORRUPTED_CHECKER_H

typedef struct		s_control_consistant
{
	unsigned int	size_file;
	unsigned int	size_header;
	unsigned int	size_symbol;
	unsigned int	size_segment;
	int				error;
}					t_ctr_consis;

int					main_checker(char *ptr, unsigned int size);

int					beatiful_checker(char *ptr, t_ctr_consis *consis);

int					check_32bits(char *ptr, int rev, t_ctr_consis *consis);

int					check_64bits(char *ptr, int rev, t_ctr_consis *consis);

int					checker_fat_32(char *ptr, int rev, t_ctr_consis *consis);

int					checker_fat_64(char *ptr, int rev, t_ctr_consis *consis);

int					spe_return_error(int value_error,\
					t_ctr_consis *consis);

#endif
