/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_gen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:47:57 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 10:49:29 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_pilea(t_info *info, int *tab)
{
	int			i;
	long int	nbr;

	i = 0;
	info->what = GEN;
	info->nbr_pa = info->nbr_args;
	info->nbr_pb = 0;
	info->count_move = 0;
	info->pileb = malloc(sizeof(int *) * 1);
	info->pileb[0] = '\0';
	info->pilea = malloc(sizeof(int *) * info->nbr_args + 1);
	if (!info->pilea)
		return (ft_printf_error());
	while (i <= info->nbr_args)
	{
		nbr = tab[i];
		info->pilea[i] = nbr;
		i++;
	}
	info->pilea[i] = '\0';
	return (NO_ERROR);
}

static void	ft_get_min_max(t_info *info)
{
	int	i;

	i = 0;
	info->max = info->pilea[0];
	info->min = info->pilea[0];
	while (i < info->nbr_pa)
	{
		if (info->pilea[i] > info->max)
			info->max = info->pilea[i];
		if (info->pilea[i] < info->min)
			info->min = info->pilea[i];
		i++;
	}
	info->nbr_div = sqrt(info->nbr_pa) / 2 + 1;
	info->index = 0;
}

int	push_swap_gen(int cmb, int *tab)
{
	t_info	info;
	int		i;

	info.nbr_args = cmb;
	if (ft_get_pilea(&info, tab) == ERROR)
		return (ERROR);
	ft_get_min_max(&info);
	if (ft_get_posi_pa(&info) == ERROR)
		return (ERROR);
	i = 0;
	while (i < info.nbr_pa)
	{
		printf("%d ", info.pilea[i]);
		i++;
	}
	printf("||\n");
	push_swap(&info);
	free(info.pilea);
	free(info.pileb);
	free(info.posi_pa);
	free(info.posi_pb);
	printf("Nous avons eu besion de %d mouvements\n\n", info.count_move);
	return (info.count_move);
}
