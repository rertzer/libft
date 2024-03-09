/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:14:37 by rertzer           #+#    #+#             */
/*   Updated: 2024/03/09 10:01:42 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c);
static char	*str_malloc_copy(const char *src, int l);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**splited;

	k = word_count(s, c);
	splited = malloc(sizeof (char *) * (k + 1));
	if (! splited)
		return (NULL);
	splited[k] = NULL;
	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			k = i;
			while (s[i] && s[i] != c)
				i++;
			splited[++j] = strlm(&s[k], i - k);
		}
	}
	return (splited);
}

static int	word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*str_malloc_copy(const char *src, int l)
{
	int		i;
	char	*cpy;

	cpy = malloc(sizeof (char) * (l + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}


