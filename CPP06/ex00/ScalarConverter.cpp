/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:00:19 by tas               #+#    #+#             */
/*   Updated: 2023/11/16 14:23:15 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

long long	ft_atoi(std::string nptr)
{
	long long	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((res > 2147483647 && sign == 1) || (res < -2147483648 - 1 && sign == -1))
			return (-1);
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
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

int	ftStrlen(std::string nb)
{
	int i = 0;

	while (nb[i])
		i++;
	return (i);
}

bool	isFloat(std::string nb)
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
	if (!(nb[i] >= '0' && nb[i] <= '9') && nb[i])
		return (false);
	while (nb[i] >= '0' && nb[i] <= '9')
		i++;
	if (nb[i] == 'f' && ftStrlen(nb) == (i + 1))
		return (true);
	return (false);
}

int	isAchar(std::string nb)
{
	if (ftStrlen(nb) > 1 && !onlyDigit(nb) && !isFloat(nb) && !DecimalDigit(nb))
		return (1);
	if (ftStrlen(nb) == 1 && !onlyDigit(nb) && (nb[0] > 32 && nb[0] < 127))
		return (2);
	return (3);
}

void	removeF(std::string nb)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (nb[i] != 'f')
		i++;
	while (j < i)
	{
		std::cout << nb[j];
		j++;
	}
}

/* conversion */
void    ScalarConverter::toChar(std::string nb)
{
	int		intValue;
	char	asciiValue;

	intValue = ft_atoi(nb);
	if (ft_strcmp(nb, "-inff") || ft_strcmp(nb, "+inff") 
		|| ft_strcmp(nb, "-inf") || ft_strcmp(nb, "+inf") 
		|| ft_strcmp(nb, "nan") || isAchar(nb) == 1 
		|| intValue <= -1 || intValue > 126)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (isAchar(nb) == 2)
	{
		std::cout << "char: " << nb << std::endl;
	}
	else if (ftStrlen(nb) == 1 && nb[0] == 32)
		std::cout << "char: ' '" << std::endl;
	else if ((intValue >= 0 && intValue < 32) || intValue == 127)
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
   		asciiValue = static_cast<char>(intValue);
		if (asciiValue == 32)
			std::cout << "char: ' '" << std::endl;
		else
			std::cout << "char: '" << asciiValue << "'" << std::endl;
	}
}

void    ScalarConverter::toInt(std::string nb)
{
	int		intValue;

	intValue = ft_atoi(nb);
	if (ft_strcmp(nb, "-inff") || ft_strcmp(nb, "+inff") 
		|| ft_strcmp(nb, "-inf") || ft_strcmp(nb, "+inf") 
		|| ft_strcmp(nb, "nan") || intValue == -1)
	{
		std::cout << "int: impossible" << std::endl;
	}
	else if (ftStrlen(nb) == 1 && !onlyDigit(nb))
	{
		int asciiValue = static_cast<int>(nb[0]);
		std::cout << "int: " << asciiValue << std::endl;
	}
	else
	{
		std::cout << "int: " << intValue << std::endl;
	}
}

void    ScalarConverter::toFloat(std::string nb)
{
	if (ft_strcmp(nb, "-inff") || ft_strcmp(nb, "+inff") 
		|| ft_strcmp(nb, "-inf") || ft_strcmp(nb, "+inf"))
	{
		std::cout << "float: impossible" << std::endl;
	}
	else if (ft_strcmp(nb, "nan"))
	{
		std::cout << "float: nanf" << std::endl;
	}
	else if (isFloat(nb) == true)
	{
		std::cout << "float: " << nb << std::endl;
	}
	else if (onlyDigit(nb))
	{
		std::string floatValue = nb.append(".0f");
		std::cout << "float: " << floatValue << std::endl;
	}
	else if (DecimalDigit(nb))
	{
		std::string floatValue = nb.append("f");
		std::cout << "float: " << floatValue << std::endl;
	}
	else
	{
		std::cout << "float: impossible" << std::endl;
	}
}

void    ScalarConverter::toDouble(std::string nb)
{
	if (ft_strcmp(nb, "-inff") || ft_strcmp(nb, "+inff") 
		|| ft_strcmp(nb, "-inf") || ft_strcmp(nb, "+inf"))
	{
		std::cout << "double: impossible" << std::endl;
	}
	else if (ft_strcmp(nb, "nan"))
	{
		std::cout << "double: nan" << std::endl;
	}

	else if (DecimalDigit(nb))
	{
		std::cout << "double: " << nb << std::endl;
	}
	else if (onlyDigit(nb))
	{
		std::string floatValue = nb.append(".0");
		std::cout << "double: " << floatValue << std::endl;
	}
	else if (isFloat(nb))
	{
		std::cout << "double: ";
		removeF(nb);
		std::cout << "\n";
	}
	else
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void	ScalarConverter::convert(std::string nb)
{
	if (onlyDigit(nb) || DecimalDigit(nb) || isFloat(nb) || ft_strcmp(nb, "-inff") || ft_strcmp(nb, "+inff") 
		|| ft_strcmp(nb, "-inf") || ft_strcmp(nb, "+inf") || ft_strcmp(nb, "nan") || ft_strcmp(nb, " "))
	{
		toChar(nb);
		toInt(nb);
		toFloat(nb);
		toDouble(nb);
	}
	else
	{
		std::cout << "Not a valid argument" << std::endl;
	}
}