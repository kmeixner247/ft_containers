/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/13 21:06:37 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
int main()
{
	// std::vector<int> OG1;
	// std::vector<char> OG2(5, 'X');
	// ft::vector<int> testvector;
	// ft::vector<char> testvector2(25, 'X');
	// for (int i = 0; testvector2.begin() + i != testvector2.end(); i++)
	// 	std::cout << "i: " << i << " content: " << *(testvector2.begin() + i) << std::endl;
	// std::cout << (testvector2.begin() - testvector2.end()) << std::endl;
	// std::cout << (testvector2.begin() < testvector2.end()) << std::endl;
	// std::cout << (testvector2.begin() > testvector2.end()) << std::endl;
	// std::cout << (testvector2.begin() <= testvector2.end()) << std::endl;
	// std::cout << (testvector2.begin() >= testvector2.end()) << std::endl;
	// std::cout << (testvector2.begin() <= testvector2.begin()) << std::endl;
	// std::cout << (testvector2.begin() >= testvector2.begin()) << std::endl;
	// std::cout << (testvector2.begin() == testvector2.begin()) << std::endl;
	// std::cout << (testvector2.begin() == testvector2.end()) << std::endl;
	// std::cout << (testvector2.begin() != testvector2.begin()) << std::endl;
	// std::cout << (testvector2.begin() != testvector2.end()) << std::endl;
	// std::cout << OG1.max_size() << std::endl;
	// std::cout << OG2.max_size() << std::endl;
	// std::cout << testvector.max_size() << std::endl;
	// std::cout << testvector2.max_size() << std::endl;
	// ft::vector<char> abcdef(testvector2.begin(), testvector2.end());
	// for (int i = 0; abcdef.begin() + i != abcdef.end(); i++)
	// 	std::cout << "i: " << i << " content: " << *(abcdef.begin() + i) << std::endl;
	ft::vector<int> zero(5, 1);
	ft::vector<int> one(zero);
	std::cout << "capacity: " << one.capacity() << " size: " << one.size() << std::endl;
	for (int i = 0; one.begin() + i != one.end(); i++)
		std::cout << "i: " << i << " content: " << *(one.begin() + i) << " address: " << &*(one.begin() + i) << std::endl;
	
	// one.insert(one.end(), 12, 2);
	ft::vector<int> two(33, 19);
	// one.assign(5, 19);
	// one.insert(one.begin() + 5, two.begin(), two.end());
	// one.push_back(3);
	one.erase(one.begin() + 1, one.end());
	one.push_back(5);
	one.push_back(8);
	one.push_back(2);
	one.push_back(123);
	one.push_back(-2);
	one.push_back(0);
	one.pop_back();
	one.pop_back();
	// one.erase(one.begin());
	
	std::cout << "capacity: " << one.capacity() << " size: " << one.size() << std::endl;
	for (int i = 0; one.begin() + i != one.end(); i++)
	{
		std::cout << "i: " << i << " content: " << *(one.begin() + i) << " address: " << &*(one.begin() + i) << std::endl;
	}
	std::cout << "capacity: " << one.capacity() << " size: " << one.size() << std::endl;
	std::cout << "???" << std::endl;
	// std::vector<int> two;
	// one.reserve(one.max_size() + 1);

}