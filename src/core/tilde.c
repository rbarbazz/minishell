/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:20:49 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/11 15:30:27 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*just_tilde(t_sh *sh, char **buf, int i)
{
	t_env	*tmp;
	char	*save;

	if (buf[i] && buf[i][0] && buf[i][0] == '~' && (!buf[i][1] ||\
				buf[i][1] == '/'))
	{
		tmp = sh->env;
		while (tmp && ft_strcmp("HOME", tmp->key) != 0)
			tmp = tmp->next;
		if (tmp)
		{
			save = dup_from_char(buf[i], '~');
			ft_strdel(&buf[i]);
			buf[i] = ft_strjoin(tmp->value, save);
			ft_strdel(&save);
			return (buf[i]);
		}
		else
		{
			ft_printf("minishell: HOME not set\n");
			ft_strdel(&buf[i]);
		}
	}
	return (buf[i]);
}

static char	*tilde_user(char **buf, int i)
{
	char	*usr;

	if (buf[i] && buf[i][0] && buf[i][0] == '~')
	{
		usr = ft_strdup(buf[i] + 1);
		ft_strdel(&buf[i]);
		buf[i] = ft_strjoin("/Users/", usr);
	}
	return (buf[i]);
}

char		**ft_tilde(t_sh *sh, char **buf)
{
	int	i;

	i = 0;
	while (buf && buf[i])
	{
		if (ft_strchr(buf[i], '~'))
		{
			if (!(buf[i] = just_tilde(sh, buf, i)))
			{
				strstr_free(buf);
				return (NULL);
			}
			else
				buf[i] = tilde_user(buf, i);
		}
		i++;
	}
	return (buf);
}
