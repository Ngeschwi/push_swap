/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:44:55 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 12:37:15 by ngeschwi         ###   ########.fr       */
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
		return (ft_free_error(info, 1));
	while (i <= info->nbr_pa)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (ft_free_error(info, 1));
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

static void	ft_free(t_info *info)
{
	free(info->pilea);
	free(info->pileb);
	free(info->posi_pa);
	free(info->posi_pb);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 2)
	{
		if (ft_change_arg(&info, argv) == ERROR)
			return (ERROR);
	}
	else
	{
		if (ft_check_int(argc, argv) == ERROR)
			return (ERROR);
		info.nbr_args = argc - 1;
		if (ft_get_pilea(&info, argv) == ERROR)
			return (ERROR);
	}
	info.what = PUSH;
	ft_get_min_max(&info);
	if (ft_get_posi_pa(&info) == ERROR)
		return (ERROR);
	if (ft_check_double(&info) == ERROR)
		return (ERROR);
	push_swap(&info);
	ft_free(&info);
	return (0);
}
