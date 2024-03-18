/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:17:06 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/18 11:28:03 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s_len;

	if (s == NULL)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if ((size_t)start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > (s_len - start))
	{
		len = s_len - start;
	}
	s2 = (char *)malloc(len + 1);
	if (!s2)
	{
		return (NULL);
	}
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}
