/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:44:55 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/08 17:12:26 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_pilea(t_info *info, char **argv)
{
	int			i;
	long int	nbr;

	i = 1;
	info->what = PUSH;
	info->nbr_pa = info->nbr_args;
	info->nbr_pb = 0;
	info->count_move = 0;
	info->pileb = malloc(sizeof(int *) * 1);
	info->pileb[0] = '\0';
	info->pilea = malloc(sizeof(int *) * info->nbr_pa + 1);
	if (!info->pilea)
		return (ft_printf_error());
	while (i <= info->nbr_pa)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (ft_printf_error());
		info->pilea[i - 1] = (int)nbr;
		i++;
	}
	info->pilea[i - 1] = '\0';
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

static int	ft_get_posi_pa(t_info *info)
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
		return (ft_printf_error());
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

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (ft_check_int(argc, argv) == ERROR)
		return (ERROR);
	info.nbr_args = argc - 1;
	if (ft_get_pilea(&info, argv) == ERROR)
		return (ERROR);
	ft_get_min_max(&info);
	if (ft_get_posi_pa(&info) == ERROR)
		return (ERROR);
	i = 0;
	while (i < info.nbr_pa)
	{
		if (ft_check_double(&info, i) == ERROR)
			return (ERROR);
		i++;
	}
	push_swap(&info);
	free(info.pilea);
	free(info.pileb);
	free(info.posi_pa);
	free(info.posi_pb);
	return (0);
}
