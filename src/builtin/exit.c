/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:57:15 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/11 15:49:15 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exit(int i, t_sh *sh)
{
	int	ret;

	ret = 0;
	if (sh->buf[i] && sh->buf[i + 1])
	{
		ft_printf("exit: too many arguments\n");
		return ;
	}
	if (sh->buf[i])
		ret = ft_atoi(sh->buf[i]);
	free_sh(sh);
	exit(ret);
}
