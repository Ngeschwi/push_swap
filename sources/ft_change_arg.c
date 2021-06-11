/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:49:08 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 12:43:35 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_init(t_info *info)
{
	info->nbr_pa = info->nbr_args;
	info->nbr_pb = 0;
	info->count_move = 0;
	info->pileb = malloc(sizeof(int *) * 1);
	info->pileb[0] = '\0';
	info->pilea = malloc(sizeof(int *) * (info->nbr_args + 1));
	if (!info->pilea)
		return (ft_free_error(info, 1));
	return (NO_ERROR);
}

static int	ft_len_nbr(char **argv, int i)
{
	int	len;

	len = 0;
	if (argv[1][i] == '-')
	{
		len++;
		i++;
	}
	while (ft_isdigit(argv[1][i]))
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_get_pile(t_info *info, char **argv)
{
	int		i;
	int		j;
	int		h;
	char	*nbr;
	int		len;

	i = 0;
	h = 0;
	if (ft_init(info) == ERROR)
		return (ERROR);
	while (argv[1][i])
	{
		j = 0;
		while (argv[1][i] == ' ')
			i++;
		len = ft_len_nbr(argv, i);
		nbr = malloc(sizeof(char) * (len + 1));
		if (argv[1][i] == '-')
		{
			i++;
			j++;
			nbr[0] = '-';
		}
		while (ft_isdigit(argv[1][i]))
		{
			nbr[j] = argv[1][i];
			j++;
			i++;
		}
		nbr[j] = '\0';
		if (ft_atoi(nbr) < INT_MIN || ft_atoi(nbr) > INT_MAX)
		{
			free(nbr);
			return (ft_free_error(info, 1));
		}
		info->pilea[h] = ft_atoi(nbr);
		h++;
		free(nbr);
	}
	return (NO_ERROR);
}

static int	ft_calcul_cmb(char **argv)
{
	int	i;
	int	check;
	int	cmb;

	i = 0;
	check = 0;
	cmb = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-')
			i++;
		while (ft_isdigit(argv[1][i]))
		{
			if (check == 0)
			{
				check++;
				cmb++;
			}
			i++;
		}
		check = 0;
		while (argv[1][i] == ' ')
			i++;
	}
	return (cmb);
}

int	ft_change_arg(t_info *info, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-')
			i++;
		if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
			return (ft_printf_error());
		i++;
	}
	info->nbr_args = ft_calcul_cmb(argv);
	if (ft_get_pile(info, argv) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
