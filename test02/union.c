/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:53:07 by suhong            #+#    #+#             */
/*   Updated: 2020/12/06 17:03:47 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int	tmp[255];
	int	i;
	char	*c;
	char	*d;

	i = 0;
	if (argc == 3)
	{
		c = argv[1];
		d = argv[2];
		while (i < 255)
			tmp[i++] = 0;
		while (*c != '\0')
		{
			if (tmp[(int)*c] == 0)
			{
				write(1, c, 1);
			       tmp[(int)*c] = 1;	
			}
			c++;
		}
		while (*d != '\0')
		{
			if (tmp[(int)*d] == 0)
			{
				write(1, d, 1);
			       tmp[(int)*d] = 1;	
			}
			d++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
