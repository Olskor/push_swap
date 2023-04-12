/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:43:50 by olskor            #+#    #+#             */
/*   Updated: 2023/04/12 17:44:37 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

t_tab	freeall(t_tab *tab, char **list, int i)
{
	freetab(tab);
	while (list[i])
		free(list[i++]);
	free(list);
	return (*tab);
}

int	whoisthegreatest(t_list *lst, int num, int mem)
{
	int		greatlast;
	int		greatfirst;

	if (mem < 2)
		return (0);
	if (num < lst->content)
		return (0);
	greatlast = lastgreatestpos(lst, num);
	greatfirst = 0;
	while (num > lst->content)
	{
		greatfirst++;
		lst = lst->next;
		if (!lst)
			break ;
	}
	if (greatfirst < greatlast - mem)
		return (greatfirst);
	return (greatlast - mem);
}

int	objectpos(t_list *lst, int num)
{
	int	pos;
	int	size;

	size = ft_lstsize(lst);
	if (ft_lstsize(lst) < 2)
		return (0);
	if (num == lst->content)
		return (0);
	pos = 0;
	while (num != lst->content)
	{
		pos++;
		lst = lst->next;
		if (!lst)
			break ;
	}
	if (pos > size / 2)
		return (pos - size);
	return (pos);
}

char	*ft_sort3(t_tab *tab, char *rslt)
{
	if (!tab->a)
		return (ft_pa(tab, rslt));
	if (ft_lstsize(tab->a) == 1)
		return (rslt);
	if (ft_lstsize(tab->a) == 2)
	{
		if (tab->a->content > tab->a->next->content)
			return (ft_sa(tab, rslt));
		return (rslt);
	}
	if (tab->a->content > tab->a->next->next->content)
		rslt = ft_rra(tab, rslt);
	if (tab->a->content > tab->a->next->content)
		rslt = ft_sa(tab, rslt);
	if (tab->a->next->content > tab->a->next->next->content)
	{
		rslt = ft_rra(tab, rslt);
		rslt = ft_sort3(tab, rslt);
	}
	return (rslt);
}
