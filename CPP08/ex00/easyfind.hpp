/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:35:35 by tas               #+#    #+#             */
/*   Updated: 2023/12/25 11:43:30 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

/******************************************************************************/
/*                                  Class                                     */
/******************************************************************************/

class NoOccurence : public std::exception
{
	public:
		const char	*what(void) const throw()
		{
			return "\x1b[38;5;125mAucune occurence n'a été trouvée.\x1b[0m";
		}
};

/******************************************************************************/
/*                                 Functions                                  */
/******************************************************************************/

template<typename T>
int easyfind(T container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it != container.end())
    {
        std::cout << "\x1b[38;5;79mUne occurrence à bien été trouvée à l'index: \x1b[0m" <<  std::distance(container.begin(), it) << std::endl;
        return (std::distance(container.begin(), it));
    }
    else
        throw NoOccurence();
    return (1);
}

#endif