/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:20:46 by tas               #+#    #+#             */
/*   Updated: 2023/08/22 14:57:15 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "PhoneBook Constructor called" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook Destructor called" << std::endl;
    return;
}

void    PhoneBook::add(Contact *repertory)
{
    std::string data;

    std::cout << "Please enter your information" << std::endl;
    if (PhoneBook::index == 7)
    {
        PhoneBook::index = 0;
        PhoneBook::flag_full = 1;
    }
    
    std::cout << "First name: ";
    std::cin >> data;
    repertory[PhoneBook::index].FirstName = data;

    std::cout << "Last name: ";
    std::cin >> data;
    repertory[PhoneBook::index].LastName = data;

    std::cout << "Nickname: ";
    std::cin >> data;
    repertory[PhoneBook::index].Nickname = data;

    std::cout << "Phone number: ";
    std::cin >> data;
    repertory[PhoneBook::index].PhoneNumber = data;

    std::cout << "Darkest secret: ";
    std::cin >> data;
    repertory[PhoneBook::index].DarkestSecret = data;

    std::cout << repertory[PhoneBook::index].FirstName << " " << repertory[PhoneBook::index].LastName << " has been added" << std::endl;;
    PhoneBook::index++;
}

void    PhoneBook::printContact(Contact *repertory, int index)
{
    int counter;
    
    counter = 0;
    PhoneBook::index = 0;
    while (PhoneBook::index < index)
        PhoneBook::index++;    
    std::cout << PhoneBook::index + 1;
    std::cout << "         |";
    while(counter < 9 && repertory[PhoneBook::index].FirstName[counter])
    {
        std::cout << repertory[PhoneBook::index].FirstName[counter];
        counter++;
        if (counter == 9 && repertory[PhoneBook::index].FirstName[counter])
        {
            std::cout << ".";
            counter++;
        }
    }
    while(counter <= 9)
    {
        std::cout << " ";
        counter++;
    }

    counter = 0;
    std::cout << "|";

    while(counter < 9 && repertory[PhoneBook::index].LastName[counter])
    {
        std::cout << repertory[PhoneBook::index].LastName[counter];
        counter++;
        if (counter == 9 && repertory[PhoneBook::index].LastName[counter])
        {
            std::cout << ".";
            counter++;
        }
    }
    while(counter <= 9)
    {
        std::cout << " ";
        counter++;
    }
    std::cout << "|";

    counter = 0;
    while(counter < 9 && repertory[PhoneBook::index].Nickname[counter])
    {
        std::cout << repertory[PhoneBook::index].Nickname[counter];
        counter++;
        if (counter == 9 && repertory[PhoneBook::index].Nickname[counter])
        {
            std::cout << ".";
            counter++;
        }
    }
    while(counter <= 9)
    {
        std::cout << " ";
        counter++;
    }
    std::cout << "\n";
}

void    PhoneBook::printList(Contact *repertory)
{
    int keepIndex = 0;
    
    int saveIndex = PhoneBook::index;
    if (PhoneBook::flag_full == 1)
    {
        saveIndex = 7;
        keepIndex = PhoneBook::index;
    }
    PhoneBook::index = 0;
    while (PhoneBook::index < saveIndex)
    {
        printContact(repertory, index);
        PhoneBook::index++;
    }
    if (PhoneBook::flag_full == 1)
        PhoneBook::index = keepIndex;
}

int	ft_atoi(std::string str)
{
	int		res;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void    PhoneBook::displayContact(Contact *repertory, int index)
{
    int keepIndex;
    
    keepIndex = PhoneBook::index;
    PhoneBook::index = 0;
    while (PhoneBook::index < index)
        PhoneBook::index++;    
    std::cout << "\n" << PhoneBook::index + 1;
    std::cout << " | ";
    std::cout << repertory[PhoneBook::index].FirstName;
    std::cout << " | ";
    std::cout << repertory[PhoneBook::index].LastName;
    std::cout << " | ";
    std::cout << repertory[PhoneBook::index].Nickname << std::endl;
    PhoneBook::index = keepIndex;
}

void    PhoneBook::search(Contact *repertory)
{
    std::string nb_input;
    int i;

    printList(repertory);
    std::cout << "Please enter the number of the contact to display:" << std::endl;
    std::cin >> nb_input;

    i = ft_atoi(nb_input);
    if (i <= 0 || i > 8)
    {
        std::cout << "error: index" << std::endl;
        return ;
    }
    else
    {
        if (i < 0)
        {
            std::cout << "error: index" << std::endl;
            return ;
        }
        if (i > PhoneBook::index && PhoneBook::flag_full != 1)
        {
            std::cout << "Sorry there is only " << PhoneBook::index << " contact(s)" << std::endl;
            return ;
        }
        displayContact(repertory, i - 1);
    }
}
