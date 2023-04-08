/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:15:38 by jauffret          #+#    #+#             */
/*   Updated: 2023/02/18 15:38:30 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	checknbr(int *space, int spacetype)
{
	int	count;

	count = 0;
	if (!ft_bitisset(spacetype, 0))
	{
		count += ft_putspace(space[0] - 5, ' ');
		ft_putstr_fd("(nil)", 1);
		return (count + 5);
	}
	ft_putstr_fd("(nil)", 1);
	count += ft_putspace(space[0] - 5, ' ');
	return (count + 5);
}

int	ft_print_pnbr(unsigned long n, int spacetype, int *space, char *base)
{
	int		count;

	count = 0;
	if (!n)
		return (checknbr(space, spacetype));
	if (!ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - ft_nbrlength(n, 16) - 2, ' ');
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_putnbr_base(n, base, spacetype, space);
	if (ft_bitisset(spacetype, 0))
		count += ft_putspace(space[0] - ft_nbrlength(n, 16) - 2, ' ');
	return (count);
}

int	ft_putox(int spacetype, char *base)
{
	if (ft_bitisset(spacetype, 5))
	{
		if (base[15] == 'F')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		return (2);
	}
	return (0);
}
