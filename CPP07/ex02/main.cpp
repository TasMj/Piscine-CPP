/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:01:58 by tas               #+#    #+#             */
/*   Updated: 2023/11/21 16:14:43 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdio>

#define MAX_VAL 750
int main(int, char**)
{
	printf("\x1b[38;5;143m**************EMPTY ARRAY**************\x1b[0m\n");
	Array<int>			EmptyArray;
	std::cout << "size: " << EmptyArray.size() << std::endl;
	
	printf("\n\x1b[38;5;143m***************INT ARRAY***************\x1b[0m\n");
	Array<int>		IntArray(15);
	IntArray[0] = 1;
	IntArray[1] = 2;
	IntArray[2] = 3;
	IntArray[3] = 4;
	IntArray[4] = 5;
	IntArray[5] = 6;
	IntArray[6] = 7;
	IntArray[7] = 8;
	IntArray[8] = 9;
	IntArray[9] = 10;
	IntArray[10] = 11;
	IntArray[12] = 11;
	std::cout << "size: " << IntArray.size() << std::endl;
	std::cout << std::endl << "Value of the int array: \n" << std::endl;
	for (int i = 0; i < 11; i++)
		std::cout << IntArray[i] << std::endl;

	printf("\n\x1b[38;5;143m**************STRING ARRAY**************\x1b[0m\n");
	Array<std::string>	stringArray(10);

	stringArray[0] = "Lundi";
	stringArray[1] = "Mardi";
	stringArray[2] = "Mercredi";
	stringArray[3] = "Jeudi";
	stringArray[4] = "Vendredi";
	stringArray[5] = "Samedi";
	stringArray[6] = "Dimanche";
	std::cout << "size: " << stringArray.size() << std::endl;	
	std::cout << std::endl << "Value of the string array: \n" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << stringArray[i] << std::endl;

	printf("\n\x1b[38;5;143m**********CHANGE STRING ARRAY**********\x1b[0m\n");
	Array<std::string>	ChangeStringArray;
	ChangeStringArray = stringArray;
	
	std::cout << "size: " << ChangeStringArray.size() << std::endl;	
	
	ChangeStringArray[1] = "???";
	ChangeStringArray[3] = "???";
	ChangeStringArray[5] = "???";
	
	std::cout << std::endl << "Value of the string array with some change: \n" << std::endl;
	for (int i = 0; i < 7; i++)
		std::cout << ChangeStringArray[i] << std::endl;
	std::cout << std::endl;
	
	printf("\n\x1b[38;5;143m**************INVALID INDEX**************\x1b[0m\n");
	try
	{
		std::cout << stringArray[42] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << stringArray[-42] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}