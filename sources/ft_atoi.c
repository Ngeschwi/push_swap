/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:31:48 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:38:36 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	long int	total;
	int			nbr_less;
	int			i;
	int			len;

	i = 0;
	total = 0;
	nbr_less = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		nbr_less = -1;
		i++;
	}
	while (i < len)
	{
		total = total * 10;
		total = total + (str[i] - '0');
		i++;
	}
	return (total * nbr_less);
}
