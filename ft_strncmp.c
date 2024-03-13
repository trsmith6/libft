/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:03:00 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/13 09:27:45 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (s1[i] && i < n)
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (ret != 0)
		{
			return (ret);
		}
		else
		{
			i++;
		}
	}
	if (s2[i] && i < n)
	{
		ret = - (unsigned char)s2[i];
	}
	return (ret);
}
