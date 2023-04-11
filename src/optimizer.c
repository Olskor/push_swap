/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olskor <olskor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:26:02 by olskor            #+#    #+#             */
/*   Updated: 2023/04/09 19:02:18 by olskor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

t_rot	ft_isrotate2(char *str, t_rot rot)
{
	if (!ft_strncmp(str, "rb", 2))
	{
		rot.rb++;
		rot.bo = 1;
		return (rot);
	}
	if (!ft_strncmp(str, "rrb", 3))
	{
		rot.rb--;
		rot.bo = 1;
		return (rot);
	}
	rot.bo = 0;
	return (rot);
}

t_rot	ft_isrotate(char *str, t_rot rot)
{
	if (!ft_strncmp(str, "ra", 2))
	{
		rot.ra++;
		rot.bo = 1;
		return (rot);
	}
	if (!ft_strncmp(str, "rra", 3))
	{
		rot.ra--;
		rot.bo = 1;
		return (rot);
	}
	return (ft_isrotate2(str, rot));
}

t_rot	ft_detect2(char *str, t_rot rot)
{
	while (rot.rb > 0)
	{
		ft_printf("rb\n");
		rot.rb--;
	}
	while (rot.ra < 0)
	{
		ft_printf("rra\n");
		rot.ra++;
	}
	while (rot.rb < 0)
	{
		ft_printf("rrb\n");
		rot.rb++;
	}
	ft_printf("%s\n", str);
	return (rot);
}

t_rot	ft_detect(char *str, t_rot rot)
{
	rot = ft_isrotate(str, rot);
	if (rot.bo)
		return (rot);
	while (rot.ra > 0 && rot.rb > 0)
	{
		ft_printf("rr\n");
		rot.ra--;
		rot.rb--;
	}
	while (rot.ra < 0 && rot.rb < 0)
	{
		ft_printf("rrr\n");
		rot.ra++;
		rot.rb++;
	}
	while (rot.ra > 0)
	{
		ft_printf("ra\n");
		rot.ra--;
	}
	return (ft_detect2(str, rot));
}

void	ft_optimise(char *rslt, int ra, int rb)
{
	char	**ret;
	int		i;
	t_rot	rot;

	ret = ft_split(rslt, '\n');
	i = 0;
	rot.ra = ra;
	rot.rb = rb;
	rot.bo = 0;
	while (ret[i])
	{
		rot = ft_detect(ret[i], rot);
		if (ra || rb)
			ra = ra;
		free(ret[i]);
		i++;
	}
	free(ret);
}
