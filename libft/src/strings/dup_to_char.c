/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:47:59 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/07 11:13:39 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*dup_to_char(char *str, char c)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (dst = ft_strdup(str));
	if (!(dst = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	j = i;
	i = 0;
	while (i != j)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
