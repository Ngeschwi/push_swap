/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:09:36 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:32:26 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_error(void)
{
	write(1, "Error\n", 6);
	return (ERROR);
}

int	ft_free_error(t_info *info)
{
	if (info->pilea)
		free(info->pilea);
	if (info->pileb)
		free(info->pileb);
	if (info->posi_pa)
		free(info->posi_pa);
	if (info->posi_pb)
		free(info->posi_pb);
	return (ft_printf_error());
}

int	ft_check_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		return (ERROR);
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' && argv[i][1])
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_printf_error());
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

int	ft_check_double(t_info *info, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (info->pilea[i] == info->pilea[j])
			return (ft_free_error(info));
		j++;
	}
	return (NO_ERROR);
}
