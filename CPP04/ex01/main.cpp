/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:21:44 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 13:06:39 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal	*tab[10];
	Dog		chien;
	Cat		chat;
	
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << i + 1 << ": ";
			tab[i] = new Dog();
		}
		else
		{
			std::cout << i + 1 << ": ";	
			tab[i] = new Cat();
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ": ";	
		tab[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete tab[i];
	}

	chien.getBrain()->add_idea("je veux jouer");
	chat.getBrain()->add_idea("je veux dormir");
	
	std::cout << std::endl;
	chien.getBrain()->print_ideas();
	chat.getBrain()->print_ideas();
	std::cout << std::endl;
	
	return (0);	
}