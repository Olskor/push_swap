/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:38:52 by jauffret          #+#    #+#             */
/*   Updated: 2023/02/18 15:44:37 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	printnbrbase(unsigned long nbr, int i, char *base, int basesize)
{
	if (i > 1)
		printnbrbase(nbr / basesize, i - 1, base, basesize);
	ft_putchar_fd(base[nbr % basesize], 1);
}

int	ft_nbrlength(unsigned long i, int n)
{
	int	w;

	w = 0;
	while (i >= (unsigned long) n)
	{
		i = i / n;
		w++;
	}
	return (w + 1);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int spacetype, int *space)
{
	unsigned int	i;

	i = (unsigned int) nbr;
	if (!nbr && (ft_bitisset(spacetype, 2) || ft_bitisset(spacetype, 1)))
		return (0);
	if (ft_bitisset(spacetype, 5))
	{
		printnbrbase(nbr, ft_nbrlength(nbr, 16), base, 16);
		return (ft_nbrlength(nbr, 16));
	}
	space[0] = space[0];
	printnbrbase(i, ft_nbrlength(i, 16), base, 16);
	return (ft_nbrlength(i, 16));
}
