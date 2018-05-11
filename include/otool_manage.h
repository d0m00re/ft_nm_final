/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_manage.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:24:23 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/02 19:24:34 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_MANAGE_H
# define OTOOL_MANAGE_H

void otool_64(char *ptr, int rev, char *name_file, unsigned int is_dis_arch);

void otool_32(char *ptr, int rev, char *name_file, unsigned int is_dis_arch);

void fat_otool_32(char *ptr, char *name_file, int rev);
void fat_otool_64(char *ptr, char *name_file, int rev);

void otool(char *ptr, char *name_file, unsigned int is_dis_arch);

void    display_cpu(char *name, int cpu_type);

#endif
