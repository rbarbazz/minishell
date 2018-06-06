/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:02:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/13 16:56:38 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char *s1, char const c)
{
	char	add[2];
	char	*result;

	add[0] = c;
	add[1] = '\0';
	result = ft_strjoin(s1, add);
	ft_strdel(&s1);
	return (result);
}
