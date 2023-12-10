/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:20:09 by tas               #+#    #+#             */
/*   Updated: 2023/08/22 15:12:03 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP

/******************************************************************************/
/*                            includes                                        */
/******************************************************************************/

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

/******************************************************************************/
/*                             classes                                        */
/******************************************************************************/

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add(Contact *repertory);
        void    printContact(Contact *repertory, int index);
        void    displayContact(Contact *repertory, int index);
        void    printList(Contact *repertory);
        void    search(Contact *repertory);
        int     flag_full;
        int     index;
        Contact repertory[8];
};

#endif