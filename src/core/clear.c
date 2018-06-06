/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:36:11 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/15 19:56:33 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lst_buf(t_lst *buf)
{
	t_lst	*tmp;

	while (buf)
	{
		tmp = buf;
		buf = buf->next;
		ft_strdel(&tmp->cont);
		ft_memdel((void**)&tmp);
	}
}

/*
** frees the structure before exit
*/

void	free_sh(t_sh *sh)
{
	if (sh)
	{
		strstr_free(sh->buf);
		strstr_free(sh->buf_cpy);
		free_env(sh->env);
		sh->env = NULL;
		free_env(sh->env_tmp);
		sh->env_tmp = NULL;
		ft_memdel((void**)&sh);
	}
}

/*
** frees the path end returns the exit status
*/

int		free_path(char **path, int status, t_sh *sh)
{
	if (path)
		strstr_free(path);
	if (WEXITSTATUS(status) != INVALID_CMD)
	{
		sh->ret = WEXITSTATUS(status);
		return (0);
	}
	return (1);
}

/*
** frees an env list
*/

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		ft_strdel(&tmp->key);
		ft_strdel(&tmp->value);
		ft_memdel((void**)&tmp);
	}
}
