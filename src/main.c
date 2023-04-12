/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:50:44 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/12 18:02:51 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	ft_suite(t_tab *tab)
{
	int		test;
	char	*rslt;

	test = 0;
	if (ft_is2number(tab))
		test = 1;
	if (ft_checktab(tab))
		test = 2;
	rslt = malloc(1);
	rslt[0] = 0;
	if (test == 0)
	{
		rslt = ft_qssolve(tab, rslt);
		ft_optimise(rslt, 0, 0);
	}
	free(rslt);
	freetab(tab);
	if (test == 1)
		return (1);
	return (0);
}

int	ft_solver(char **arg, int argc)
{
	t_tab	tab;

	if (argc == 2)
		tab = ft_setuptab1(arg[1], 0, 0);
	else
		tab = ft_setuptab(arg, 0);
	if (!tab.a)
		return (write(2, ERR1, ft_strlen(ERR1)));
	if (tab.size < 2)
	{
		freetab(&tab);
		return (0);
	}
	return (ft_suite(&tab));
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		return (ft_solver(argv, argc));
	return (ft_printf("%s%s", ERR0, HELP));
}
