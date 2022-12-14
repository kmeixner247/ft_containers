/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/05 09:16:36 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "RBT.hpp"
#include <vector>
#include "map.hpp"
#include <map>
#include <iterator>
#define _map ft::map
#define _make_pair ft::make_pair
#define _pair ft::pair
#include <sys/time.h>
typedef struct timeval	t_timeval;

template<typename T>
void compare_print_vectors(std::vector<T> std, std::vector<T> ft)
{
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	for (size_t n = 0; std.begin() + n != std.end(); n++)
	{
		std::cout << ((std[n] == ft[n]) ? "\x1B[32m" : "\x1B[31m");
		std::cout << n << ":\tSTD: " << std[n] << " FT: " << ft[n] << std::endl;
		std::cout << "\033[0m";
	}
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
}


int	gettime(t_timeval start)
{
	t_timeval	tv;
	int			tdiff;

	gettimeofday(&tv, NULL);
	tdiff = (tv.tv_sec - start.tv_sec) * 1000;
	tdiff += (tv.tv_usec - start.tv_usec) / 1000;
	return (tdiff);
}

int main()
{
	
}
