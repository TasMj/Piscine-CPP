/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:49 by tas               #+#    #+#             */
/*   Updated: 2023/11/16 16:19:58 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

/******************************************************************************/
/*                                 Includes                                   */
/******************************************************************************/

#include <iostream>
#include <string.h>
#include <stdint.h>

/******************************************************************************/
/*                                  Structure                                 */
/******************************************************************************/

typedef struct s_Data
{
    std::string str;
    uintptr_t   n;
}               Data;


/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/


class Serializer
{
    public:

        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &assign);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
