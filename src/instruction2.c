/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:57:28 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/08 12:24:29 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

char	*ft_ra(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->a)
	{
		if (tab->a->next)
		{
			mem = tab->a;
			tab->a = tab->a->next;
			ft_lstlast(tab->a)->next = mem;
			mem->next = NULL;
			ret = ft_strjoin(str, "ra\n");
			free(str);
			return (ret);
		}
	}
	return (str);
}

char	*ft_rb(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->b)
	{
		if (tab->b->next)
		{
			mem = tab->b;
			tab->b = tab->b->next;
			ft_lstlast(tab->b)->next = mem;
			mem->next = NULL;
			ret = ft_strjoin(str, "rb\n");
			free(str);
			return (ret);
		}
	}
	return (str);
}

char	*ft_rr(t_tab *tab, char *str)
{
	char	*test;
	char	*ret;

	test = malloc(1);
	test[0] = 0;
	test = ft_rb(tab, test);
	test = ft_ra(tab, test);
	if (ft_strlen(test) > 4)
	{
		ret = ft_strjoin(str, "rr\n");
		free(test);
		free(str);
		return (ret);
	}
	ret = ft_strjoin(str, test);
	free(test);
	free(str);
	return (ret);
}

char	*ft_rra(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->a)
	{
		if (tab->a->next)
		{
			mem = tab->a;
			while (tab->a->next->next)
				tab->a = tab->a->next;
			tab->a->next->next = mem;
			mem = tab->a->next;
			tab->a->next = NULL;
			tab->a = mem;
			ret = ft_strjoin(str, "rra\n");
			free(str);
			return (ret);
		}
	}
	return (str);
}

char	*ft_rrb(t_tab *tab, char *str)
{
	char	*ret;
	t_list	*mem;

	if (tab->b)
	{
		if (tab->b->next)
		{
			mem = tab->b;
			while (tab->b->next->next)
				tab->b = tab->b->next;
			tab->b->next->next = mem;
			mem = tab->b->next;
			tab->b->next = NULL;
			tab->b = mem;
			ret = ft_strjoin(str, "rrb\n");
			free(str);
			return (ret);
		}
	}
	return (str);
}
