/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:07:19 by  jauffret         #+#    #+#             */
/*   Updated: 2023/02/17 18:02:12 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	check_idterm(char c)
{
	int	i;

	i = (c != 'd' && c != 's' && c != 'c' && c != 'i'
			&& c != 'x' && c != 'X' && c != 'p' && c != '%'
			&& c != 'u');
	return (i);
}

static int	check_spaceplus(char c, int spacetype)
{
	if (c == ' ')
		return (ft_bitset(spacetype, 4));
	if (c == '+')
		return (ft_bitset(spacetype, 3));
	if (c == '#')
		return (ft_bitset(spacetype, 5));
	if (c == '.')
		return (ft_bitset(spacetype, 2));
	if (c == '0')
		return (ft_bitset(spacetype, 1));
	if (c == '-')
		return (ft_bitset(spacetype, 0));
	return (spacetype);
}

int	ft_putspace(int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	if (n < 0)
		return (0);
	return (n);
}

int	ft_printfbonus(const char *s, va_list ptr, int *i, int *n)
{
	int	spacetype;
	int	*space;
	int	w;

	spacetype = 0;
	space = ft_calloc(3, sizeof(int));
	w = 0;
	*i += 1;
	while (check_idterm(s[*i]))
	{
		spacetype = check_spaceplus(s[*i], spacetype);
		w = ft_check_spacetype(s[*i], w);
		if (s[*i] > '0' && s[*i] <= '9' && !space[w])
		{
			space[w] = ft_atoi(s + *i);
			while (ft_isdigit(s[*i]))
				*i += 1;
		}
		else
			*i += 1;
	}
	*n += arg_print(ptr, s[*i], spacetype, space);
	*i += 1;
	free(space);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		n;
	va_list	ptr;

	va_start(ptr, s);
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, s + i, 1);
			i += 1;
			n += 1;
		}
		else
			ft_printfbonus(s, ptr, &i, &n);
	}
	return (n);
}
