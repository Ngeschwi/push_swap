/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_a_posi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:16:32 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 12:20:44 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_and_call(int **tab1, int **tab2)
{
	free(*tab1);
	free(*tab2);
}

void	ft_sa_posi(t_info *info)
{
	int	nbr_save;

	if (info->nbr_pa >= 2)
	{
		nbr_save = info->posi_pa[0];
		info->posi_pa[0] = info->posi_pa[1];
		info->posi_pa[1] = nbr_save;
	}
}

void	ft_pa_posi(t_info *info)
{
	int	*save_pa;
	int	*save_pb;
	int	i;

	i = -1;
	if (info->nbr_pb >= 1)
	{
		save_pa = ft_intdup(info->posi_pa, info->nbr_pa - 1);
		save_pb = ft_intdup(info->posi_pb, info->nbr_pb + 1);
		free(info->posi_pa);
		free(info->posi_pb);
		info->posi_pa = malloc(sizeof(int *) * (info->nbr_pa + 1));
		info->posi_pb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		info->posi_pa[0] = save_pb[0];
		while (++i < info->nbr_pa - 1)
			info->posi_pa[i + 1] = save_pa[i];
		info->posi_pa[i + 1] = '\0';
		i = -1;
		while (++i < info->nbr_pb + 1)
			info->posi_pb[i] = save_pb[i + 1];
		info->posi_pb[i] = '\0';
		ft_free_and_call(&save_pa, &save_pb);
	}
}

void	ft_ra_posi(t_info *info)
{
	int	*save_pa;
	int	i;

	i = 1;
	if (info->nbr_pa >= 2)
	{
		save_pa = ft_intdup(info->posi_pa, info->nbr_pa);
		free(info->posi_pa);
		info->posi_pa = malloc(sizeof(int *) * (info->nbr_pa + 1));
		while (i < info->nbr_pa)
		{
			info->posi_pa[i - 1] = save_pa[i];
			i++;
		}
		info->posi_pa[i - 1] = save_pa[0];
		info->posi_pa[i] = '\0';
		free(save_pa);
	}
}

void	ft_rra_posi(t_info *info)
{
	int	*save_pa;
	int	i;

	i = 0;
	if (info->nbr_pa >= 2)
	{
		save_pa = ft_intdup(info->posi_pa, info->nbr_pa);
		free(info->posi_pa);
		info->posi_pa = malloc(sizeof(int *) * (info->nbr_pa + 1));
		info->posi_pa[0] = save_pa[info->nbr_pa - 1];
		while (i < info->nbr_pa)
		{
			info->posi_pa[i + 1] = save_pa[i];
			i++;
		}
		info->posi_pa[i] = '\0';
		free(save_pa);
	}
}
