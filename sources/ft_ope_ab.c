/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:32:58 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:38:56 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_info *info)
{
	ft_sa(info);
	ft_sb(info);
	if (info->what == PUSH || info->what == GEN)
	{
		ft_sa_posi(info);
		ft_sb_posi(info);
	}
}

void	ft_rr(t_info *info)
{
	ft_ra(info);
	ft_rb(info);
	if (info->what == PUSH || info->what == GEN)
	{
		ft_ra_posi(info);
		ft_rb_posi(info);
	}
}

void	ft_rrr(t_info *info)
{
	ft_rra(info);
	ft_rrb(info);
	if (info->what == PUSH || info->what == GEN)
	{
		ft_rra_posi(info);
		ft_rrb_posi(info);
	}
}
