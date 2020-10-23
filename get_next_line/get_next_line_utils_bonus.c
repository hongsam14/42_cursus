/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:41:14 by suhong            #+#    #+#             */
/*   Updated: 2020/10/23 16:26:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t				gnl_strlen(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*gnl_strchr(const char *s, int c)
{
	char			*p;

	if (s == 0)
		return (0);
	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (c == 0)
		return (p);
	return (0);
}

char				*gnl_strjoin(char const *s1, char const *s2)
{
	size_t			s1_size;
	size_t			s2_size;
	char			*tmp;
	size_t			i;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_size = gnl_strlen(s1);
	s2_size = gnl_strlen(s2);
	i = 0;
	if ((tmp = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1))) == 0)
		return (0);
	while (i < s1_size + s2_size)
	{
		if (i < s1_size)
			tmp[i] = s1[i];
		else
			tmp[i] = s2[i - s1_size];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char				*gnl_strdup(const char *str)
{
	size_t			size;
	size_t			i;
	char			*tmp;

	i = 0;
	size = gnl_strlen(str);
	if ((tmp = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (0);
	while (i < size)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char				*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	size;
	unsigned int	i;

	if (s == 0)
		return (0);
	size = (unsigned int)gnl_strlen(s);
	if (size < start)
		return (gnl_strdup(""));
	if ((p = (char *)malloc(len + 1)) == 0)
		return (0);
	i = 0;
	while (i < len && start + i < size)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
