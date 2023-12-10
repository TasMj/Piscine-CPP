/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:21:44 by tas               #+#    #+#             */
/*   Updated: 2023/10/06 13:20:50 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	AAnimal	*tab[10];
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

	chien.GetBrain()->add_idea("je veux jouer");
	chat.GetBrain()->add_idea("je veux dormir");
	
	std::cout << std::endl;
	chien.GetBrain()->print_ideas();
	chat.GetBrain()->print_ideas();
	std::cout << std::endl;
	
	return (0);	
}