/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:28:54 by suhong            #+#    #+#             */
/*   Updated: 2021/07/16 17:04:06 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*judge_command(char *str)
{
	char		*bin;
	char		*ubin;

	if (!str)
		return (0);
	bin = ft_strjoin("/bin/", str);
	ubin = ft_strjoin("/usr/bin/", str);
	if (!bin || !ubin)
		ft_syserror("malloc error");
	if (access(bin, F_OK | X_OK) == -1)
	{
		free(bin);
		if (access(ubin, F_OK | X_OK) == -1)
		{
			free(ubin);
			ft_perror(str, "command not found");
			return (0);
		}
		return (ubin);
	}
	free(ubin);
	return (bin);
}

char	**parse_cmd(char *str)
{
	char	**argv;
	char	*tmp;

	argv = ft_token_split(str, ' ');
	tmp = argv[0];
	argv[0] = judge_command(argv[0]);
	free(tmp);
	if (!argv[0])
	{
		ft_free2(argv);
		return (0);
	}
	return (argv);
}
