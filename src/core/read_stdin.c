/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:32:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/18 15:55:04 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_sh(t_sh *sh)
{
	if (sh->env_tmp)
		free_env(sh->env_tmp);
	sh->env_tmp = NULL;
	sh->buf = NULL;
	sh->buf_cpy = NULL;
	sh->ret = 0;
	sh->i = 0;
}

void		command_not_found(t_sh *sh, int i)
{
	sh->ret = 127;
	ft_printf("minishell: command not found: %s\n", sh->buf[i]);
}

void		read_stdin(t_sh *sh)
{
	char	*buf;

	buf = NULL;
	while (get_stdin(0, &buf) == 1)
	{
		init_sh(sh);
		if ((sh->buf = parser(buf)))
			sh->buf_cpy = ft_strstrdup(sh->buf);
		ft_strdel(&buf);
		if ((sh->buf = ft_tilde(sh, sh->buf)))
			if (check_builtins(0, sh))
				if (ft_binaries(sh))
					command_not_found(sh, 0);
		if (sh->buf)
			strstr_free(sh->buf);
		if (sh->buf_cpy)
			strstr_free(sh->buf_cpy);
		display_prompt(sh);
	}
}
