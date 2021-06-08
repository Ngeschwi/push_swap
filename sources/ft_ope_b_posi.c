/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_b_posi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:16:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/08 16:56:47 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_and_call(int **tab1, int **tab2)
{
	free(*tab1);
	free(*tab2);
}

void	ft_sb_posi(t_info *info)
{
	int	nbr_save;

	if (info->nbr_pb >= 2)
	{
		nbr_save = info->posi_pb[0];
		info->posi_pb[0] = info->posi_pb[1];
		info->posi_pb[1] = nbr_save;
	}
}

void	ft_pb_posi(t_info *info)
{
	int	*save_pa;
	int	*save_pb;
	int	i;

	i = -1;
	if (info->nbr_pa + 1 >= 1)
	{
		save_pa = ft_intdup(info->posi_pa, info->nbr_pa + 1);
		save_pb = ft_intdup(info->posi_pb, info->nbr_pb - 1);
		i = -1;
		free(info->posi_pa);
		free(info->posi_pb);
		info->posi_pa = malloc(sizeof(int *) * (info->nbr_pa + 1));
		info->posi_pb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		info->posi_pb[0] = save_pa[0];
		while (++i < info->nbr_pb - 1)
			info->posi_pb[i + 1] = save_pb[i];
		info->posi_pb[i + 1] = '\0';
		i = 0;
		while (++i < info->nbr_pa + 1)
			info->posi_pa[i - 1] = save_pa[i];
		info->posi_pa[i - 1] = '\0';
		ft_free_and_call(&save_pb, &save_pa);
	}
}

void	ft_rb_posi(t_info *info)
{
	int	*save_pb;
	int	i;

	i = 1;
	if (info->nbr_pb >= 2)
	{
		save_pb = ft_intdup(info->posi_pb, info->nbr_pb);
		free(info->posi_pb);
		info->posi_pb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		while (i < info->nbr_pb)
		{
			info->posi_pb[i - 1] = save_pb[i];
			i++;
		}
		info->posi_pb[i - 1] = save_pb[0];
		info->posi_pb[i] = '\0';
		free(save_pb);
	}
}

void	ft_rrb_posi(t_info *info)
{
	int	*save_pb;
	int	i;

	i = 0;
	if (info->nbr_pb >= 2)
	{
		save_pb = ft_intdup(info->posi_pb, info->nbr_pb);
		free(info->posi_pb);
		info->posi_pb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		info->posi_pb[0] = save_pb[info->nbr_pb - 1];
		while (i < info->nbr_pb)
		{
			info->posi_pb[i + 1] = save_pb[i];
			i++;
		}
		info->posi_pb[i] = '\0';
		free(save_pb);
	}
}
