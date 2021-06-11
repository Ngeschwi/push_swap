/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:56:01 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 12:41:24 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_calcul_index(t_info *info, int max_pb)
{
	int	i;

	i = 0;
	while (i < info->nbr_pb)
	{
		if (info->posi_pb[i] == max_pb)
		{
			info->index = i;
			max_pb--;
			break ;
		}
		i++;
	}
	return (max_pb);
}

static void	ft_index_inf(t_info *info)
{
	while (info->index > 0)
	{
		ft_rb(info);
		info->index--;
	}
}

static void	ft_index_sup(t_info *info)
{
	while (info->index < info->nbr_pb)
	{
		ft_rrb(info);
		info->index++;
	}
}

void	ft_push_a(t_info *info)
{
	int	max_pb;

	max_pb = info->nbr_args;
	while (info->nbr_pb > 0)
	{
		max_pb = ft_calcul_index(info, max_pb);
		if (info->index < info->nbr_pb / 2)
			ft_index_inf(info);
		else
			ft_index_sup(info);
		ft_pa(info);
	}
}
