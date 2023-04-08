/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:03:55 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/08 12:24:40 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

t_tab	ft_setuptab(char **src)
{
	t_tab	tab;
	int		i;

	tab.size = 0;
	i = 1;
	while (src[tab.size])
		tab.size++;
	tab.a = ft_lstnew(ft_atoi(src[i]));
	i++;
	while (src[i])
	{
		ft_lstadd_back(&tab.a, ft_lstnew(ft_atoi(src[i])));
		i++;
	}
	tab.b = 0;
	return (tab);
}

void	delint(int d)
{
	return ((void) d);
}

void	freetab(t_tab *tab)
{
	ft_lstclear(&tab->a, &delint);
	ft_lstclear(&tab->b, &delint);
}

char	*ft_rrr(t_tab *tab, char *str)
{
	char	*test;
	char	*ret;

	test = malloc(1);
	test[0] = 0;
	test = ft_rrb(tab, test);
	test = ft_rra(tab, test);
	if (ft_strlen(test) > 4)
	{
		ret = ft_strjoin(str, "rrr\n");
		free(test);
		free(str);
		return (ret);
	}
	ret = ft_strjoin(str, test);
	free(test);
	free(str);
	return (ret);
}