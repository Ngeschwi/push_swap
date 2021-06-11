/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_posia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:27:00 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 10:41:12 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_posia_tow(t_info *info)
{
	if (info->pilea[0] == info->min)
	{
		info->posi_pa[0] = 1;
		info->posi_pa[1] = 2;
	}
	else
	{
		info->posi_pa[0] = 2;
		info->posi_pa[1] = 1;
	}
	return (NO_ERROR);
}

static int	ft_define_next(t_info *info, int last, int next)
{
	int	i;

	i = 0;
	while (i < info->nbr_pa)
	{
		if (info->pilea[i] == info->min)
			info->posi_pa[i] = 1;
		if (info->pilea[i] == info->max)
			info->posi_pa[i] = info->nbr_pa;
		if (info->pilea[i] > last && info->pilea[i] < next)
		{
			info->index = i;
			next = info->pilea[i];
		}
		i++;
	}
	return (next);
}

int	ft_get_posi_pa(t_info *info)
{
	int	position;
	int	last;
	int	next;

	position = 2;
	last = info->min;
	info->posi_pb = malloc(sizeof(int *) * 1);
	info->posi_pb[0] = '\0';
	info->posi_pa = malloc(sizeof(int *) * (info->nbr_pa + 1));
	if (!info->posi_pa)
		return (ft_free_error(info, 2));
	if (info->nbr_args == 2)
		return (ft_posia_tow(info));
	while (position < info->nbr_pa)
	{
		next = info->max;
		next = ft_define_next(info, last, next);
		last = next;
		info->posi_pa[info->index] = position;
		position++;
	}
	return (NO_ERROR);
}
