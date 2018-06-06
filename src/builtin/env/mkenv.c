/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkenv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:32:56 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/05 14:41:38 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** check if a key already exists
** if so, just change the value
*/

static int	key_exist(t_env *env, char *elem)
{
	t_env	*tmp;
	char	*key;
	char	*value;

	key = dup_to_char(elem, '=');
	tmp = env;
	while (tmp && ft_strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	ft_strdel(&key);
	if (tmp)
	{
		value = dup_from_char(elem, '=');
		change_value(tmp, value);
		ft_strdel(&value);
		return (1);
	}
	return (0);
}

t_env		*clone_lst(t_env *e1, t_env *e2)
{
	t_env	*tmp;

	tmp = e1;
	while (tmp)
	{
		e2 = mkenvar(e2, tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (e2);
}

/*
** make the temp env to be used with the env command
** if no opt, calls clone_lst to first get a copy of the env
** then adds input values
*/

t_env		*mkenv_env(t_sh *sh, int *i)
{
	if (sh->env_opt)
	{
		free_env(sh->env);
		sh->env = NULL;
	}
	while (sh->buf[*i] && ft_strchr(sh->buf[*i], '='))
	{
		if (!key_exist(sh->env, sh->buf[*i]))
			sh->env = env_add(sh->env, sh->buf[*i]);
		(*i)++;
	}
	return (sh->env);
}
