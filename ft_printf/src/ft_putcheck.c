/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:21:54 by jauffret          #+#    #+#             */
/*   Updated: 2023/02/18 15:55:32 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_check_spacetype(char c, int w)
{
	if (c == '.')
		return (1);
	if (c == '0')
		return (2);
	return (w);
}

int	ft_putstrcheck_fd(char *s, int fd, int *space, int spacetype)
{
	if (!s)
	{
		if (ft_bitisset(spacetype, 2) && space[1] < 6)
			return (0);
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	if (ft_bitisset(spacetype, 2) && space[1] < (int)ft_strlen(s))
	{
		write(1, s, space[1]);
		return (space[1]);
	}
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}

int	ft_checkstrlen(char *s, int *space, int spacetype)
{
	if (!s)
	{
		if (ft_bitisset(spacetype, 2) && space[1] < 6)
			return (0);
		return (6);
	}
	if (ft_bitisset(spacetype, 2) && space[1] < (int)ft_strlen(s))
	{
		return (space[1]);
	}
	return (ft_strlen(s));
}

int	ft_putnbrcheck_fd(char *s, int fd, int *space, int spacetype)
{
	if (ft_bitisset(spacetype, 2))
		if (space[1] == 0 && fd == 0)
			return (0);
	if (s[0] == '-')
	{
		ft_putstr_fd(s + 1, 1);
		return (ft_strlen(s) - 1);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
