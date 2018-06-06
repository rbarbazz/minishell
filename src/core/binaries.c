/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:40:08 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/08 12:22:01 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_path(t_env *env, char *exe)
{
	t_env	*tmp;
	char	**path;
	char	*save;
	int		i;

	i = 0;
	tmp = env;
	while (tmp && ft_strcmp("PATH", tmp->key) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	path = ft_strsplit(tmp->value, ':');
	while (path && path[i])
	{
		save = ft_strjoinchar(path[i], '/');
		path[i] = ft_strjoin(save, exe);
		ft_strdel(&save);
		i++;
	}
	return (path);
}

int			exec_binaries(t_sh *sh, char **env, char **path, char **argv)
{
	int		i;
	int		shi;
	int		status;
	pid_t	pid;

	i = 0;
	shi = sh->i;
	if ((pid = fork()) < 0)
		return (1);
	else if (!pid)
	{
		if (execve(sh->buf[shi], argv, env) == -1)
			while (path && path[i])
				execve(path[i++], argv, env);
		exit(INVALID_CMD);
	}
	else
		waitpid(pid, &status, 0);
	strstr_free(env);
	return (free_path(path, status, sh));
}

int			ft_binaries(t_sh *sh)
{
	char	**env;
	char	**path;

	env = mkenv_strstr(sh->env);
	path = get_path(sh->env, sh->buf[0]);
	return (exec_binaries(sh, env, path, sh->buf));
}
