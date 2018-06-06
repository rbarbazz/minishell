/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:23:43 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/13 11:13:06 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Bonus :
** -prompt displays username and pwd
*/

static t_sh	*save_env(t_sh *sh, char **environ)
{
	sh->env_tmp = NULL;
	if (environ && environ[0])
		sh->env = list_env(environ);
	else
		sh->env = NULL;
	return (sh);
}

int			main(int argc, char **argv, char **environ)
{
	t_sh	*sh;

	if (!(sh = (t_sh*)malloc(sizeof(t_sh))))
		return (1);
	if (argc != 1 || argv[1] || clrscr() < 0)
		return (-1);
	sh = save_env(sh, environ);
	display_prompt(sh);
	read_stdin(sh);
	return (0);
}
