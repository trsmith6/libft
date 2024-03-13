/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:45:38 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/13 09:56:55 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			a = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		a = (char *)s;
	}
	return (a);
}
