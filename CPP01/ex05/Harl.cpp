/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:00:29 by tas               #+#    #+#             */
/*   Updated: 2023/08/23 23:45:34 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "constructor called" << std::endl;
	this->annonce[0] = "DEBUG";
	this->annonce[1] = "INFO";
	this->annonce[2] = "WARNING";
	this->annonce[3] = "ERROR";

	this->ptr[0] = &Harl::debug;
	this->ptr[1] = &Harl::info;
	this->ptr[2] = &Harl::warning;
	this->ptr[3] = &Harl::error;
}

Harl::~Harl()
{
    std::cout << "destructor called" << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;

	while (i < 4)
	{
		if (annonce[i] == level)
		{
			(this->*ptr[i])();
		}
		i++;
	}
}

void Harl::debug( void )
{
	std::cout<< "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}
void Harl::info( void )
{
	std::cout<< "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void Harl::warning( void )
{
	std::cout<< "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
;
}
void Harl::error( void )
{
	std::cout << "ERROR : This is unacceptable ! I want to speak to the manager now." << std::endl;
}
