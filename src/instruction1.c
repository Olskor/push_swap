/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:08:58 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/08 13:09:00 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

char	*ft_sa(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->a)
	{
		if (!tab->a->next)
			return (str);
		mem = tab->a;
		tab->a = tab->a->next;
		mem->next = tab->a->next;
		tab->a->next = mem;
		ret = ft_strjoin(str, "sa\n");
		free(str);
		return (ret);
	}
	return (str);
}

char	*ft_sb(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->b)
	{
		if (!tab->b->next)
			return (str);
		mem = tab->b;
		tab->b = tab->b->next;
		mem->next = tab->b->next;
		tab->b->next = mem;
			ret = ft_strjoin(str, "sb\n");
		free(str);
		return (ret);
	}
	return (str);
}

char	*ft_ss(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (!tab->b)
		return (ft_sa(tab, str));
	if (!tab->a)
		return (ft_sb(tab, str));
	if (!tab->b->next)
		return (ft_sa(tab, str));
	if (!tab->a->next)
		return (ft_sb(tab, str));
	mem = tab->b;
	tab->b = tab->b->next;
	mem->next = tab->b->next;
	tab->b->next = mem;
	mem = tab->a;
	tab->a = tab->a->next;
	mem->next = tab->a->next;
	tab->a->next = mem;
	ret = ft_strjoin(str, "ss\n");
	free(str);
	return (ret);
}

char	*ft_pb(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->a)
	{
		mem = tab->a->next;
		if (tab->b)
			ft_lstadd_front(&tab->b, ft_lstnew(tab->a->content));
		else
			tab->b = ft_lstnew(tab->a->content);
		ft_lstdelone(tab->a, &delint);
		tab->a = mem;
		ret = ft_strjoin(str, "pb\n");
		free(str);
		return (ret);
	}
	return (str);
}

char	*ft_pa(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->b)
	{
		mem = tab->b->next;
		if (tab->a)
			ft_lstadd_front(&tab->a, ft_lstnew(tab->b->content));
		else
			tab->a = ft_lstnew(tab->b->content);
		ft_lstdelone(tab->b, &delint);
		tab->b = mem;
		ret = ft_strjoin(str, "pa\n");
		free(str);
		return (ret);
	}
	return (str);
}
/*
rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.

rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.

rrr : rra et rrb en même temps
*/