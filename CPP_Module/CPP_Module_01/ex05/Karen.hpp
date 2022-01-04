/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:25:15 by suhong            #+#    #+#             */
/*   Updated: 2022/01/04 16:39:18 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>
# include <array>

namespace customer
{
	class Karen
	{
		public:
			void	complain(std::string level);
			Karen();
			~Karen();

		private:
			void	debug(void);
			void	info(void);
			void	warning(void);
			void	error(void);
	};
}

#endif
