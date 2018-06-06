/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:51:16 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/18 16:24:14 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lst	*buf_add(t_lst *buf, char *elem)
{
	t_lst	*new;
	t_lst	*tmp;

	tmp = buf;
	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	while (tmp && tmp->next)
		tmp = tmp->next;
	new->cont = ft_strdup(elem);
	new->next = NULL;
	if (tmp)
	{
		tmp->next = new;
		return (buf);
	}
	return (new);
}

static char		*check_dquote(char *input, int *i)
{
	char	*elem;
	int		j;

	elem = NULL;
	(*i)++;
	j = *i;
	while (input[*i] && input[*i] != 34)
		(*i)++;
	if (!input[*i])
		ft_printf("dquote> \n");
	else
		elem = dup_to_char(input + j, '\"');
	return (elem);
}

static char		*add_quoted(char *elem, char *quoted)
{
	char	*tmp;

	tmp = ft_strjoin(elem, quoted);
	ft_strdel(&elem);
	ft_strdel(&quoted);
	elem = tmp;
	return (elem);
}

static char		*check_buffer(char *input, int *i)
{
	char	*elem;
	char	*quoted;

	elem = ft_strdup("");
	while (input[*i] && (input[*i] == 32 || input[*i] == 9 || input[*i] == 10))
		(*i)++;
	while (input[*i] && input[*i] != 32 && input[*i] != 9 && input[*i] != 10)
	{
		if (input[*i] == 34)
		{
			if ((quoted = check_dquote(input, i)))
				elem = add_quoted(elem, quoted);
			else
			{
				ft_strdel(&elem);
				return (NULL);
			}
		}
		else
			elem = ft_strjoinchar(elem, input[*i]);
		(*i)++;
	}
	return (elem);
}

char			**parser(char *input)
{
	int		i;
	char	**res;
	char	*elem;
	t_lst	*buf;

	buf = NULL;
	i = 0;
	if (!input)
		return (NULL);
	while (input[i])
	{
		while (input[i] && (input[i] == 32 || input[i] == 9 || input[i] == 10))
			i++;
		if ((!buf && !input[i]) || !(elem = check_buffer(input, &i)))
		{
			free_lst_buf(buf);
			return (NULL);
		}
		buf = buf_add(buf, elem);
		ft_strdel(&elem);
	}
	res = lst_to_arr(buf);
	free_lst_buf(buf);
	return (res);
}
