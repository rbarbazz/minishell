/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:10:43 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/03/28 17:23:40 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str)
{
	int wc;
	int i;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == 9 || str[i] == 10)
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 10)
			i++;
	}
	return (wc);
}

static char	**copy(char **res, const char *str, int wc)
{
	int i;
	int wn;
	int cn;

	wn = 0;
	i = 0;
	while (wn < wc)
	{
		cn = 0;
		if (!(res[wn] = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (NULL);
		while (str[i] == 32 || str[i] == 9 || str[i] == 10)
			i++;
		while (str[i] && str[i] != 32 && str[i] != 9 && str[i] != 10)
		{
			res[wn][cn] = str[i];
			i++;
			cn++;
		}
		res[wn][cn] = '\0';
		wn++;
	}
	res[wn] = NULL;
	return (res);
}

char		**ft_strsplit_whitespace(const char *str)
{
	char	**res;
	int		wc;

	wc = count_words(str);
	if (!str || !wc || !(res = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	res = copy(res, str, wc);
	return (res);
}
