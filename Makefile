# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 10:16:43 by ngeschwi          #+#    #+#              #
#    Updated: 2021/06/08 14:55:58 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= sources/main.c \
			sources/push_swap.c \
			sources/ft_push_b.c \
			sources/ft_push_a.c \
			sources/ft_intdup.c \
			sources/ft_error.c \
			sources/ft_ope_a.c \
			sources/ft_ope_b.c \
			sources/ft_ope_ab.c \
			sources/ft_ope_a_posi.c \
			sources/ft_ope_b_posi.c \
			sources/ft_atoi.c \
			sources/ft_strlen.c \
			sources/ft_isdigit.c \
			sources/ft_putstr.c
			

BONUS	= sources/main_checker.c \
			sources/ft_intdup.c \
			sources/get_next_line.c \
			sources/get_next_line_utils.c \
			sources/ft_compare.c \
			sources/ft_error.c \
			sources/ft_ope_a.c \
			sources/ft_ope_b.c \
			sources/ft_ope_ab.c \
			sources/ft_ope_a_posi.c \
			sources/ft_ope_b_posi.c \
			sources/ft_atoi.c \
			sources/ft_strlen.c \
			sources/ft_isdigit.c \
			sources/ft_putstr.c

NBR_GEN	= sources/main_generete.c \
			sources/push_swap.c \
			sources/push_swap_gen.c \
			sources/ft_push_b.c \
			sources/ft_push_a.c \
			sources/ft_intdup.c \
			sources/ft_error.c \
			sources/ft_ope_a.c \
			sources/ft_ope_b.c \
			sources/ft_ope_ab.c \
			sources/ft_ope_a_posi.c \
			sources/ft_ope_b_posi.c \
			sources/ft_atoi.c \
			sources/ft_strlen.c \
			sources/ft_isdigit.c \
			sources/ft_putstr.c

OBJS	= $(SRCS:.c=.o)

OBJSBNS	= $(BONUS:.c=.o)

OBJSGEN	= $(NBR_GEN:.c=.o)

NAME	= push_swap

NAMEBNS	= checker

NAMEGEN	= generateur

CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Werror -Wextra -g

%.o : %.c
	${CC} ${CFLAGS} -I./includes -o $@ -c $<

$(NAME):	$(OBJS)
		${CC} ${CFLAGS} $(OBJS) -o $(NAME)
		
$(NAMEBNS):	$(OBJSBNS)
		${CC} ${CFLAGS} $(OBJSBNS) -o $(NAMEBNS)

$(NAMEGEN):	$(OBJSGEN)
		${CC} ${CFLAGS} $(OBJSGEN) -o $(NAMEGEN)

$(OBJS):	includes/push_swap.h

$(OBJSBNS):	includes/get_next_line.h includes/push_swap.h

$(OBJSGEN):	includes/get_next_line.h includes/push_swap.h

all:		$(NAME) $(NAMEBNS) $(NAMEGEN)

clean:
		$(RM) $(OBJS) 
		$(RM) $(OBJSBNS)
		$(RM) $(OBJSGEN)

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAMEBNS)
		$(RM) $(NAMEGEN)

re:			fclean $(NAME) $(NAMEBNS) $(NAMEGEN)

.PHONY:		all clean fclean re