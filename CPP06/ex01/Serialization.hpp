/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:57:49 by tas               #+#    #+#             */
/*   Updated: 2023/12/15 19:26:17 by tmejri           ###   ########.fr       */
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
    uintptr_t   n; // uintptr_t = unsigned int type capable of storing a data pointer
}               Data;


/******************************************************************************/
/*                                   Classes                                  */
/******************************************************************************/


class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &assign);
        ~Serializer();

    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif
