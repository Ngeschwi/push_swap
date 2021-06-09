/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:40:06 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 12:40:06 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>

# define BUFFER_SIZE 1024 

# define NO_NL -1

int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, int start, int len);
char		*ft_strjoin(char **str, char *buff);
void		ft_free_if_define(char **str);

#endif
