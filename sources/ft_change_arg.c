/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:49:08 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:21:36 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_change_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' ')
			return (ft_printf_error());
		i++;
	}
	return (NO_ERROR);
}
