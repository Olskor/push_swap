/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:41:30 by jauffret          #+#    #+#             */
/*   Updated: 2023/02/18 15:55:22 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 5  4  3  2  1  0        0
// # ' ' +  .  0  -     nothing

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX "0123456789abcdef"

# include <stdarg.h>

int		ft_putnbr_base(unsigned long nbr, char *base, int spacetype,
			int *space);
int		arg_print(va_list ptr, char c, int space, int *numberspace);
char	*ft_uitoa(unsigned int nbr);
int		ft_putspace(int n, char c);
int		ft_bitisset(int n, int pos);
int		ft_bitset(int n, int pos);
int		ft_bitunset(int n, int pos);
int		ft_print_char(char s, int spacetype, int *space);
int		ft_print_str(char *s, int spacetype, int *space);
int		ft_print_nbr(int n, int spacetype, int *space);
int		ft_putstrcheck_fd(char *s, int fd, int *space, int spacetype);
int		ft_checkstrlen(char *s, int *space, int spacetype);
int		ft_print_unbr(unsigned int n, int spacetype, int *space);
int		ft_print_xnbr(unsigned long n, int spacetype, int *space, char *base);
int		ft_nbrlength(unsigned long i, int n);
int		ft_print_pnbr(unsigned long n, int spacetype, int *space, char *base);
int		ft_putox(int spacetype, char *base);
int		ft_check_spacetype(char c, int w);
int		ft_putnbrcheck_fd(char *s, int fd, int *space, int spacetype);

int		ft_printf(const char *s, ...);

#endif
