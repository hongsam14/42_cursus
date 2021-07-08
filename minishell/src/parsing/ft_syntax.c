/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:55:34 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/06 05:16:15 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_quotes(char const *s, int *i, int *flag, char c)
{
	if (s[(*i)])
		(*i)++;
	while (s[(*i)] && s[(*i)] != c)
		(*i)++;
	(*flag) = 1;
}

static int	face_space_at_start_case(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strchr("|;", str[i]))
	{
		g_mini.status = ERROR_INVALID_ARGUMENT;
		ft_syntaxerror(str[i]);
		free(str);
		return (ERROR_INVALID_ARGUMENT);
	}
	return (SUCCESS);
}

static int	face_normal_char(char *str, int *i, int *flag)
{
	char	find;

	if (str[(*i)] && ft_strchr("><;|", str[*i]))
	{
		find = str[*i];
		(*i)++;
		while (str[*i] == ' ')
			(*i)++;
		if ((str[(*i)] && (ft_strchr("|;", str[(*i)]) || (find == str[(*i)] && !str[(*i + 1)]))) || \
				(!str[(*i)] && ((find == ';' && *i == 0) \
				|| ft_strchr("><|", find))))
		{
			ft_syntaxerror(find);
			g_mini.status = ERROR_INVALID_ARGUMENT;
			ft_free(str);
			return (ERROR_INVALID_ARGUMENT);
		}
	}
	if (str[(*i)] == '"')
		*flag = -1;
	else if (str[*i] == '\'')
		*flag = -2;
	return (SUCCESS);
}

int	ft_check_syntax(char *str)
{
	int		i;
	int		flag;

	flag = 1;
	if (!str)
		return (ERROR);
	if (face_space_at_start_case(str) != SUCCESS)
		return (ERROR_INVALID_ARGUMENT);
	i = 0;
	while (str[i])
	{
		if (flag == 1)
		{
			if (face_normal_char(str, &i, &flag) != SUCCESS)
				return (ERROR_INVALID_ARGUMENT);
		}
		if (flag == -1 && str[i] == '"')
			ft_quotes(str, &i, &flag, '"');
		else if (flag == -2 && str[i] == '\'')
			ft_quotes(str, &i, &flag, '\'');
		if (str[i])
			i++;
	}
	return (SUCCESS);
}
