/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:01:18 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/08 17:03:40 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_sorted(t_info *info)
{
	int	i;

	i = 0;
	if (info->nbr_pb > 0)
		return (NO_SORTED);
	else
	{
		while (i + 1 < info->nbr_pa)
		{
			if (info->posi_pa[i] > info->posi_pa[i + 1])
				return (NO_SORTED);
			i++;
		}
	}
	return (SORTED);
}

static void	ft_sort_three(t_info *info)
{
	if (info->nbr_pa == 3)
	{
		if (ft_check_sorted(info) == SORTED)
			return ;
		if (info->pilea[0] > info->pilea[1] && info->pilea[0] > info->pilea[2])
		{
			ft_ra(info);
			if (info->pilea[0] > info->pilea[1])
			{
				ft_sa(info);
			}
		}
		else
		{
			ft_sa(info);
			if (ft_check_sorted(info) == NO_SORTED)
			{
				ft_ra(info);
				if (ft_check_sorted(info) == NO_SORTED)
					ft_sa(info);
			}
		}
	}
	else if (info->pilea[0] > info->pilea[1] && info->pilea[1])
		ft_sa(info);
}

void	push_swap(t_info *info)
{
	if (ft_check_sorted(info) == NO_SORTED)
	{
		if (info->nbr_div == 1)
			ft_sort_three(info);
		else
		{
			info->index = 0;
			ft_push_b(info);
			info->index = 0;
			ft_push_a(info);
		}
	}
}
