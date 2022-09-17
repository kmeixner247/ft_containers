/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/17 20:03:59 by kmeixner         ###   ########.fr       */
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
	std::cout << (one == two) << std::endl;
	ft::vector<int> three(one);
	std::cout << (one == three) << std::endl;
	std::string s = "approvjvorppa";
	std::cout << (ft::equal(s.begin(), s.begin() + s.size()/2, s.rbegin())) << std::endl;
	
    std::vector<int> result, result_2;
	ft::vector<int> V_int1, V_int2, V_int3;
	ft::vector<std::string> V_str1, V_str2, V_str3;
	V_int3.push_back(1);
	V_str1.push_back("aa");
	V_str2.push_back("ab");
	std::cout <<  "should be true: " << std::boolalpha << (V_int1 == V_int2) << std::endl;
	V_int1.push_back(1);
	std::cout <<  "should be false: " << std::boolalpha << (V_int1 == V_int2) << std::endl;
	V_int2.push_back(2);
	std::cout <<  "should be false: " << std::boolalpha << (V_int1 == V_int2) << std::endl;
	std::cout <<  "should be true: " << std::boolalpha << (V_int1 == V_int3) << std::endl;
	result_2.push_back(V_int1 == V_int3);
	result_2.push_back(V_str1 == V_str2);
	V_str3 = V_str2;
	std::cout <<  "should be false: " << std::boolalpha << (V_str1 == V_str2) << std::endl;
	std::cout <<  "should be true: " << std::boolalpha << (V_str2 == V_str3) << std::endl;
	std::cout << V_int1.at(0) << std::endl;
	// for (size_t i = 0; result_2.begin() + i != result_2.end(); i++)
	// 	std::cout <<"x: "<< result_2.at(i) << std::endl;
	// std::vector<int> two;
	// one.reserve(one.max_size() + 1);

}