/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynell <slynell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:43:40 by slynell           #+#    #+#             */
/*   Updated: 2019/09/29 16:21:06 by slynell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			check_n(char *str)
{
	int				i;

	i = 0;
	while(*(str + i))
		if(*(str + i++) == '\n')
			return (i);
	return (-1);
}

static char			*read_file(int fd, char *str, int *cur, int *status)
{
	char			buf[BUFF_SIZE + 1];
	size_t			ret;
	char			*temp;

	temp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		if (check_n(str) != -1)
			break;
	}
	*status = ret;
	*cur = (check_n(str));
	return (str + check_n(str));
}

static t_list		*find_file(t_list **lst, int fd)
{
	t_list			*file;
	file = *lst;
	while (file)
	{
		if (((t_file*)((file->content)))->fd == fd)
			return (file);
		file = file->next;
	}
	return (NULL);
}

static t_list		*add_file(t_list **lst, int fd)
{
	t_file			f;

	f.fd = fd;
	f.lines = "";
	f.cur = 0;
	ft_lstadd((lst), ft_lstnew((void*)&f, sizeof(t_file)));
	return (*lst);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	t_list			*temp;
	static t_list	*files = NULL;
	int				i;
	int				status;
	char			*sr;
	temp = find_file(&files, fd);

	if (temp == NULL)
	{
		if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0) || BUFF_SIZE < 1)
			return (-1);
		temp = add_file(&files, fd);
	}
	((t_file*)(temp->content))->lines = read_file(((t_file*)(temp->content))->fd, \
	((t_file*)(temp->content))->lines, \
	&((t_file*)(temp->content))->cur, &status);
	if (status == 0)
		return (0);
	i = ((t_file*)(temp->content))->cur;
	sr = ft_strnew(i);
	
	while (i > 0)
		*sr++ =  *(((t_file*)(temp->content))->lines - i--);
	*line = sr - ((t_file*)(temp->content))->cur;
	return (1);
}
