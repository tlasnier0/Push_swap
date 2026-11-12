/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noclemen <noclemen@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:10:17 by noclemen          #+#    #+#             */
/*   Updated: 2026/11/05 22:16:09 by noclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*copy_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = count_word_len(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_tab(char **tab, int j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
}

char	**ft_split(const char *s, char c)
{
	int		nb_words;
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			tab[j] = copy_word(&s[i], c);
			if (!tab[j])
				return (free_tab(tab, j), NULL);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
