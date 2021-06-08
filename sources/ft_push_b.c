/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:43:47 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/08 16:03:09 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_calcul_index(t_info *info, int inter, int count_inter)
{
	int	i;

	i = 0;
	while (i < info->nbr_pa)
	{
		if (info->posi_pa[i] <= inter)
		{
			info->index = i;
			count_inter++;
			break ;
		}
		i++;
	}
	return (count_inter);
}

static int	ft_end_pa(t_info *info, int inter, int count_inter, int save_inter)
{
	ft_pb(info);
	if (info->posi_pb[0] < info->posi_pb[1] && info->nbr_pb >= 1)
	{
		if (info->posi_pb[0] < info->posi_pb[info->nbr_pb - 1])
			ft_rb(info);
		else
			ft_sb(info);
	}
	if (info->nbr_pa == 1)
		ft_pb(info);
	if (info->posi_pb[0] < info->posi_pb[1] && info->nbr_pb >= 1)
	{
		if (info->posi_pb[0] < info->posi_pb[info->nbr_pb - 1])
			ft_rb(info);
		else
			ft_sb(info);
	}
	if (count_inter == inter)
		inter += save_inter;
	return (inter);
}

static void	ft_index_inf(t_info *info)
{
	while (info->index > 0)
	{
		ft_ra(info);
		info->index--;
	}
}

static void	ft_index_sup(t_info *info)
{
	while (info->index < info->nbr_pa)
	{
		ft_rra(info);
		info->index++;
	}
}

void	ft_push_b(t_info *info)
{
	int	inter;
	int	save_inter;
	int	count_inter;

	count_inter = 0;
	inter = info->nbr_args / info->nbr_div;
	if ((info->nbr_args / info->nbr_div) % 2 != 0)
		inter ++;
	save_inter = inter;
	while (info->nbr_pa > 0)
	{
		count_inter = ft_calcul_index(info, inter, count_inter);
		if (info->index < info->nbr_pa / 2)
			ft_index_inf(info);
		else
			ft_index_sup(info);
		inter = ft_end_pa(info, inter, count_inter, save_inter);
		info->index = 0;
	}
}
