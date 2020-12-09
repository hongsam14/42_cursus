/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:08:54 by suhong            #+#    #+#             */
/*   Updated: 2020/12/07 02:46:13 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_strdup(char const *str)
{
	size_t	len;
	size_t	index;
	char	*tmp;

	len = ft_strlen(str);
	if (!(tmp = (char *)malloc(len + 1)))
		return (0);
	index = 0;
	while (index < len)
	{
		tmp[index] = str[index];
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}

static char	*ft_strchr(char const *s, int c)
{
	char	*p;

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

static char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	s_len;
	size_t	index;
	char	*tmp;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (!(tmp = (char *)malloc(len + 1)))
		return (0);
	index = 0;
	while (index + start < s_len && index < len)
	{
		tmp[index] = s[index + start];
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*tmp;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	if (!(tmp = (char *)malloc(s1_len + s2_len + 1)))
		return (0);
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			tmp[i] = s1[i];
		else
			tmp[i] = s2[i - s1_len];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int		split_buffer(char **buffer, char **line)
{
	char		*b_tmp;
	char		*point;
	
	if (!(*buffer))
		return (0);
	b_tmp = *buffer;
	if (!(point = ft_strchr(b_tmp, '\n')))
		return (0);
	*line = ft_substr(b_tmp, 0, point - b_tmp);
	*buffer = ft_strdup(point + 1);
	free(b_tmp);
	if (*line == 0 || *buffer == 0)
	{
		if (*line == 0)
			free(*line);
		if (*buffer == 0)
		{
			free(*buffer);
			*buffer = 0;
		}
		return (-1);
	}
	return (1);
}

static int		join_buffer(char **buffer, char *tmp)
{
	char		*b_tmp;

	if (!(*buffer))
	{
		*buffer = tmp;
		return (1);
	}
	b_tmp = *buffer;
	*buffer = ft_strjoin(b_tmp, tmp);
	free(b_tmp);
	free(tmp);
	if (*buffer == 0)
		return (-1);
	return (1);
}

int			get_next_line(char **line)
{
	static char	*buffer = 0;
	char		*tmp;
	int		result;
	ssize_t		read_size;

	while ((result = split_buffer(&buffer, line)) == 0)
	{
		if (!(tmp = (char *)malloc(128)))
		{
			if (buffer)
			{
				free(buffer);
				buffer = 0;
			}
			return (-1);
		}
		if ((read_size = read(0, tmp, 127)) <= 0)
		{
			free(tmp);
			if (read_size == 0)
			{
				if (!buffer)
				{
					if (!(*line = ft_strdup("")))
						return (-1);
					return (0);
				}
				*line = ft_strdup(buffer);
				free(buffer);
				buffer = 0;
				if (!(*line))
					return (-1);
				return (0);
			}
		}
		tmp[read_size] = '\0';
		if (!(result = join_buffer(&buffer, tmp)))
			break ;
	}
	if (result == -1)
		return (-1);
	return (1);
}
