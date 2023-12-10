/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:14:41 by tas               #+#    #+#             */
/*   Updated: 2023/06/11 11:26:07 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *ptr = &brain;
    std::string &ref = brain;
    
    std::cout << "adress:" << std::endl;
    std::cout << &brain << std::endl;
    std::cout << ptr << std::endl;
    std::cout << &ref << std::endl;

    std::cout << "\nstring value:" << std::endl;
    std::cout << brain << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;
    
}