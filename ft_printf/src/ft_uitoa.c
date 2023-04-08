/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:23:16 by jauffret          #+#    #+#             */
/*   Updated: 2023/03/10 10:26:27 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	nbrlength(unsigned int nbr)
{
	size_t	len;

	len = 0;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len + 1);
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_uitoa(unsigned int nbr)
{
	char	*str;
	int		len;

	len = nbrlength(nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (nbr >= 10)
	{
		str[len - 1] = ft_abs(nbr % 10) + '0';
		nbr = (nbr / 10);
		len--;
	}
	str[len - 1] = ft_abs(nbr % 10) + '0';
	return (str);
}
