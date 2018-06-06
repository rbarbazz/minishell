/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:21:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/18 13:27:59 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** create a new element env with key and value provided
*/

t_env	*mkenvar(t_env *env, char *key, char *value)
{
	t_env	*new;
	t_env	*tmp;

	tmp = env;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (tmp)
	{
		tmp->next = new;
		return (env);
	}
	return (new);
}

/*
** change the value of an elem
*/

void	change_value(t_env *env, char *value)
{
	ft_strdel(&env->value);
	env->value = ft_strdup(value);
}

int		ft_setenv(int i, t_sh *sh)
{
	t_env	*tmp;

	if (!sh->buf[i])
		return (env_print(sh->env));
	else if (sh->buf[i] && sh->buf[i + 1] && sh->buf[i + 2])
	{
		ft_printf("setenv: Too many arguments.\n");
		return (1);
	}
	tmp = sh->env;
	while (tmp && sh->buf[i] && ft_strcmp(sh->buf[i], tmp->key) != 0)
		tmp = tmp->next;
	if (tmp && sh->buf[i + 1])
		change_value(tmp, sh->buf[i + 1]);
	else if (tmp && !sh->buf[i + 1])
		change_value(tmp, "");
	else if (!tmp && sh->buf[i + 1])
		sh->env = mkenvar(sh->env, sh->buf[i], sh->buf[i + 1]);
	else
		sh->env = mkenvar(sh->env, sh->buf[i], "");
	return (0);
}
