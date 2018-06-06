/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:23:09 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/01 14:38:22 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*usr_prompt(t_sh *sh, char *pwd)
{
	t_env	*tmp;
	char	*usr;
	char	*prompt;

	tmp = sh->env;
	while (tmp && ft_strcmp("USER", tmp->key) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (pwd);
	else
	{
		usr = ft_strdup(tmp->value);
		usr = ft_strjoinchar(usr, ' ');
		prompt = ft_strjoin(usr, pwd);
		ft_strdel(&pwd);
		ft_strdel(&usr);
	}
	return (prompt);
}

static char	*pwd_prompt(t_sh *sh)
{
	t_env	*tmp;
	char	*pwd;
	char	*save;

	tmp = sh->env;
	while (tmp && ft_strcmp("PWD", tmp->key) != 0)
		tmp = tmp->next;
	if (!tmp)
		pwd = ft_strdup("% ");
	else
	{
		save = ft_strdup(tmp->value);
		pwd = ft_strjoin(save, " % ");
		ft_strdel(&save);
	}
	return (pwd);
}

void		display_prompt(t_sh *sh)
{
	char	*prompt;
	char	*pwd;

	pwd = pwd_prompt(sh);
	prompt = usr_prompt(sh, pwd);
	ft_printf("%s", prompt);
	ft_strdel(&prompt);
}
