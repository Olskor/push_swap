/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:00:46 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/07 12:28:13 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lst_del(t_list *first, t_list	*new, void (*del)(int))
{
	while (first)
	{
		new = first->next;
		(*del)(first->content);
		free(first);
		first = new;
	}
}

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*first;
	t_list	*new;
	int		temp;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			lst_del(first, new, del);
			lst = NULL;
			del (temp);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
