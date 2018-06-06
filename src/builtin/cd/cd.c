/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:57:43 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/11 16:23:36 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	parsing_options(t_sh *sh, int i, int *bigp)
{
	int	j;

	while (sh->buf[i])
	{
		j = 1;
		if (!sh->buf[i][j])
			return (i);
		while (sh->buf[i][j] && sh->buf[i][0] == '-')
		{
			if (sh->buf[i][0] == '-' && sh->buf[i][1] == '-' &&\
					!sh->buf[i][2])
				return (++i);
			if (sh->buf[i][j] == 'P')
				*bigp = 1;
			else if (sh->buf[i][j] == 'L')
				*bigp = 0;
			else
				return (i);
			j++;
		}
		if (sh->buf[i][0] != '-')
			return (i);
		i++;
	}
	return (i);
}

static int	cd_error(t_sh *sh, char *arg, int i)
{
	DIR	*currdir;

	currdir = opendir(arg);
	if (sh->buf[i] && sh->buf[i + 1])
		ft_printf("cd: string not in pwd: %s\n", sh->buf[i]);
	else if ((access(arg, F_OK)) != 0)
		ft_printf("cd: no such file or directory: %s\n", arg);
	else if ((access(arg, X_OK)) != 0)
		ft_printf("cd: permission denied: %s\n", arg);
	else if (!currdir)
		ft_printf("cd: not a directory: %s\n", arg);
	else
	{
		if (currdir)
			closedir(currdir);
		return (0);
	}
	if (currdir)
		closedir(currdir);
	return (1);
}

/*
** gets the path aimed for by user(no args, hyphen or args)
*/

static char	*get_curpath(t_sh *sh, int i, int *hyphen)
{
	t_env	*tmp;

	tmp = sh->env;
	if (!sh->buf[i])
		return (cd_home(sh));
	else if (!ft_strcmp(sh->buf[i], "-"))
		return (cd_oldpwd(sh, hyphen));
	else
		return (sh->buf[i]);
}

int			ft_cd(int i, t_sh *sh)
{
	int		bigp;
	int		hyphen;
	char	*curpath;

	bigp = 0;
	hyphen = 0;
	if (sh->buf[i])
		i = parsing_options(sh, i, &bigp);
	if (!(curpath = get_curpath(sh, i, &hyphen)) || cd_error(sh, curpath, i) ||\
			(chdir(curpath) < 0))
		return (1);
	mk_old_pwd(sh);
	mk_new_pwd(sh, hyphen);
	return (0);
}
