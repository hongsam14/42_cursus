/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:41:14 by suhong            #+#    #+#             */
/*   Updated: 2020/10/14 17:02:42 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				gnl_strlen(const char *str)
{
	size_t			i;
	char			*p;

	i = 0;
	p = (char *)str;
	while (p[i] != '\0')
		i++;
	return (i);
}

char				*gnl_strchr(const char *s, int c)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (*p != '\0')
	{
		if (*p == c)
			return ((char *)p);
		p++;
	}
	if (c == 0)
		return ((char *)p);
	return (0);
}

char				*gnl_strjoin(char const *s1, char const *s2)
{
	size_t			s1_size;
	size_t			s2_size;
	char			*start;
	char			*tmp;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_size = gnl_strlen(s1);
	s2_size = gnl_strlen(s2);
	if ((tmp = (char *)malloc(s1_size + s2_size + 1)) == 0)
		return (0);
	start = tmp;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (start);
}

char				*gnl_strdup(const char *str)
{
	size_t			size;
	size_t			i;
	char			*tmp;

	i = 0;
	if (str == 0)
		return (0);
	size = gnl_strlen(str);
	if ((tmp = (char *)malloc(size + 1)) == 0)
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
