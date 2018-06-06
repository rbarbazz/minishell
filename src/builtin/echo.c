/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:14:14 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/04 15:16:46 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(int i, t_sh *sh)
{
	int	tmp;

	tmp = i;
	if (sh->buf[i] && !ft_strcmp(sh->buf[i], "-n"))
		i++;
	while (sh->buf[i])
	{
		ft_printf("%s", sh->buf[i++]);
		if (sh->buf[i])
			ft_printf(" ");
	}
	if ((sh->buf[tmp] && ft_strcmp(sh->buf[tmp], "-n")) != 0 || !sh->buf[tmp])
		ft_printf("\n");
	return (0);
}
