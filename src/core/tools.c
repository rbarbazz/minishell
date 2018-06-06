/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:23:34 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/18 16:24:05 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**lst_to_arr(t_lst *buf)
{
	t_lst	*tmp;
	int		i;
	char	**res;

	i = 0;
	tmp = buf;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!buf || !(res = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	tmp = buf;
	i = 0;
	while (tmp)
	{
		res[i] = ft_strdup(tmp->cont);
		i++;
		tmp = tmp->next;
	}
	res[i] = NULL;
	return (res);
}
