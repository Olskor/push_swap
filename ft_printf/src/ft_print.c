/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:57:09 by jauffret          #+#    #+#             */
/*   Updated: 2023/03/10 10:27:59 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_str(char *s, int spacetype, int *space)
{
	int	count;

	count = 0;
	if (!ft_bitisset(spacetype, 0))
	{
		count += ft_putspace(space[0] - ft_checkstrlen(s, space, spacetype),
				' ');
		count += ft_putstrcheck_fd(s, 1, space, spacetype);
		return (count);
	}
	count += ft_putstrcheck_fd(s, 1, space, spacetype);
	count += ft_putspace(space[0] - ft_checkstrlen(s, space, spacetype), ' ');
	return (count);
}

int	ft_print_char(char s, int spacetype, int *space)
{
	int	count;

	count = 0;
	if (!ft_bitisset(spacetype, 0))
	{
		count += ft_putspace(space[0] - 1, ' ');
		ft_putchar_fd(s, 1);
		count += 1;
		return (count);
	}
	ft_putchar_fd(s, 1);
	count += ft_putspace(space[0] - 1, ' ');
	count += 1;
	return (count);
}

int	ft_print_nbr(int n, int spacetype, int *space)
{
	int		count;
	int		len;
	char	*s;

	s = ft_itoa(n);
	count = 0;
	len = ft_strlen(s);
	if (n < 0)
		len = ft_strlen(s) - 1;
	if (!ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - ft_strlen(s), ' ');
	if (n < 0)
		count += write(1, "-", 1);
	count += ft_putspace(space[1] - len, '0');
	count += ft_putnbrcheck_fd(s, n, space, spacetype);
	if (ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - count, ' ');
	free (s);
	return (count);
}

int	ft_print_unbr(unsigned int n, int spacetype, int *space)
{
	int		count;
	int		len;
	char	*s;

	s = ft_uitoa(n);
	count = 0;
	len = ft_strlen(s);
	if (!ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - len, ' ');
	count += ft_putspace(space[1] - len, '0');
	count += ft_putnbrcheck_fd(s, n, space, spacetype);
	if (ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - count, ' ');
	free (s);
	return (count);
}

int	ft_print_xnbr(unsigned long n, int spacetype, int *space, char *base)
{
	int		count;
	int		len;

	count = 0;
	len = ft_nbrlength(n, 16);
	if (n == 0)
		len = 0;
	if (!ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - ft_nbrlength(n, 16), ' ');
	count += ft_putspace(space[1] - len + 2 * ft_bitisset(spacetype, 5), '0');
	count += ft_putox(spacetype, base);
	count += ft_putnbr_base(n, base, spacetype, space);
	if (ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - count, ' ');
	return (count);
}
