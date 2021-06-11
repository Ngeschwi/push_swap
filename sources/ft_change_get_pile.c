/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_get_pile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:43:52 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 12:50:37 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_get_nbr(char **argv, char **nbr, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_len_nbr(argv, i);
	*nbr = malloc(sizeof(char) * (len + 1));
	if (argv[1][i] == '-')
	{
		i++;
		j++;
		(*nbr)[0] = '-';
	}
	while (ft_isdigit(argv[1][i]))
	{
		(*nbr)[j] = argv[1][i];
		j++;
		i++;
	}
	(*nbr)[j] = '\0';
	return (i);
}
