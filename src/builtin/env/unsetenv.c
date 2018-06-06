/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:35:43 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/04 15:29:07 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unsetenv_error(t_sh *sh)
{
	if (!sh->buf[1])
	{
		ft_printf("unsetenv: Too few arguments.\n");
		return (1);
	}
	return (0);
}

static void	del_envar(t_env *tmp)
{
	t_env	*swp;

	swp = tmp->next;
	ft_strdel(&tmp->next->value);
	ft_strdel(&tmp->next->key);
	if (tmp->next->next)
		tmp->next = tmp->next->next;
	else
		tmp->next = NULL;
	ft_memdel((void**)&swp);
}

int			ft_unsetenv(int i, t_sh *sh)
{
	t_env	*tmp;

	if (unsetenv_error(sh))
		return (1);
	while (sh->buf[i])
	{
		tmp = sh->env;
		while (tmp->next && ft_strcmp(tmp->next->key, sh->buf[i]) != 0)
			tmp = tmp->next;
		if (tmp->next)
			del_envar(tmp);
		i++;
	}
	return (0);
}
