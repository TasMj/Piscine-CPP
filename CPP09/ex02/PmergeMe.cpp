/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:26:08 by tmejri            #+#    #+#             */
/*   Updated: 2023/12/16 02:39:26 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* canonical functions */
PmergeMe::PmergeMe()
{
    // std::cout << "\x1b[38;5;43mPmergeMe default constructor called\x1b[0m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    // std::cout << "\x1b[38;5;114mPmergeMe Copy constructor called\x1b[0m" << std::endl;
	if (this != &copy)
		*this = copy;
}
	
PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    // std::cout << "\x1b[38;5;138mPmergeMe Copy assignement operation called\x1b[0m" << std::endl;
	(void)copy;
    return (*this);
}

PmergeMe::~PmergeMe()
{
    // std::cout << "\x1b[38;5;124mPmergeMe destructor called\x1b[0m" << std::endl;
}

/* tools */
bool	is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
	
    while (it != s.end() && std::isdigit(*it))
		++it;
    return !s.empty() && it == s.end();
}

bool	isMax(const std::string &s)
{
	std::istringstream iss(s);
    long int nb;
    iss >> nb;
	
	if (nb > 2147483647)
	{
       	std::cout << "\x1b[38;5;205mError: \x1b[0m" << nb << " \x1b[38;5;205mnumber to high\x1b[0m" << std::endl;
		return (false);
	}
	return (true);
}

/* member functions */
void	PmergeMe::addNbr(const std::string &s)
{
	std::istringstream iss(s);
    long int nb;
    iss >> nb;

	vectArr.push_back(nb);
}

void	PmergeMe::addNbrDeq(const std::string &s)
{
	std::istringstream iss(s);
    long int nb;
    iss >> nb;

	dequeArr.push_back(nb);
}

void	PmergeMe::fillVec(std::vector<std::string> args)
{
	std::vector<std::string>::iterator it;

	for(it = args.begin(); it < args.end(); it++)
		addNbr(*it);
}

void	PmergeMe::fillDeq(std::vector<std::string> args)
{
	std::vector<std::string>::iterator it;

	for(it = args.begin(); it < args.end(); it++)
		addNbrDeq(*it);
}

bool	PmergeMe::parseArgs(int argc, char **argv)
{
	std::vector<std::string> args;
	std::vector<std::string>::iterator it;

	for (int i = 1; i < argc; i++)
		args.push_back(argv[i]);
	for(it = args.begin(); it < args.end(); it++)
	{
		if (is_number(*it) == false)
		{
        	std::cout << "\x1b[38;5;205mError: \x1b[0m" << *it << "\x1b[38;5;205m is not a digit\x1b[0m" << std::endl;
			return (false);
		}
	}
	for(it = args.begin(); it < args.end(); it++)
	{
		if (isMax(*it) == false)
			return (false);
	}
	fillVec(args);
	std::deque<std::string> deqArgs;
	fillDeq(args);
	return (true);
}

// void	PmergeMe::printList(std::vector<int> list)
// {
// 	std::vector<int>::iterator it;
	
// 	for (it = list.begin(); it < list.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

void	PmergeMe::fordJohnsonSortDeq(std::deque<int> &arr)
{
    int n = arr.size();
    bool flag = true;

	struct timeval d_time_start, d_time_end;
    gettimeofday(&d_time_start, NULL);

    while (flag) 
	{
        flag = false;
        int p = -1;
        for (int i = 0; i < n - 1; ++i)
		{
            if (arr[i] > arr[i + 1]) {
                p = i;
                break;
            }
        }

        if (p != -1) 
		{
            int q = p;
            for (int i = p + 1; i < n; ++i)
			{
                if (arr[i] < arr[p]) {
                    q = i;
                }
            }
            int temp = arr[q];
            arr.erase(arr.begin() + q);
            arr.insert(arr.begin() + p, temp);
            flag = true;
        }
    }

	gettimeofday(&d_time_end, NULL);
	long seconds = d_time_end.tv_sec - d_time_start.tv_sec;
    long microseconds = d_time_end.tv_usec - d_time_start.tv_usec;
    d_time = seconds + microseconds * 1e-6;
}

void	PmergeMe::fordJohnsonSortVec(std::vector<int> &arr)
{
    int n = arr.size();
    bool flag = true;

    struct timeval d_time_start, d_time_end;
    gettimeofday(&d_time_start, NULL);

    while (flag)
    {
        flag = false;
        int p = -1;
        for (int i = 0; i < n - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                p = i;
                break;
            }
        }

        if (p != -1)
        {
            int q = p;
            for (int i = p + 1; i < n; ++i)
            {
                if (arr[i] < arr[p])
                {
                    q = i;
                }
            }
            std::swap(arr[p], arr[q]); // Échange les éléments aux indices p et q
            flag = true;
        }
    }

    gettimeofday(&d_time_end, NULL);
    long seconds = d_time_end.tv_sec - d_time_start.tv_sec;
    long microseconds = d_time_end.tv_usec - d_time_start.tv_usec;
    d_time = seconds + microseconds * 1e-6;

}


void	PmergeMe::printDeq()
{
	int	n = dequeArr.size();
	
	if (n <= 4)
	{
		for (int i = 0; i < n; i++)
			std::cout << dequeArr[i] << " ";
	}
	else
	{
		for (int i = 0; i < 4; i++)
			std::cout << dequeArr[i] << " ";
		std::cout << "[...]" << std::endl;
	}
}

// void	PmergeMe::printVec()
// {
// 	int	n = vectArr.size();
	
// 	if (n <= 4)
// 	{
// 		for (int i = 0; i < n; i++)
// 			std::cout << vectArr[i] << " ";
// 	}
// 	else
// 	{
// 		for (int i = 0; i < 4; i++)
// 			std::cout << vectArr[i] << " ";
// 		std::cout << " [...]" << std::endl;
// 	}
// }

void	PmergeMe::displayRes()
{
	std::cout << "Before: " << PURPLE;
	printDeq();

	std::cout << EOC << "After: " << PURPLE;
	fordJohnsonSortDeq(dequeArr);
	printDeq();
    std::cout << EOC;

	std::cout << "Time to process a range of 5 elements with std::deque : " << GREEN <<  d_time << EOC << " us" << std::endl;
	
	fordJohnsonSortVec(vectArr);
	std::cout << "Time to process a range of 5 elements with std::vector : " << GREEN << v_time << EOC << " us" << std::endl;

}














