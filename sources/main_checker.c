/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:20:11 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 12:07:39 by ngeschwi         ###   ########.fr       */
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
			{
				free(info->pilea);
				free(info->pileb);
				return (NO_SORTED);
			}
			i++;
		}
	}
	ft_putstr("OK\n", info);
	free(info->pilea);
	free(info->pileb);
	return (SORTED);
}

static int	ft_check_line(char *line, t_info *info)
{
	if (ft_compare(line, info) == SAME)
		return (SAME);
	else if (!line[0])
		return (END);
	else
		return (ft_free_error(info, 1));
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
		{
			ft_free_define(&line);
			return (ERROR);
		}
		ft_free_define(&line);
		get = get_next_line(0, &line);
	}
	if (ft_check_line(line, info) == ERROR)
	{
		ft_free_define(&line);
		return (ERROR);
	}
	ft_free_define(&line);
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
		return (ft_free_error(info, 1));
	while (i <= info->nbr_args)
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
	info.what = CHECKER;
	if (ft_check_double(&info) == ERROR)
		return (ERROR);
	if (ft_checker(&info) == ERROR)
		return (ERROR);
	info.what = OK;
	if (ft_check_sorted(&info) == NO_SORTED)
		ft_putstr("KO\n", &info);
	return (0);
}
