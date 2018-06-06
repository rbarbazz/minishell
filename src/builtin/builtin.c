/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:00:17 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/11 12:59:21 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtins(int i, t_sh *sh)
{
	if (!ft_strcmp(sh->buf[i], "exit"))
		ft_exit(++i, sh);
	else if (!ft_strcmp(sh->buf[i], "echo"))
		sh->ret = ft_echo(++i, sh);
	else if (!ft_strcmp(sh->buf[i], "cd"))
		sh->ret = ft_cd(++i, sh);
	else if (!ft_strcmp(sh->buf[i], "setenv"))
		sh->ret = ft_setenv(++i, sh);
	else if (!ft_strcmp(sh->buf[i], "unsetenv"))
		sh->ret = ft_unsetenv(++i, sh);
	else if (!ft_strcmp(sh->buf[i], "env"))
		sh->ret = ft_env(++i, sh);
	else
		return (1);
	return (0);
}
