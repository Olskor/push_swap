/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmanipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:17:56 by jauffret          #+#    #+#             */
/*   Updated: 2023/02/16 17:21:38 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_iterative_power(int nb, int power)
{
	int	rslt;

	rslt = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		rslt *= nb;
		power--;
	}
	return (rslt);
}

int	ft_bitisset(int n, int pos)
{
	if ((n) & (1 << (pos)))
	{
		return (1);
	}
	return (0);
}

int	ft_bitset(int n, int pos)
{
	if (!(ft_bitisset(n, pos)))
	{
		return (n + ft_iterative_power(2, pos));
	}
	return (n);
}

int	ft_bitunset(int n, int pos)
{
	if (ft_bitisset(n, pos))
	{
		return (n - ft_iterative_power(2, pos));
	}
	return (n);
}
