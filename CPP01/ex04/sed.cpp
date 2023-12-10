/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:43:08 by tas               #+#    #+#             */
/*   Updated: 2023/08/23 00:44:31 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2)
{
    std::cout << "constructor called" << std::endl;
	this->infile.open(this->_filename.c_str());
	if (this->infile.fail())
	{
		std::cout << "file doesn't exist" << std::endl;
		return ;
	}
	this->outfile.open("file.replace", std::fstream::out | std::fstream::trunc);
	if (this->outfile.fail())
	{
		std::cout << "file doesn't exist" << std::endl;
		return ;
	}
}

Sed::~Sed(void)
{
    std::cout << "destructor called" << std::endl;
    this->infile.close();
    this->outfile.close();
    return ;
}

std::fstream &Sed::get_infile(void)
{
	return (this->infile);
}

std::ofstream &Sed::get_outfile(void)
{
	return (this->outfile);
}

std::string ft_replace(std::string buffer, std::string s1, std::string s2)
{
	std::size_t	i = 0;

	i = buffer.find(s1, 0);
	while (i != std::string::npos)
	{
		buffer.erase(i, s1.size());
		buffer.insert(i, s2);
		i += s2.size();
		i = buffer.find(s1.c_str(), i, s1.size());
	}
	return (buffer);
}
