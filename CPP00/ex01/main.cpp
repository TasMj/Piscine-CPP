/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:14:32 by tas               #+#    #+#             */
/*   Updated: 2023/05/15 08:24:49 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    std::string     input;
    PhoneBook       phonebook;
    
    if (argc != 1)
        return (0);
    phonebook.index = 0;
    while (input.compare("EXIT") != 0)
    {
        std::cout << "\n*************************************************" << std::endl;
        std::cout << "* If you want to add a contact, enter ADD       *" << std::endl;
        std::cout << "* If you want to search a contact, enter SEARCH *" << std::endl;
        std::cout << "* If you want to exit the program, enter EXIT   *" << std::endl;
        std::cout << "*************************************************\n" << std::endl;
        std::cin >> input;
        if (input.compare("ADD") == 0)
            phonebook.add(phonebook.repertory);
        else if (input.compare("SEARCH") == 0)
            phonebook.search(phonebook.repertory);
        else if (input.compare("EXIT") != 0)
            std::cout << "error: the command doesn't exist. \nPlease enter 'ADD', 'SEARCH' or 'EXIT" << std::endl;
    }
    return (0);
}