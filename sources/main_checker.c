/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:20:11 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/08 15:36:36 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_check_sorted(t_info *info)
{
	int	i;

	i = 0;
	if (info->pileb[0])
		return (NO_SORTED);
	else
	{
		while (i + 1 < info->nbr_pa)
		{
			if (info->pilea[i] > info->pilea[i + 1])
				return (NO_SORTED);
			i++;
		}
	}
	return (SORTED);
}

static int	ft_check_line(char *line, t_info *info)
{
	if (ft_compare(line, info) == SAME)
		return (SAME);
	else if (!line[0])
		return (END);
	else
		return (ft_printf_error());
}

static int	ft_checker(t_info *info)
{
	char	*line;
	int		get;

	line = NULL;
	get = get_next_line(0, &line);
	while (get > 0)
	{
		if (ft_check_line(line, info) == ERROR)
			return (ERROR);
		free(line);
		line = NULL;
		get = get_next_line(0, &line);
	}
	if (ft_check_line(line, info) == ERROR)
		return (ERROR);
	free(line);
	line = NULL;
	return (NO_ERROR);
}

static int	ft_get_pilea(t_info *info, char **argv)
{
	int			i;
	long int	nbr;

	i = 1;
	info->what = CHECKER;
	info->count_move = 0;
	info->nbr_pa = info->nbr_args;
	info->nbr_pb = 0;
	info->posi_pa = NULL;
	info->posi_pb = NULL;
	info->pileb = malloc(sizeof(int *) * 1);
	info->pileb[0] = '\0';
	info->pilea = malloc(sizeof(int *) * info->nbr_args + 1);
	if (!info->pilea)
		return (ft_printf_error());
	while (i <= info->nbr_args)
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

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (ft_check_int(argc, argv) == ERROR)
		return (ERROR);
	info.nbr_args = argc - 1;
	if (ft_get_pilea(&info, argv) == ERROR)
		return (ERROR);
	i = 0;
	while (i < info.nbr_pa)
	{	
		if (ft_check_double(&info, i) == ERROR)
			return (ERROR);
		i++;
	}
	if (ft_checker(&info) == ERROR)
		return (0);
	info.what = OK;
	if (ft_check_sorted(&info) == SORTED)
		ft_putstr("OK\n", &info);
	else
		ft_putstr("KO\n", &info);
	free(info.pilea);
	free(info.pileb);
	return (0);
}
