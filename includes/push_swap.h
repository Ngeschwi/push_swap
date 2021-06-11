/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 13:34:16 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 12:50:11 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_info
{
	int		*pilea;
	int		*pileb;
	int		*posi_pa;
	int		*posi_pb;
	int		nbr_pa;
	int		nbr_pb;
	int		nbr_args;
	int		nbr_div;
	int		max;
	int		min;
	int		index;
	int		count_move;
	int		what;
}			t_info;

# define ERROR -1
# define NO_ERROR 1
# define SORTED 1
# define NO_SORTED -1
# define FIRST_TIME 1
# define OTHER_TIME -1
# define SAME 1
# define NOT_SAME -1
# define END 1
# define PUSH 2
# define CHECKER 1
# define GEN 0
# define OK 2
# define INT_MIN -2147483648
# define INT_MAX 2147483647

void		push_swap(t_info *info);
int			ft_error(t_info *info, int argc, char **argv);
int			ft_change_arg(t_info *info, char **argv);
int			ft_get_nbr(char **argv, char **nbr, int i);
int			ft_check_int(int argc, char **argv);
int			ft_check_double(t_info *info);
int			ft_printf_error(void);
int			ft_free_error(t_info *info, int i);
void		ft_free_define(char **line);
int			ft_get_posi_pa(t_info *info);
void		ft_push_a(t_info *info);
void		ft_push_b(t_info *info);

void		ft_sa(t_info *info);
void		ft_sb(t_info *info);
void		ft_ss(t_info *info);
void		ft_pa(t_info *info);
void		ft_pb(t_info *info);
void		ft_ra(t_info *info);
void		ft_rb(t_info *info);
void		ft_rr(t_info *info);
void		ft_rra(t_info *info);
void		ft_rrb(t_info *info);
void		ft_rrr(t_info *info);

void		ft_sa_posi(t_info *info);
void		ft_sb_posi(t_info *info);
void		ft_ss_posi(t_info *info);
void		ft_pa_posi(t_info *info);
void		ft_pb_posi(t_info *info);
void		ft_ra_posi(t_info *info);
void		ft_rb_posi(t_info *info);
void		ft_rr_posi(t_info *info);
void		ft_rra_posi(t_info *info);
void		ft_rrb_posi(t_info *info);
void		ft_rrr_posi(t_info *info);

int			ft_strlen(const char *str);
void		ft_putstr(char *str, t_info *info);
void		ft_putnbr(int n);
int			ft_isdigit(int c);
long int	ft_atoi(char *str);
int			*ft_intdup(int *src, int len);
int			ft_compare(char *line, t_info *info);

int			push_swap_gen(int cmb, int *tab);

#endif