/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:34:52 by hopark            #+#    #+#             */
/*   Updated: 2021/07/05 03:08:45 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0 || !s1 || !s2)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (ft_strlen(s1) != n)
		return (0);
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp2(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	n = ft_strlen(s2);
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp3(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*b;

	i = 0;
	f = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (i < n && f[i] != '\0' && b[i] != '\0')
	{
		if (f[i] > b[i])
			return (1);
		if (b[i] > f[i])
			return (-1);
		i++;
	}
	if (i < n)
	{
		if (f[i] != '\0')
			return (1);
		if (b[i] != '\0')
			return (-1);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	size;
	unsigned int	i;

	if (s == 0)
		return (0);
	size = (unsigned int)ft_strlen(s);
	i = 0;
	if (size < start)
		return (ft_strndup("", 0));
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	while (i < len && start + i < size)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strlen2(char **s)
{
	int				i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
