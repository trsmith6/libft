/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:48:31 by trsmith           #+#    #+#             */
/*   Updated: 2024/03/18 14:58:32 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	initialize(size_t *i, int *j, int *sub_str)
{
	*i = 0;
	*j = 0;
	*sub_str = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		sub_str;

	initialize(&i, &j, &sub_str);
	res = ft_calloc((ft_counter(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && sub_str < 0)
			sub_str = i;
		else if ((s[i] == c || i == ft_strlen(s)) && sub_str >= 0)
		{
			res[j] = fill_word(s, sub_str, i);
			if (!(res[j]))
				return (ft_free(res, j));
			sub_str = -1;
			j++;
		}
		i++;
	}
	return (res);
}
