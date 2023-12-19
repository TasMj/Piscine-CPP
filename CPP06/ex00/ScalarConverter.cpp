/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:19 by tas               #+#    #+#             */
/*   Updated: 2023/12/19 21:44:44 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

/* constructors and destructor */
ScalarConverter::ScalarConverter()
{
    std::cout << "\x1b[38;5;43mScalar default constructor called\x1b[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    std::cout << "\x1b[38;5;114mScalar Copy constructor called\x1b[0m" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "\x1b[38;5;124mScalar destructor called\x1b[0m" << std::endl;	
}

/* operator */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign)
{
    std::cout << "\x1b[38;5;138mScalar Copy assignement operation called\x1b[0m" << std::endl;
    (void)assign;
	return (*this);
}

/* tools*/
int	ft_strcmp(std::string s1, std::string s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

bool	onlyDigit(std::string nb)
{
	int i = 0;
	
	if (nb[i] == '-')
		i++;
	while(nb[i])
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	DecimalDigit(std::string nb)
{
	int i = 0;
	
	if (nb[i] == '-')
		i++;
	if (!(nb[i] >= '0' && nb[i] <= '9'))
		return (false);
	while (nb[i] >= '0' && nb[i] <= '9')
		i++;
	if (nb[i] == '.')
		i++;
	else
		return (false);
	while (nb[i])
	{
		if (nb[i] >= '0' && nb[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	isFloat(std::string nb)
{
	unsigned int i = 0;

	if (nb[i] == '-')
		i++;
	if (!(nb[i] >= '0' && nb[i] <= '9'))
		return (false);
	while (nb[i] >= '0' && nb[i] <= '9')
		i++;
	if (nb[i] == '.')
		i++;
	else
		return (false);
	if (!(nb[i] >= '0' && nb[i] <= '9') && nb[i])
		return (false);
	while (nb[i] >= '0' && nb[i] <= '9')
		i++;
	if (nb[i] == 'f' && nb.length() == (i + 1))
		return (true);
	return (false);
}

int	precisionCounter(std::string nb)
{
	int i = 0;
	int c = 0;

	while (isdigit(nb[i]))
		i++;
	if (nb[i] == '.')
		i++;
	while (isdigit(nb[i]))
	{
		c++;
		i++;
	}
	return (c);
}

int	isAchar(std::string nb)
{
	if (nb.length() > 1 && !onlyDigit(nb) && !isFloat(nb) && !DecimalDigit(nb))
		return (1);
	if (nb.length() == 1 && !onlyDigit(nb) && ((nb[0] > 32 && nb[0] < 127) || nb[0] == 32))
		return (2);
	return (3);
}

/* convert functions */
void	convertInt(std::string nb)
{
	std::istringstream iss(nb);
    long int longInt;
	iss >> longInt;
	int intValue = static_cast<int>(longInt);

	if (longInt != intValue)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if ((intValue >= 0 && intValue < 32) || intValue == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (intValue < 0 || intValue > 127)
			std::cout << "char: impossible" << std::endl;
		else
		{
   			char	asciiValue = static_cast<char>(intValue);
			if (asciiValue == 32)
				std::cout << "char: ' '" << std::endl;
			else
				std::cout << "char: '" << asciiValue << "'" << std::endl;
		}
		std::cout << "int: " << intValue << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(longInt) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(longInt) << std::endl;
}

void	convertChar(std::string nb)
{
	char c = nb.at(0); //acces premier char
	int	cInt = static_cast<int>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << cInt << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(cInt) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(cInt) << std::endl;
}

void	convertFloat(std::string nb)
{
    std::istringstream iss(nb);
    float f;
	iss >> f;
	int fInt = static_cast<int>(f);

	if (fInt < -2147483648 || fInt > 2147483647 || (fInt < 0 && nb.length() >= 11))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}	
	else
	{
		if ((fInt >= 0 && fInt < 32) || fInt == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (fInt < 0 || fInt > 127)
			std::cout << "char: impossible" << std::endl;
		else
		{
   			char asciiValue = static_cast<char>(fInt);
			if (asciiValue == 32)
				std::cout << "char: ' '" << std::endl;
			else
				std::cout << "char: '" << asciiValue << "'" << std::endl;
		}
		std::cout << "int: " << fInt << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(precisionCounter(nb)) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precisionCounter(nb)) << static_cast<double>(f) << std::endl;
}

void	convertDouble(std::string nb)
{
    std::istringstream iss(nb);
    double doubleValue;
	iss >> doubleValue;
	int intValue = static_cast<int>(doubleValue);

	if (doubleValue < -2147483648 || doubleValue > 2147483647)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if ((intValue >= 0 && intValue < 32) || intValue == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (intValue < 0 || intValue > 127)
			std::cout << "char: impossible" << std::endl;
		else
		{
   			char	asciiValue = static_cast<char>(intValue);
			if (asciiValue == 32)
				std::cout << "char: ' '" << std::endl;
			else
				std::cout << "char: '" << asciiValue << "'" << std::endl;
		}
		std::cout << "int: " << intValue << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(precisionCounter(nb)) << static_cast<float>(doubleValue) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(precisionCounter(nb)) << doubleValue << std::endl;
}

void	convertNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void	convertInfNeg()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	convertInfPos()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: inff" << std::endl;
	std::cout << "double: inf" << std::endl;
}

void	ScalarConverter::convert(std::string nb)
{
	if (nb.empty())
		std::cout << PINK << "Error: No argument" << EOC << std::endl;
	else if (isAchar(nb) == 2)
		convertChar(nb);
	else if (onlyDigit(nb))
		convertInt(nb);
	else if (isFloat(nb))
		convertFloat(nb);	
	else if (DecimalDigit(nb))
		convertDouble(nb);
	else if (ft_strcmp(nb, "nan"))
		convertNan();
	else if (ft_strcmp(nb, "-inf") || ft_strcmp(nb, "-inff"))
		convertInfNeg();
	else if (ft_strcmp(nb, "inf") || ft_strcmp(nb, "inff") || ft_strcmp(nb, "+inf") || ft_strcmp(nb, "+inff"))
		convertInfPos();
	else
		std::cout << PINK << "Error: Not a valid argument" << EOC << std::endl;
}