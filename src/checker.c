/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:10:54 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/12 17:59:39 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	ft_doaction2(t_tab *tab, char *str, char *c)
{
	if (!ft_strncmp(str, "pb", 3))
	{
		c = ft_pb(tab, c);
		free(c);
		return (0);
	}
	if (!ft_strncmp(str, "ra", 3))
	{
		c = ft_ra(tab, c);
		free(c);
		return (0);
	}
	if (!ft_strncmp(str, "rb", 3))
	{
		c = ft_rb(tab, c);
		free(c);
		return (0);
	}
	if (!ft_strncmp(str, "rra", 4))
	{
		c = ft_rra(tab, c);
		free(c);
		return (0);
	}
	return (ft_doaction3(tab, str, c));
}

int	ft_doaction(t_tab *tab, char *str)
{
	char	*c;

	c = ft_calloc(1, 1);
	if (!ft_strncmp(str, "sa", 3))
	{
		c = ft_sa(tab, c);
		free(c);
		return (0);
	}
	if (!ft_strncmp(str, "sb", 3))
	{
		c = ft_sb(tab, c);
		free(c);
		return (0);
	}
	if (!ft_strncmp(str, "pa", 3))
	{
		c = ft_pa(tab, c);
		free(c);
		return (0);
	}
	return (ft_doaction2(tab, str, c));
}

int	ft_test_tab(t_tab *tab, int i, int test)
{
	char	*str;
	char	**split;

	str = ft_calloc(100000000, 1);
	read(0, str, 100000000);
	split = ft_split(str, '\n');
	while (split[i])
	{
		test += ft_doaction(tab, split[i]);
		free(split[i]);
		i++;
	}
	free(str);
	free(split);
	if (ft_checktab(tab) && !test)
	{
		freetab(tab);
		return (0 * ft_printf("OK\n"));
	}
	freetab(tab);
	if (test)
		return (write(2, ERR4, ft_strlen(ERR4)));
	return (ft_printf("KO\n"));
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
	if (ft_is2number(&tab))
	{
		freetab(&tab);
		return (1);
	}
	ft_test_tab(&tab, 0, 0);
	freetab(&tab);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		return (ft_solver(argv, argc));
	return (ft_printf("%s%s", ERR0, HELP));
}
