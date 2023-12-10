/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:22:46 by tas               #+#    #+#             */
/*   Updated: 2023/11/23 22:50:58 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* constructors & destructor */
BitcoinExchange::BitcoinExchange()
{
    std::cout << "\x1b[38;5;43mBitcoinExchange default constructor called\x1b[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    std::cout << "\x1b[38;5;114mBitcoinExchange Copy constructor called\x1b[0m" << std::endl;
	if (this != &copy)
		*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "\x1b[38;5;124mBitcoinExchange destructor called\x1b[0m" << std::endl;
}

/* operator */
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
    std::cout << "\x1b[38;5;138mBitcoinExchange Copy assignement operation called\x1b[0m" << std::endl;
	_data.insert(assign._data.begin(), assign._data.end());
	return (*this);
}

/* tools */
long long	ftAtoi(std::string nptr)
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

bool	isNumeric(char c)
{
	if (!(c >= '0' && c <= '9'))
	{
		std::cout << "\x1b[38;5;205mError: not a numeric format\x1b[0m" << std::endl;	
		return (false);
	}
	return (true);
}

bool	checkYear(std::string str)
{    
	int i = 0;
	while (i < 4)
	{
		if (isNumeric(str[i]) == false)
    	    return (false);
    	i++;
	}
	int y = ftAtoi(str);
	if (y < 2008 || y > 2023)
	{
		std::cout << "\x1b[38;5;205mError: wrong year format\x1b[0m" << std::endl;
		return (false);
	}
	return (true);
}

bool	checkMonth(std::string str)
{
    int i = 0;
	
	while (i < 2)
	{
		if (isNumeric(str[i]) == false)
    	    return (false);
    	i++;
	}
	int m = ftAtoi(str);
	if (m < 1 || m > 13)
	{
		std::cout << "\x1b[38;5;205mError: wrong month format\x1b[0m" << std::endl;
		return (false);
	}
	return (true);
}

bool	checkDay(std::string str)
{
    int i = 0;
	while (i < 2)
	{
		if (isNumeric(str[i]) == false)
    	    return (false);
    	i++;
	}
	int d = ftAtoi(str);
	if (d < 1 || d > 32)
	{
		std::cout << "\x1b[38;5;205mError: wrong day format\x1b[0m" << std::endl;
		return (false);
	}
	return (true);
}

bool	checkLastNb(std::string str)
{
	int i = 0;
	int flag = 0;
	
	if (str[i] == '-' && i == 0)
		i++;
	while (str[i])
	{
		if (str[i] == '.' && flag == 0)
			flag = 1;
		else if (isNumeric(str[i]) == false)
			return (false);
		i++;
	}
	char *end;
	float l = std::strtod(str.c_str(), &end);
	if (l < 0)
	{
		std::cout << "\x1b[38;5;205mError: not a positif number\x1b[0m" << std::endl;
		return (false);
	}
	else if (l > 1001)
	{
		std::cout << "\x1b[38;5;205mError: too large a number\x1b[0m" << std::endl;
		return (false);
	}
	return (true);
}

/* function member */
bool BitcoinExchange::parseFile(std::string file) 
{
    std::ifstream inputFile(file.c_str());
	getData();
	
    if (!inputFile.is_open())
	{
        std::cout << "\x1b[38;5;205mError: can't open file\x1b[0m" << std::endl;
        return (false);
    }
    std::string line;
	if ((std::getline(inputFile, line)) && (line != "date | value"))
	{
		std::cout << "\x1b[38;5;205mError: first line invalid\x1b[0m" << std::endl;
		return (true);
	}
    while (std::getline(inputFile, line))
		checkLine(line);
    inputFile.close();
    return (true);
}

int	BitcoinExchange::checkLine(std::string line)
{
	if (line.size() < 14)
	{
		std::cout << "\x1b[38;5;205mError: data missing in the line\x1b[0m" << std::endl;
		return (1);
	}
	
    int i = 0;
    std::string year;
    std::string month;
    std::string day;
    std::string Lastnb;

    while(i < 4)
	{
		year += line[i];
		i++;
	}
	if (checkYear(year) == false)
		return (1);
	if (line[i] != '-')
	{
		std::cout << "\x1b[38;5;205mError: incorrect character\x1b[0m" << std::endl;	
        return (1);
	}
    i++;
    while(i < 7)
	{
		month += line[i];
		i++;
	}
	if (checkMonth(month) == false)
		return (1);
    if (line[i] != '-')
	{
		std::cout << "\x1b[38;5;205mError: incorrect character\x1b[0m" << std::endl;	
        return (1);
	}
	else
		i++;
	
    while(i < 10)
    {
		day += line[i];
		i++;
    }
	if (checkDay(day) == false)
		return (1);
	if (line[i] != ' ')
	{
		std::cout << "\x1b[38;5;205mError: incorrect character\x1b[0m" << std::endl;		
        return (1);
	}
	i++;

	if (line[i] != '|')
	{
		std::cout << "\x1b[38;5;205mError: incorrect character\x1b[0m" << std::endl;	
        return (1);
	}
	i++;

	if (line[i] != ' ')
	{
		std::cout << "\x1b[38;5;205mError: incorrect character\x1b[0m" << std::endl;		
        return (1);
	}
	i++;

	while (line[i])
	{
		Lastnb += line[i];
		i++;
	}
	if (checkLastNb(Lastnb) == false)
		return (1);
	printResult(line);
	return (0);
}

/* stock dans un containers map les elm du fichier csv */
void	BitcoinExchange::getData()
{
    std::ifstream file("data.csv");

    if (file.is_open())
	{
        std::string line;
    
	    while (std::getline(file, line))
		{
            std::istringstream linestream(line); // permet d'utiliser std::getline pour extraire les différents éléments séparés par un délimiteur
            std::string elt;
            std::string stringValue;
            float floatValue;

            if (std::getline(linestream, stringValue, ',')) 
			{
                if (std::getline(linestream, elt, ',')) 
				{
					char *end;
					floatValue = std::strtod(elt.c_str(), &end);
                    _data[stringValue] = floatValue;
                }
            }
        }
        file.close();
    }
	else
        std::cout << "\x1b[38;5;205mError: Unable to open the file\x1b[0m" << std::endl;
}

float	BitcoinExchange::findClosest(std::string line)
{
	
	std::string	year = line.substr(0, 4);
	std::string	month = line.substr(5, 2);
	std::string	day = line.substr(8, 2);
	
	/* avant 2009-01-02 */
	if (ftAtoi(year) < 2009 || (ftAtoi(year) == 2009 && ftAtoi(month) == 1 && ftAtoi(day) == 1))
	{
        std::cout << "\x1b[38;5;205mError: date too old\x1b[0m" << std::endl;
		return (0);
	}
	
	/* apres 2022-03-29 */
	if (ftAtoi(year) > 2022 || (ftAtoi(year) > 2022 && ftAtoi(month) > 3) || (ftAtoi(year) == 2022 && ftAtoi(month) == 3 && ftAtoi(day) > 29))
	{
		char *end;
		std::string substrLine = line.substr(13, line.size());
		float inputValue = std::strtod(substrLine.c_str(), &end);
		std::cout << line.substr(0, 10) << " => " << line.substr(13, line.size());
		std::cout << " = \x1b[38;5;129m" << 47115.93 * inputValue << "\x1b[0m" << std::endl;

		return (0);
	}

	/* le reste */
	it = _data.lower_bound(line.substr(0, 10));
	float recupFromFile;
	
	if (it == _data.end())
    	--it;
	--it;
   	recupFromFile = it->second;

	char *end;
	std::string substrLine = line.substr(13, line.size());
	float inputValue = std::strtod(substrLine.c_str(), &end);
	std::cout << line.substr(0, 10) << " => " << line.substr(13, line.size());
	std::cout << " = \x1b[38;5;129m" << recupFromFile * inputValue << "\x1b[0m" << std::endl;
	
	return (0);
}

int	BitcoinExchange::printResult(std::string line)
{
	float recupFromFile;
	it = _data.find(line.substr(0, 10));
	
	if (it != _data.end())
	{
		recupFromFile = it->second;
	}
	else
	{
		findClosest(line);
		return (1);
	}

	char *end;
	std::string substrLine = line.substr(13, line.size());
	float inputValue = std::strtod(substrLine.c_str(), &end);
	std::cout << line.substr(0, 10) << " => " << line.substr(13, line.size());
	std::cout << " = \x1b[38;5;129m" << recupFromFile * inputValue << "\x1b[0m" << std::endl;

	return (0);
}
