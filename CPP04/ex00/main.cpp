/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:21:44 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 12:22:02 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "------- Animal -------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << std::endl;
    	std::cout << "\x1b[32m";
		std::cout << meta->GetType() << " " << std::endl;
    	std::cout << "\x1b[0m";
    	std::cout << "\x1b[33m";
		std::cout << i->GetType() << " " << std::endl;
    	std::cout << "\x1b[0m";
    	std::cout << "\x1b[35m";
		std::cout << j->GetType() << " " << std::endl;
    	std::cout << "\x1b[0m";
		std::cout << std::endl;
		
		meta->makeSound();
		i->makeSound();
		j->makeSound();
		std::cout << std::endl;

		delete meta;
		delete j;
		delete i;	
	}
	{
		std::cout << std::endl;
		std::cout << "---- Wrong Animal ----" << std::endl;
		const WrongAnimal* wrong = new WrongAnimal();
		const WrongAnimal* wcat = new WrongCat();
		
		std::cout << std::endl;
    	std::cout << "\x1b[34m";
		std::cout << wrong->GetType() << " " << std::endl;
    	std::cout << "\x1b[0m";
    	std::cout << "\x1b[31m";
		std::cout << wcat->GetType() << " " << std::endl;
    	std::cout << "\x1b[0m";
		
		std::cout << std::endl;
		wrong->makeSound();
		wcat->makeSound();

		std::cout << std::endl;
		delete wrong;
		delete wcat;
		std::cout << std::endl;
	}

	return 0;
}