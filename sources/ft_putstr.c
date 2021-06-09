/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:27:27 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:39:12 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str, t_info *info)
{
	int	i;

	i = 0;
	if (info->what == PUSH)
	{
		while (str[i])
		{
			write(1, str + i, 1);
			i++;
		}
	}
	info->count_move++;
}
