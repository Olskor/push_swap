/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_handler2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:58:36 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/12 18:14:32 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

t_tab	ft_setuptab1(char *src, int ret, int i)
{
	t_tab	tab;
	char	**list;

	tab.size = 0;
	list = ft_split(src, ' ');
	while (list[tab.size])
		tab.size++;
	if (ft_checkdigit(list[i]))
		return (tab);
	tab.a = ft_lstnew(ft_atoicheck(list[i], &ret));
	tab.b = 0;
	free(list[i++]);
	while (list[i])
	{
		if (ft_checkdigit(list[i]))
			return (freeall(&tab, list, i));
		ft_lstadd_back(&tab.a, ft_lstnew(ft_atoicheck(list[i], &ret)));
		free(list[i++]);
	}
	free(list);
	if (ret)
		freetab(&tab);
	return (tab);
}

int	ft_is2number(t_tab *tab)
{
	t_list	*mem;
	t_list	*loop;
	int		t;

	mem = tab->a;
	while (mem)
	{
		t = 0;
		loop = tab->a;
		while (loop)
		{
			if (mem->content == loop->content)
			{
				if (t)
					return (write(2, ERR3, ft_strlen(ERR3)));
				t++;
			}
			loop = loop->next;
		}
		mem = mem->next;
	}
	return (0);
}

int	ft_checkdigit(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (!ft_isdigit(src[i]))
		{
			if (src[i] == '-')
			{
				if (!ft_isdigit(src[i + 1]))
					return (1);
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_checktab(t_tab *tab)
{
	t_list	*mem;
	int		t;

	mem = tab->a;
	t = 1;
	while (mem)
	{
		if (mem->next)
			if (mem->next->content < mem->content)
				t = 0;
		mem = mem->next;
	}
	return (t);
}
