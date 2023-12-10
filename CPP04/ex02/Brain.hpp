/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:56:08 by tas               #+#    #+#             */
/*   Updated: 2023/08/27 14:54:27 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>

/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/

class Brain
{
    public:

        Brain();
        Brain(Brain const &copy);
        Brain &operator=(Brain const &copy);
        virtual ~Brain();
        void add_idea(std::string idea);
        void print_ideas() const;
        
    private:

        std::string ideas[100];
};

#endif