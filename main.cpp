/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/08/27 13:35:32 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
int main()
{
	std::vector<int> OG1;
	std::vector<char> OG2(5, 'X');
	ft::vector<int> testvector;
	ft::vector<char> testvector2(25, 'X');
	for (int i = 0; testvector2.begin() + i != testvector2.end(); i++)
		std::cout << "i: " << i << " content: " << *(testvector2.begin() + i) << std::endl;
	std::cout << (testvector2.begin() - testvector2.end()) << std::endl;
	std::cout << (testvector2.begin() < testvector2.end()) << std::endl;
	std::cout << (testvector2.begin() > testvector2.end()) << std::endl;
	std::cout << (testvector2.begin() <= testvector2.end()) << std::endl;
	std::cout << (testvector2.begin() >= testvector2.end()) << std::endl;
	std::cout << (testvector2.begin() <= testvector2.begin()) << std::endl;
	std::cout << (testvector2.begin() >= testvector2.begin()) << std::endl;
	std::cout << (testvector2.begin() == testvector2.begin()) << std::endl;
	std::cout << (testvector2.begin() == testvector2.end()) << std::endl;
	std::cout << (testvector2.begin() != testvector2.begin()) << std::endl;
	std::cout << (testvector2.begin() != testvector2.end()) << std::endl;
	std::cout << OG1.max_size() << std::endl;
	std::cout << OG2.max_size() << std::endl;
	std::cout << testvector.max_size() << std::endl;
	std::cout << testvector2.max_size() << std::endl;
	ft::vector<char> abcdef(testvector2.begin(), testvector2.end());
}