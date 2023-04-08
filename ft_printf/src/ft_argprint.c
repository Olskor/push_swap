/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:02:07 by jauffret          #+#    #+#             */
/*   Updated: 2023/03/10 10:29:35 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	arg_print(va_list ptr, char c, int spacetype, int *space)
{
	if (c == 's')
		return (ft_print_str(va_arg(ptr, char *), spacetype, space));
	if (c == 'c')
		return (ft_print_char(va_arg(ptr, int), spacetype, space));
	if (c == 'i' || c == 'd')
		return (ft_print_nbr(va_arg(ptr, int), spacetype, space));
	if (c == 'u')
		return (ft_print_unbr(va_arg(ptr, int), spacetype, space));
	if (c == 'x')
		return (ft_print_xnbr(va_arg(ptr, long), spacetype, space
				, "0123456789abcdef"));
	if (c == 'X')
		return (ft_print_xnbr(va_arg(ptr, long), spacetype, space
				, "0123456789ABCDEF"));
	if (c == 'p')
	{
		spacetype = ft_bitset(spacetype, 5);
		spacetype = ft_bitset(spacetype, 6);
		return (ft_print_pnbr(va_arg(ptr, long), spacetype, space
				, "0123456789abcdef"));
	}
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
