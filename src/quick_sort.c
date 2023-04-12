/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:34:08 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/11 15:41:09 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

char	*ft_rota(t_tab *tab, char *rslt, int val)
{
	int	pos;

	pos = objectpos(tab->a, val);
	while (pos > 0)
	{
		rslt = ft_ra(tab, rslt);
		pos--;
	}
	while (pos < 0)
	{
		rslt = ft_rra(tab, rslt);
		pos++;
	}
	return (rslt);
}

int	ft_fclosemin(t_list *lst, int val)
{
	int	i;

	if (!lst)
		return (0);
	i = lstmax(lst);
	while (lst)
	{
		if (i > lst->content && lst->content > val)
		{
			i = lst->content;
		}
		lst = lst->next;
	}
	return (i);
}

char	*ft_rotb(t_tab *tab, char *rslt, int rotb, int norot)
{
	while (rotb > 0)
	{
		rslt = ft_rb(tab, rslt);
		rotb--;
	}
	while (rotb < 0)
	{
		rslt = ft_rrb(tab, rslt);
		rotb++;
	}
	if (norot)
		norot = 1;
	rslt = ft_rota(tab, rslt, ft_fclosemin(tab->a, tab->b->content));
	return (rslt);
}

char	*ft_pushtoa(t_tab *tab, char *rslt, int rotb)
{
	int	rot;

	rot = 0;
	if (lstmin(tab->a) > lstmax(tab->b))
	{
		rotb = whoisthegreatest(tab->b, 8 * lstmax(tab->b) / 9,
				ft_lstsize(tab->b));
		rot = 1;
	}
	else
		rotb = whoisthegreatest(tab->b, lstmin(tab->a),
				ft_lstsize(tab->b));
	if (rotb < -ft_lstsize(tab->b) / 2)
		rotb = rotb + ft_lstsize(tab->b);
	rslt = ft_rotb(tab, rslt, rotb, rot);
	rslt = ft_pa(tab, rslt);
	return (rslt);
}

char	*ft_qssolve(t_tab *tab, char *rslt)
{
	if (ft_lstsize(tab->a) <= 2)
	{
		if (tab->a->content > tab->a->next->content)
			rslt = ft_sa(tab, rslt);
		return (rslt);
	}
	while (ft_lstsize(tab->a) > 3)
	{
		tab->size = (lstmax(tab->a) - lstmin(tab->a)) / 2;
		rslt = ft_push2third(tab, rslt, lstmin(tab->a) - 1);
	}
	rslt = ft_sort3(tab, rslt);
	while (ft_lstsize(tab->b) > 0)
	{
		rslt = ft_pushtoa(tab, rslt, 0);
	}
	while (ft_lstlast(tab->a)->content <= tab->a->content)
		rslt = ft_rra(tab, rslt);
	return (rslt);
}
