/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:36:38 by suhong            #+#    #+#             */
/*   Updated: 2022/01/05 15:54:26 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int argc, char *argv[])
{
	customer::Karen	karen;
	
	if (argc < 2 || argc > 2)
	{
		std::cerr<<"invalid arguments. "<<std::endl;
		return (1);
	}
	karen.complain(argv[1]);
	return (0);
}
