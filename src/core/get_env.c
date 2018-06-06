/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:03:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/18 15:07:35 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*env_add(t_env *env, char *elem)
{
	t_env	*new;
	t_env	*tmp;

	tmp = env;
	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	while (tmp && tmp->next)
		tmp = tmp->next;
	new->key = dup_to_char(elem, '=');
	new->value = dup_from_char(elem, '=');
	new->next = NULL;
	if (tmp)
	{
		tmp->next = new;
		return (env);
	}
	return (new);
}

t_env	*list_env(char **environ)
{
	t_env	*env;
	int		i;

	i = 0;
	env = NULL;
	env = env_add(env, environ[i++]);
	while (environ && environ[i])
	{
		env = env_add(env, environ[i]);
		i++;
	}
	return (env);
}

char	**mkenv_strstr(t_env *env)
{
	char	**res;
	char	*save;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (!i || !(res = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	tmp = env;
	while (tmp)
	{
		save = ft_strjoin(tmp->key, "=");
		res[i++] = ft_strjoin(save, tmp->value);
		ft_strdel(&save);
		tmp = tmp->next;
	}
	res[i] = NULL;
	return (res);
}
