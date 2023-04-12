/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:14:00 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/12 18:15:46 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	ft_doaction4(t_tab *tab, char *str, char *c)
{
	if (!ft_strncmp(str, "ss", 3))
	{
		c = ft_ss(tab, c);
		free(c);
		return (0);
	}
	free(c);
	return (1);
}

int	ft_doaction3(t_tab *tab, char *str, char *c)
{
	if (!ft_strncmp(str, "rrb", 4))
	{
		c = ft_rrb(tab, c);
		free(c);
		return (0);
	}
	if (!ft_strncmp(str, "rr", 3))
	{
		c = ft_rr(tab, c);
		free(c);
		return (0);
	}
	if (!ft_strncmp(str, "rrr", 4))
	{
		c = ft_rrr(tab, c);
		free(c);
		return (0);
	}
	return (ft_doaction4(tab, str, c));
}
