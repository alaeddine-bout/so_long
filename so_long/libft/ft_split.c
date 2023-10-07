/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: about <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:33:28 by about             #+#    #+#             */
/*   Updated: 2022/11/01 15:05:07 by about            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_start(const char *str, char c, size_t i)
{
	while (str[i] == c)
		i++;
	return (i);
}

static int	ft_word_count(const char *str, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] && str[i] != c)
			i++;
		count++;
	}
	return (count);
}

static int	ft_len(const char *str, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_free(char **str, size_t i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	str = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!str || !ft_word_count(s, c))
		return (str);
	start = 0;
	len = 0;
	while (start + len < ft_strlen(s))
	{
		start = ft_start(s, c, start + len);
		len = ft_len(s, c, start);
		if (len == 0)
			break ;
		str[i] = ft_substr(s, start, len);
		if (!str[i])
			return (ft_free(str, i - 1));
		i++;
	}
	return (str);
}
