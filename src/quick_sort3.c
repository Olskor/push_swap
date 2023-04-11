/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olskor <olskor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:43:50 by olskor            #+#    #+#             */
/*   Updated: 2023/04/09 15:34:45 by olskor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

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
