/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:15:52 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/11 09:21:29 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	if (!dst && !src)
	{
		return (0);
	}
	ret = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
		{
			*(char *)--dst = *(char *)--src;
		}
	}
	else
	{
		while (len--)
		{
			*(char *)dst++ = *(char *)src++;
		}
	}
	return (ret);
}
