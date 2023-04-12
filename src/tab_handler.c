/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:03:55 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/11 15:03:24 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	ft_atoicheck(char *str, int *val)
{
	int	i;

	i = ft_atoi(str);
	if (i < 0 && str[0] != '-')
		*val = 1;
	if (i > 0 && str[0] == '-')
		*val = 1;
	return (i);
}

t_tab	ft_setuptab(char **src, int ret)
{
	t_tab	tab;
	int		i;

	tab.size = 0;
	i = 1;
	while (src[tab.size])
		tab.size++;
	if (ft_checkdigit(src[i]))
		return (tab);
	tab.a = ft_lstnew(ft_atoicheck(src[i], &ret));
	tab.b = 0;
	i++;
	while (src[i])
	{
		if (ft_checkdigit(src[i]))
		{
			freetab(&tab);
			return (tab);
		}
		ft_lstadd_back(&tab.a, ft_lstnew(ft_atoicheck(src[i], &ret)));
		i++;
	}
	if (ret)
		freetab(&tab);
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
