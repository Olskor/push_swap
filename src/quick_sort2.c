/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:38:36 by olskor            #+#    #+#             */
/*   Updated: 2023/04/11 14:46:00 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	lstmax(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = lst->content;
	while (lst)
	{
		if (i < lst->content)
			i = lst->content;
		lst = lst->next;
	}
	return (i);
}

int	lstmin(t_list *lst)
{
	int	i;

	i = lst->content;
	while (lst)
	{
		if (i > lst->content)
			i = lst->content;
		lst = lst->next;
	}
	return (i);
}

int	ft_qsb(t_tab *tab, int min)
{
	if (tab->b)
	{
		if (tab->b->next)
		{
			if (tab->b->content <= min)
				return (1);
		}
	}
	return (0);
}

char	*ft_push2third(t_tab *tab, char *rslt, int min)
{
	int	do_rb;

	do_rb = 0;
	while (tab->a)
	{
		do_rb = ft_qsb(tab, (tab->size / 2) + min);
		if (tab->a->content <= tab->size + min)
		{
			if (do_rb)
				rslt = ft_rb(tab, rslt);
			rslt = ft_pb(tab, rslt);
		}
		else
		{
			if (lstmin(tab->a) > tab->size + min)
				break ;
			if (do_rb)
			{
				rslt = ft_rr(tab, rslt);
			}
			else
				rslt = ft_ra(tab, rslt);
		}
	}
	return (rslt);
}

int	lastgreatestpos(t_list *lst, int num)
{
	int		val;
	t_list	*mem;
	int		ret;

	if (!lst)
		return (0);
	mem = lst;
	val = 0;
	ret = 0;
	while (lst)
	{
		if (num < lst->content)
			val = lst->content;
		lst = lst->next;
	}
	lst = mem;
	while (lst->content != val)
	{
		lst = lst->next;
		ret++;
		if (!lst)
			break ;
	}
	return (ret);
}
