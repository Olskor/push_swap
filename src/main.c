/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:50:44 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/08 12:33:57 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	ft_showlstcontent(t_list *lst)
{
	if (lst)
		return (lst->content);
	return (0);
}

void	ft_showtab(t_list *a, t_list *b)
{
	int		i;

	i = ft_lstsize(b);
	if (ft_lstsize(a) > ft_lstsize(b))
		i = ft_lstsize(a);
	ft_printf("-------------------------\n");
	ft_printf("|%11s|%11s|\n", "a", "b");
	ft_printf("-------------------------\n");
	while (i > 0)
	{
		ft_printf("|%11d|%11d|\n", ft_showlstcontent(a),
			ft_showlstcontent(b));
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		i--;
	}
}

int	ft_solver(char **arg)
{
	t_tab	tab;
	char	*rslt;

	tab = ft_setuptab(arg);
	if (!tab.a)
		return (ft_printf(ERR1));
	if (tab.size < 2)
	{
		freetab(&tab);
		return (ft_printf(ERR2));
	}
	rslt = malloc(1);
	rslt[0] = 0;
	rslt = ft_qssolve(&tab, rslt);
	ft_printf("%s", rslt);
	free(rslt);
	freetab(&tab);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 3)
		return (ft_solver(argv));
	return (ft_printf("%s%s", ERR0, HELP));
}
