/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 00:33:23 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/11 15:38:57 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** print the env : key=value
*/

int			env_print(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && tmp->key && tmp->value)
	{
		ft_printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

/*
** check for option -i
** -- handled
*/

static int	check_opt(t_sh *sh, int *i)
{
	int	j;

	while (sh->buf[*i])
	{
		j = 1;
		if (sh->buf[*i][0] == '-')
		{
			if (sh->buf[*i][1] == '-' && !sh->buf[*i][2] && (*i)++)
				return (0);
			while (sh->buf[*i][j] && sh->buf[*i][j] == 'i' && j++)
				sh->env_opt = 1;
			if (sh->buf[*i][j])
				return (ft_printf("env: illegal option -- %c\nusage: env [-i] \
[name=value]... [utility [argument...]]\n", sh->buf[*i][j]));
		}
		else
			break ;
		(*i)++;
	}
	return (0);
}

static int	opt_and_env(t_sh *sh, int *i)
{
	sh->env_opt = 0;
	if (check_opt(sh, i))
		return (1);
	if (!sh->env_tmp)
		sh->env_tmp = clone_lst(sh->env, sh->env_tmp);
	sh->env = mkenv_env(sh, i);
	return (0);
}

int			ft_env(int i, t_sh *sh)
{
	char	**envtmp;
	char	**path;

	if (opt_and_env(sh, &i))
		return (1);
	if ((sh->buf_cpy = ft_tilde(sh, sh->buf_cpy)))
	{
		strstr_free(sh->buf);
		sh->buf = ft_strstrdup(sh->buf_cpy);
		if (!sh->buf[i])
			env_print(sh->env);
		else if (check_builtins(i, sh))
		{
			envtmp = mkenv_strstr(sh->env);
			path = get_path(sh->env, sh->buf[i]);
			sh->i = i;
			if (exec_binaries(sh, envtmp, path, sh->buf + i))
				command_not_found(sh, i);
		}
	}
	free_env(sh->env);
	sh->env = NULL;
	sh->env = clone_lst(sh->env_tmp, sh->env);
	return (0);
}
