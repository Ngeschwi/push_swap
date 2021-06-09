/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:32:34 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:39:03 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_and_call(int **tab1, int **tab2, t_info *info)
{
	free(*tab1);
	free(*tab2);
	if (info->what == PUSH || info->what == GEN)
		ft_pb_posi(info);
	ft_putstr("pb\n", info);
}

void	ft_sb(t_info *info)
{
	int	nbr_save;

	if (info->nbr_pb >= 2)
	{
		nbr_save = info->pileb[0];
		info->pileb[0] = info->pileb[1];
		info->pileb[1] = nbr_save;
		if (info->what == PUSH || info->what == GEN)
			ft_sb_posi(info);
		ft_putstr("sb\n", info);
	}
}

void	ft_pb(t_info *info)
{
	int	*save_pa;
	int	*save_pb;
	int	i;

	i = -1;
	if (info->nbr_pa >= 1)
	{
		save_pa = ft_intdup(info->pilea, info->nbr_pa);
		save_pb = ft_intdup(info->pileb, info->nbr_pb);
		free(info->pilea);
		free(info->pileb);
		info->nbr_pa--;
		info->nbr_pb++;
		info->pilea = malloc(sizeof(int *) * (info->nbr_pa + 1));
		info->pileb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		info->pileb[0] = save_pa[0];
		while (++i < info->nbr_pb - 1)
			info->pileb[i + 1] = save_pb[i];
		info->pileb[i + 1] = '\0';
		i = 0;
		while (++i < info->nbr_pa + 1)
			info->pilea[i - 1] = save_pa[i];
		info->pilea[i - 1] = '\0';
		ft_free_and_call(&save_pb, &save_pa, info);
	}
}

void	ft_rb(t_info *info)
{
	int	*save_pb;
	int	i;

	i = 1;
	if (info->nbr_pb >= 2)
	{
		save_pb = ft_intdup(info->pileb, info->nbr_pb);
		free(info->pileb);
		info->pileb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		while (i < info->nbr_pb)
		{
			info->pileb[i - 1] = save_pb[i];
			i++;
		}
		info->pileb[i - 1] = save_pb[0];
		info->pileb[i] = '\0';
		free(save_pb);
		if (info->what == PUSH || info->what == GEN)
			ft_rb_posi(info);
		ft_putstr("rb\n", info);
	}
}

void	ft_rrb(t_info *info)
{
	int	*save_pb;
	int	i;

	i = 0;
	if (info->nbr_pb >= 2)
	{
		save_pb = ft_intdup(info->pileb, info->nbr_pb);
		free(info->pileb);
		info->pileb = malloc(sizeof(int *) * (info->nbr_pb + 1));
		info->pileb[0] = save_pb[info->nbr_pb - 1];
		while (i < info->nbr_pb)
		{
			info->pileb[i + 1] = save_pb[i];
			i++;
		}
		info->pileb[i] = '\0';
		free(save_pb);
		if (info->what == PUSH || info->what == GEN)
			ft_rrb_posi(info);
		ft_putstr("rrb\n", info);
	}
}
