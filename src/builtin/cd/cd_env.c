/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:51:30 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/04 15:22:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** all the functions below modify or check for env variables when cd is called
*/

void	mk_old_pwd(t_sh *sh)
{
	t_env	*tmp;
	char	*cwd;

	tmp = sh->env;
	cwd = NULL;
	while (tmp && ft_strcmp("PWD", tmp->key) != 0)
		tmp = tmp->next;
	if (tmp)
		cwd = ft_strdup(tmp->value);
	else
		cwd = getcwd(cwd, MAXPATHLEN);
	tmp = sh->env;
	while (tmp && ft_strcmp("OLDPWD", tmp->key) != 0)
		tmp = tmp->next;
	if (!tmp)
		sh->env = mkenvar(sh->env, "OLDPWD", cwd);
	else
	{
		ft_strdel(&tmp->value);
		tmp->value = ft_strdup(cwd);
	}
	ft_strdel(&cwd);
}

void	mk_new_pwd(t_sh *sh, int hyphen)
{
	t_env	*tmp;
	char	*cwd;

	tmp = sh->env;
	cwd = NULL;
	while (tmp && ft_strcmp("PWD", tmp->key) != 0)
		tmp = tmp->next;
	cwd = getcwd(cwd, MAXPATHLEN);
	if (!tmp)
		sh->env = mkenvar(sh->env, "PWD", cwd);
	else
	{
		ft_strdel(&tmp->value);
		tmp->value = ft_strdup(cwd);
	}
	if (hyphen)
		ft_printf("%s\n", cwd);
	ft_strdel(&cwd);
}

char	*cd_home(t_sh *sh)
{
	t_env	*tmp;

	tmp = sh->env;
	while (tmp && ft_strcmp("HOME", tmp->key) != 0)
		tmp = tmp->next;
	if (tmp)
		return (tmp->value);
	else
		ft_printf("minishell: cd: HOME not set\n");
	return (NULL);
}

char	*cd_oldpwd(t_sh *sh, int *hyphen)
{
	t_env	*tmp;

	tmp = sh->env;
	while (tmp && ft_strcmp(tmp->key, "OLDPWD") != 0)
		tmp = tmp->next;
	if (tmp)
	{
		*hyphen = 1;
		return (tmp->value);
	}
	else
		ft_printf("minishell: cd: OLDPWD not set\n");
	return (NULL);
}
