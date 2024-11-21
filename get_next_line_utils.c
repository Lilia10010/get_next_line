/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:53:38 by lpaula-n          #+#    #+#             */
/*   Updated: 2024/11/20 00:51:55 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	len_s1 = -1;
	while (s1[++len_s1])
		join[len_s1] = s1[len_s1];
	len_s2 = -1;
	while (s2[++len_s2])
		join[len_s1 + len_s2] = s2[len_s2];
	join[len_s1 + len_s2] = '\0';
	return (join);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	length;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	length = -1;
	while (str[++length])
		copy[length] = str[length];
	copy[length] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}