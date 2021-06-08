/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:32:01 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/08 17:02:59 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_and_call(int **tab1, int **tab2, t_info *info)
{
	free(*tab1);
	free(*tab2);
	if (info->what == PUSH || info->what == GEN)
		ft_pa_posi(info);
	ft_putstr("pa\n", info);
}

void	ft_sa(t_info *info)
{
	int	nbr_save;

	if (info->nbr_pa >= 2)
	{
		nbr_save = info->pilea[0];
		info->pilea[0] = info->pilea[1];
		info->pilea[1] = nbr_save;
		ft_putstr("sa\n", info);
		if (info->what == PUSH || info->what == GEN)
			ft_sa_posi(info);
	}
}

void	ft_pa(t_info *info)
{
	int	*save_pa;
	int	*save_pb;
	int	i;

	i = -1;
	if (info->nbr_pb >= 1)
	{
		save_pa = ft_intdup(info->pilea, info->nbr_pa);
		save_pb = ft_intdup(info->pileb, info->nbr_pb);
		free(info->pilea);
		free(info->pileb);
		info->nbr_pa++;
		info->nbr_pb--;
		info->pilea = malloc(sizeof(int *) * (info->nbr_pa + 1));
		info->pileb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		info->pilea[0] = save_pb[0];
		while (++i < info->nbr_pa - 1)
			info->pilea[i + 1] = save_pa[i];
		info->pilea[i + 1] = '\0';
		i = -1;
		while (++i < info->nbr_pb + 1)
			info->pileb[i] = save_pb[i + 1];
		info->pileb[i] = '\0';
		ft_free_and_call(&save_pa, &save_pb, info);
	}
}

void	ft_ra(t_info *info)
{
	int	*save_pa;
	int	i;

	i = 1;
	if (info->nbr_pa >= 2)
	{
		save_pa = ft_intdup(info->pilea, info->nbr_pa);
		free(info->pilea);
		info->pilea = malloc(sizeof(int *) * (info->nbr_pa + 1));
		while (i < info->nbr_pa)
		{
			info->pilea[i - 1] = save_pa[i];
			i++;
		}
		info->pilea[i - 1] = save_pa[0];
		info->pilea[i] = '\0';
		free(save_pa);
		if (info->what == PUSH || info->what == GEN)
			ft_ra_posi(info);
		ft_putstr("ra\n", info);
	}
}

void	ft_rra(t_info *info)
{
	int	*save_pa;
	int	i;

	i = 0;
	if (info->nbr_pa >= 2)
	{
		save_pa = ft_intdup(info->pilea, info->nbr_pa);
		free(info->pilea);
		info->pilea = malloc(sizeof(int *) * (info->nbr_pa + 1));
		info->pilea[0] = save_pa[info->nbr_pa - 1];
		while (i < info->nbr_pa)
		{
			info->pilea[i + 1] = save_pa[i];
			i++;
		}
		info->pilea[i] = '\0';
		free(save_pa);
		if (info->what == PUSH || info->what == GEN)
			ft_rra_posi(info);
		ft_putstr("rra\n", info);
	}
}
