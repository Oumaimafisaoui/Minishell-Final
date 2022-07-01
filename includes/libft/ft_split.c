/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufisaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:30:00 by oufisaou          #+#    #+#             */
/*   Updated: 2021/11/18 18:26:22 by oufisaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_num(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			counter++;
		while (*s && *s != c)
			s++;
	}
	return (counter);
}

static char	**ft_freed(char **sentence, int n)
{
	while (n--)
		free(sentence[n]);
	free(sentence);
	return (NULL);
}

static char	*char_alloc(char const *s, char c)
{
	int		character;
	char	*word;

	character = 0;
	while (s[character] && s[character] != c)
		character++;
	word = (char *)malloc(sizeof(char) * (character + 1));
	if (word)
	{
		ft_strlcpy(word, s, character + 1);
		return (word);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**sentence;
	int		i;
	int		len_s;

	if (s)
	{
		len_s = words_num(s, c);
		sentence = (char **)malloc(sizeof(char *) * (len_s + 1));
		if (sentence)
		{
			i = -1;
			while (++i < len_s)
			{
				while (*s == c)
					s++;
				sentence[i] = char_alloc(s, c);
				if (!sentence[i])
					ft_freed(sentence, i);
				s = s + ft_strlen(sentence[i]);
			}
			sentence[i] = 0;
			return (sentence);
		}
	}
	return (NULL);
}
