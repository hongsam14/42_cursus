/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:31:46 by suhong            #+#    #+#             */
/*   Updated: 2020/12/06 16:50:29 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int	tmp[255];
	char	*c;
	char	*d;
	int	i;
	
	i = 0;
	if (argc == 3)
	{
		c = argv[1];
		d = argv[2];
		while (i < 255)
			tmp[i++] = 0;
		while (*d != '\0')
		{
			if (tmp[(int)*d] == 0)
				tmp[(int)*d] = 1;
			d++;
		}
		while (*c != '\0')
		{
			if (tmp[(int)*c] == 1)
			{
				write(1, c, 1);
				tmp[(int)*c] = 0;
			}
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
