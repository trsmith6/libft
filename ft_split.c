/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:48:31 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/12 14:47:54 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *str, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

static char	*ft_dupe(const char *src, int n)
{
	char	*s;

	s = (char *) malloc(sizeof(char) * (n + 1));
	if (!s || !src)
		return (0);
	s = (char *) ft_memcpy(s, src, n);
	s[n] = '\0';
	return (s);
}

static void	*ft_free_all(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (list);
}

static void	ft_loop_split(const char *s, char c, char **list)
{
	int		i;
	int		last_sp;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		last_sp = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > last_sp)
		{
			list[n] = ft_dupe(&s[last_sp], (i - last_sp));
			if (! list[n])
				ft_free_all(list);
			n++;
		}
	}
	list[n] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**list;

	list = (char **) malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!list || !s)
		return (0);
	ft_loop_split(s, c, list);
	return (list);
}
