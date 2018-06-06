/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:14:20 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/07 18:15:17 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_last(char *tmp, char **line, char **save)
{
	if (*tmp && ft_strchr(tmp, '\0'))
	{
		if (*save)
			*line = ft_strjoin(*save, tmp);
		else
			*line = tmp;
		ft_strdel(save);
		return (1);
	}
	else if (*save && *save[0] && ft_strchr(*save, '\0'))
	{
		*line = *save;
		ft_strdel(save);
		return (1);
	}
	ft_strdel(save);
	ft_strdel(&tmp);
	return (0);
}

static int	save_buffer(char *tmp, char **line, char **save)
{
	char	*noleak;

	noleak = dup_to_char(tmp, '\n');
	if (!*save)
		*line = ft_strdup(noleak);
	else
		*line = ft_strjoin(*save, noleak);
	ft_strdel(&noleak);
	ft_strdel(save);
	ft_strdel(&tmp);
	return (1);
}

static int	read_buffer(const int fd, char **line, char **save)
{
	char	*noleak;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		noleak = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		tmp = noleak;
		if (ft_strchr(buf, '\n'))
			return (save_buffer(tmp, line, save));
	}
	if (ret < 0)
		return (-1);
	return (check_last(tmp, line, save));
}

int			get_stdin(const int fd, char **line)
{
	static char	*save = NULL;
	char		*noleak;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (save)
	{
		if (ft_strchr(save, '\n'))
		{
			noleak = save;
			*line = dup_to_char(save, '\n');
			save = dup_from_char(save, '\n');
			ft_strdel(&noleak);
			return (1);
		}
	}
	return (read_buffer(fd, line, &save));
}
