/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalimov <alalimov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 23:21:26 by alalimov          #+#    #+#             */
/*   Updated: 2025/10/27 09:40:46 by alalimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **str, int j)
{
	int	k;

	k = 0;
	while (k < j)
		free(str[k++]);
	free(str);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			i++;
		}
		else
			if (*s == c)
				in_word = 0;
		s++;
	}
	return (i);
}

char	*word_dup(const char *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (0);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

int	fill_words(char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = -1;
	while (s[i])
	{
		if (s[i] != c && index < 0)
			index = i;
		if ((s[i] == c || s[i + 1] == '\0') && index >= 0)
		{
			str[j] = word_dup(s, index, i + (s[i] != c));
			if (!str[j])
			{
				free_all(str, j);
				return (0);
			}
			index = -1;
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief ft_split
 *
 * Allocates memory (using malloc(3)) and returns an 
 * array of strings obtained by splitting ’s’ using
 * the character ’c’ as a delimiter. The array must
 * end with a NULL pointer.
 *
 * @param [s]: The string to be split.
 * @param [c]: The delimiter character.
 *
 * @returns The array of new strings resulting from the split. 
 * NULL if the allocation fails.
 * @retval  an array of new strings resulting from the split.
 * @retval  NULL if the allocation fails.
 */

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (0);
	str = (char **)ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!str)
		return (0);
	if (!fill_words(str, s, c))
		return (0);
	return (str);
}
