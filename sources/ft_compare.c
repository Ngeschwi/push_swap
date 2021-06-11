/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:32:42 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 10:21:07 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check(char *line, char *str)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != str[i])
			return (NOT_SAME);
		i++;
	}
	if (str[i])
		return (NOT_SAME);
	return (SAME);
}

int	ft_compare(char *line, t_info *info)
{
	if (ft_check(line, "sa") == SAME)
		ft_sa(info);
	else if (ft_check(line, "sb") == SAME)
		ft_sb(info);
	else if (ft_check(line, "ss") == SAME)
		ft_ss(info);
	else if (ft_check(line, "pa") == SAME)
		ft_pa(info);
	else if (ft_check(line, "pb") == SAME)
		ft_pb(info);
	else if (ft_check(line, "ra") == SAME)
		ft_ra(info);
	else if (ft_check(line, "rb") == SAME)
		ft_rb(info);
	else if (ft_check(line, "rr") == SAME)
		ft_rr(info);
	else if (ft_check(line, "rra") == SAME)
		ft_rra(info);
	else if (ft_check(line, "rrb") == SAME)
		ft_rrb(info);
	else if (ft_check(line, "rrr") == SAME)
		ft_rrr(info);
	else
		return (NOT_SAME);
	return (SAME);
}
