/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:43:40 by slynell           #+#    #+#             */
/*   Updated: 2019/09/29 16:19:56 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
#include <stdio.h>

# define BUFF_SIZE 30

int				get_next_line(const int fd, char **line);

typedef struct	s_file
{
	int			fd;
	char		*lines;
	int			cur;
}				t_file;

#endif
