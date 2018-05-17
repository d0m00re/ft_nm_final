/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:25:19 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/08 22:31:59 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# include <stdint.h>

# define ERR_EX " : file don't exit/bad perm\n"
# define ERR_OBJ " : The file was not recognized as a valid object file\n"

int				ft_error_file(char *name_exe, char *name_file, char *error);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, int size_max);

unsigned int	ft_strlen(const char *s);
unsigned int	ft_strlen_limit(const char *s, char *limit);

uint64_t		swap64(uint64_t r);
unsigned int	swap32(unsigned int x);
short			swap16(short x);
uint64_t		swap_gen(uint64_t value, unsigned int type_swap);

uint64_t		swap64_if(uint64_t x, int s);
unsigned int	swap32_if(unsigned int x, int s);
short			swap16_if(short x, int s);
uint64_t		swap_if_gen(uint64_t value, unsigned int type_swap, int s);

void			ft_putchar(char c);

void			ft_putstr(char *str);
void			ft_putstr_limit(char *str, char *end);
void			ft_putstr2(char *str, char *str2);

void			ft_putstr_same_char(char c, unsigned int rep);

void			ft_putnbr_base_ui(unsigned int nb, unsigned int base);

void			ft_putnbr_base_ui64(uint64_t nb, unsigned int base);

void			ft_putnbr(int nb);

unsigned int	nb_digit_buint64(uint64_t value);

void			set_testouille(char *mabite);

char			*get_testouille();

void			reset_testouille();

int				ft_strcmp_limit(const char *s1, const char *s2);

#endif
