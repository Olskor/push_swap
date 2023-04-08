/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <jauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:56:11 by jauffret          #+#    #+#             */
/*   Updated: 2023/04/08 16:51:21 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define HELP "Type: ./push_swap <value1, value2, vlaue3, ...>\n"
# define ERR0 "Error: not enough argument\n"
# define ERR1 "Error: invalid argument.\nargument format ex: \"1,5,9,7\".\n"
# define ERR2 "Error: invalid argument.\nneed at least 2 values.\n"

typedef struct s_tab
{
	t_list	*a;
	t_list	*b;
	int		size;
}	t_tab;

char	*ft_sa(t_tab *tab, char *str);
char	*ft_sb(t_tab *tab, char *str);
char	*ft_ss(t_tab *tab, char *str);
char	*ft_pa(t_tab *tab, char *str);
char	*ft_pb(t_tab *tab, char *str);
char	*ft_ra(t_tab *tab, char *str);
char	*ft_rb(t_tab *tab, char *str);
char	*ft_rr(t_tab *tab, char *str);
char	*ft_rra(t_tab *tab, char *str);
char	*ft_rrb(t_tab *tab, char *str);
char	*ft_rrr(t_tab *tab, char *str);
char	*ft_qssolve(t_tab *tab, char *rslt);
void	ft_showtab(t_list *a, t_list *b);
t_tab	ft_setuptab(char **src);
void	freetab(t_tab *tab);
void	delint(int d);

#endif