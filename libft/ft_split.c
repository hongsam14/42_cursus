/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 19:54:16 by suhong            #+#    #+#             */
/*   Updated: 2020/10/08 05:03:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*free_malloc(char **dest, int i)
{
	while (i >= 0)
		free(dest[i--]);
	free(dest);
	return (0);
}

static size_t	phrase_size(char const *s, char c)
{
	size_t		i;
	size_t		start;

	i = 0;
	start = 0;
	while (*s != '\0')
	{
		if (!start)
		{
			if (*s != c)
				start = 1;
		}
		else
		{
			if (*s == c)
			{
				start = 0;
				i++;
			}
		}
		s++;
	}
	return (!start ? i : i + 1);
}

char			**ft_split(char const *s, char c)
{
	char		**tmp;
	char const	*start;
	size_t		size;
	size_t		i;

	if ((start = s) == 0)
		return (0);
	size = phrase_size(s, c);
	i = 0;
	if ((tmp = (char **)malloc(sizeof(char *) * (size + 1))) == 0)
		return (0);
	while (size > 0 && *s != '\0')
	{
		while (*s++ == c)
			start = s;
		if (*s == c || (*s == '\0' && *start != '\0'))
		{
			if ((tmp[i++] = ft_substr(start, 0, s - start)) == 0)
				return (free_malloc(tmp, --i));
			size--;
		}
	}
	tmp[i] = 0;
	return (tmp);
}
