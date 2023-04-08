/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:34:08 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/08 16:39:38 by jauffret         ###   ########.fr       */
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
	while (1)
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

char	*ft_insert(char *str, char *lol)
{
	char	*ret;

	ret = ft_strjoin(str, lol);
	free(str);
	return (ret);
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
	return ret;
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

char	*ft_rota(t_tab *tab, char *rslt, int *rota)
{
	if (*rota == 1)
	{
		rslt = ft_ra(tab, rslt);
		rota = 0;
		return (rslt);
	}
	rslt = ft_rra(tab, rslt);
	rota = 0;
	return (rslt);
}

char	*ft_rotb(t_tab *tab, char *rslt, int rotb)
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
	return (rslt);
}

char	*ft_directpush(t_tab *tab, char *rslt)
{
	int	med;
	med = whoisthegreatest(tab->b, 4 * lstmax(tab->b) / 6, ft_lstsize(tab->b));
	if (med < -ft_lstsize(tab->b)/2)
		med = med + ft_lstsize(tab->b);
	rslt = ft_rotb(tab, rslt, med);
	rslt = ft_pa(tab, rslt);
	if (tab->a->content < lstmax(tab->b))
		rslt = ft_ra(tab, rslt);
	return (rslt);
}

char	*ft_pushtoa(t_tab *tab, char *rslt, int rotb)
{
	if (tab->a->content < ft_lstlast(tab->a)->content)
	{
		rslt = ft_directpush(tab, rslt);
		return (rslt);
	}
	if (ft_lstlast(tab->a)->content > lstmax(tab->b)
		&& ft_lstlast(tab->a)->content < tab->a->content)
	{
		rslt = ft_rra(tab, rslt);
		return (rslt);
	}
	rotb = whoisthegreatest(tab->b, ft_lstlast(tab->a)->content,
			ft_lstsize(tab->b));
	if (rotb < -ft_lstsize(tab->b)/2)
		rotb = rotb + ft_lstsize(tab->b);
	rslt = ft_rotb(tab, rslt, rotb);
	rslt = ft_pa(tab, rslt);
	if (tab->a->content < lstmax(tab->b))
		rslt = ft_ra(tab, rslt);
	else if (ft_lstlast(tab->a)->content > lstmax(tab->b)
		&& ft_lstlast(tab->a)->content < tab->a->content)
		rslt = ft_rra(tab, rslt);
	return (rslt);
}

char	*ft_qssolve(t_tab *tab, char *rslt)
{
	while (ft_lstsize(tab->a) > 2)
	{
		tab->size = 3 * (lstmax(tab->a) - lstmin(tab->a)) / 6;
		rslt = ft_push2third(tab, rslt, lstmin(tab->a) - 1);
	}
	if (tab->a->content > lstmin(tab->a))
		rslt = ft_sa(tab, rslt);
	while (ft_lstsize(tab->b) > 0)
	{
		rslt = ft_pushtoa(tab, rslt, 0);
	}
	while (ft_lstlast(tab->a)->content <= tab->a->content)
		rslt = ft_rra(tab, rslt);
	return (rslt);
}
