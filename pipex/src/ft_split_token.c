/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:55:36 by suhong            #+#    #+#             */
/*   Updated: 2021/07/17 16:06:35 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_quotes(char c)
{
	static char	tmp = 0;

	if (!c || c == tmp)
	{
		tmp = 0;
		return (tmp);
	}
	if (ft_strchr("\"\'", c) && !tmp)
	{
		tmp = c;
		return (tmp);
	}
	return (tmp);
}

static size_t	count_token(char const *str, char c)
{
	size_t	size;
	size_t	i;
	int		p_flag;
	int		q_flag;

	size = 0;
	i = 0;
	p_flag = 0;
	while (str[i])
	{
		q_flag = check_quotes(str[i]);
		if (str[i] != c && !p_flag)
		{
			p_flag = 1;
		}
		else if (str[i] == c && !q_flag && p_flag)
		{
			p_flag = 0;
			size++;
		}
		i++;
	}
	check_quotes(0);
	return (size + p_flag);
}

static char	**do_malloc(char const *str, char c, size_t *size)
{
	char	**tmp;

	if (!str)
		return (0);
	*size = count_token(str, c);
	tmp = (char **)malloc(sizeof(char *) * (*size + 1));
	if (!tmp)
		ft_syserror("malloc error");
	return (tmp);
}

static void	init_func(size_t *i, char **spot)
{
	*i = 0;
	*spot = 0;
}

char	**ft_token_split(char *str, char c)
{
	char	**token;
	size_t	size;
	size_t	i;
	char	*spot;
	int		q;

	init_func(&i, &spot);
	token = do_malloc(str, c, &size);
	while (i < size && *str >= 0)
	{
		q = check_quotes(*str);
		if (*str != c && !ft_strchr("\'\"", *str) && !spot)
			spot = str;
		else if (!q && spot && (*str == c || ft_strchr("\'\"", *str) || !*str))
		{
			token[i] = ft_substr(spot, 0, str - spot);
			if (!token[i++])
				ft_syserror("malloc error");
			spot = 0;
		}
		str++;
	}
	token[i] = 0;
	check_quotes(0);
	return (token);
}
