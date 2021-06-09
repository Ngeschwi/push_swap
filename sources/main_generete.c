/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_generete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:45:40 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:39:34 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_generete(int max, int cmb, int **tab)
{
	int	i;
	int	x;
	int	nbr;

	i = 0;
	while (i < cmb)
	{
		x = 0;
		nbr = rand() % max + 1;
		if (rand() % 2 + 1 == 2)
			nbr = -nbr;
		while (x < i)
		{
			if ((*tab)[x] == nbr)
			{
				nbr = rand() % max + 1;
				x = 0;
			}
			x++;
		}
		(*tab)[i] = nbr;
		i++;
	}
	(*tab)[i] = '\0';
}

static int	ft_get_tab(int max, int cmb, int times)
{
	int	i;
	int	*tab_moy;
	int	*tab;
	int	moyenne;

	i = -1;
	moyenne = 0;
	tab_moy = malloc(sizeof(int *) * (times + 1));
	while (++i < times)
	{
		tab = malloc(sizeof(int *) * (cmb + 1));
		if (2 * max < cmb)
			return (0);
		else
			ft_generete(max, cmb, &tab);
		tab_moy[i] = push_swap_gen(cmb, tab);
		free(tab);
	}
	tab_moy[i] = '\0';
	i = -1;
	while (tab_moy[++i])
		moyenne = moyenne + tab_moy[i];
	moyenne = moyenne / times;
	free(tab_moy);
	return (moyenne);
}

int	main(int argc, char **argv)
{
	int	max;
	int	cmb;
	int	times;
	int	moyenne;

	if (argc == 4)
	{
		max = ft_atoi(argv[1]);
		cmb = ft_atoi(argv[2]);
		times = ft_atoi(argv[3]);
		moyenne = ft_get_tab(max, cmb, times);
		printf("Pour %d tableaux avec %d entiers, ", times, cmb);
		printf("compris entre %d et %d\n", max, -max);
		printf("Nous avons en moyenne %d mouvements", moyenne);
	}
	return (0);
}
