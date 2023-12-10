/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:43:17 by tas               #+#    #+#             */
/*   Updated: 2023/08/26 15:10:27 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

/******************************************************************************/
/*                            includes                                        */
/******************************************************************************/
#include <string>
#include <iostream>
#include <fstream>

/******************************************************************************/
/*                             classes                                        */
/******************************************************************************/

class Sed
{
    public:
    
        Sed(std::string filename, std::string s1, std::string s2);
        ~Sed(void);

        std::fstream &get_infile(void);
        std::ofstream &get_outfile(void);
        
    private:
    
        std::string _filename;
        std::string _s1;
        std::string _s2;
        std::fstream infile;
        std::ofstream outfile;
};

std::string ft_replace(std::string buffer, std::string s1, std::string s2);

#endif