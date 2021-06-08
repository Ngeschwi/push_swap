/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:20:31 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/08 17:02:49 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_intdup(int *src, int len)
{
	int	*dst;
	int	i;

	i = 0;
	if (!src || len == 0)
	{
		dst = malloc(sizeof(int *) * 1);
		dst[0] = '\0';
		return (dst);
	}
	dst = malloc(sizeof(int *) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (len != 0)
		dst[i] = '\0';
	return (dst);
}
