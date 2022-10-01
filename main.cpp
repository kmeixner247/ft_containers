/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/01 14:13:19 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "RBT.hpp"
#include <vector>
#include "map.hpp"
#include <map>
#include <iterator>
class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

template<typename T>
void print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores(ft::vector<T> vector)
{
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	for (ft::random_access_iterator<T> it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
}

template<typename T>
void print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores2(std::vector<T> vector)
{
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	for (size_t n = 0; vector.begin() + n != vector.end(); n++)
		std::cout << vector[n] << std::endl;
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
}
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

int main()
{   
	{

	ft::map<int, int> one;
	ft::map<int, int> two;
	// one.insert(ft::make_pair<int, int>(3, 5));
	std::cout<< "begin is " << &*(one.begin()) << std::endl;
	std::cout<< "end is " << &*(one.end()) << std::endl;
	one.insert(ft::make_pair<int, int>(6, 5));
	// two.insert(ft::make_pair<int, int>(6, 9));
	one.insert(ft::make_pair<int, int>(5, 9));
	two = one;
	std::cout << one.size() << std::endl;
	// one.erase(5);
	// one.erase(one.begin());
	std::cout << one.size() << std::endl;
	one.clear();
	ft::map<int, int>::iterator it = one.begin();
	std::cout << it->first << " " << it->second << std::endl;
	std::cout << "one == two: " << std::boolalpha	<< (one == two) << std::endl;
	std::cout << "one != two: " << std::boolalpha	<< (one != two) << std::endl;
	std::cout << "one < two: " << std::boolalpha << (one < two) << std::endl;
	// std::cout << (one == two) <<std::endl;;
	// int _ratio = 5000;
	// std::vector<int> v;
	// std::vector<int> v2;
	// {
	// 	ft::map<int, int> mp;
	// 	for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
	// 		mp.insert(ft::make_pair(i, j));
	// 	ft::map<int, int>::iterator it = mp.begin();
	// 	v.push_back(it->first);
	// 	mp.erase(it);
	// 	v.push_back(mp.size());
	// 	it = mp.begin();
	// 	mp.erase(++it);
	// 	v.push_back(mp.size());
	// 	it = mp.begin();
	// 	v.push_back(it->first);
	// 	ft::map<int, int>::iterator it4 = mp.begin();
	// 	for (; it4 != mp.end(); it4 = mp.begin())
	// 		mp.erase(it4);
	// 	v.push_back(mp.size());
	// 	ft::map<int, int> mp2;
	// 	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
	// 		mp2.insert(ft::make_pair(i, j));
	// 	ft::map<int, int>::iterator ittest = mp2.begin();
	// 	for (int i = 0; i < 2; ++i) ittest++;
	// 	mp2.erase(ittest);
	// 	ittest = mp2.begin();
	// 	for (int i = 0; i < 5; ++i) ittest++;
	// 	mp2.erase(ittest);
	// 	ft::map<int, int>::iterator it3 = mp2.begin();
	// 	for (; it3 != mp2.end(); ++it3)
	// 	{
	// 		v.push_back(it3->first);
	// 		v.push_back(it3->second);
	// 	}
	// }
	// {
	// 	std::map<int, int> mp;
	// 	for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
	// 		mp.insert(std::make_pair(i, j));
	// 	std::map<int, int>::iterator it = mp.begin();
	// 	v2.push_back(it->first);
	// 	mp.erase(it);
	// 	v2.push_back(mp.size());
	// 	it = mp.begin();
	// 	mp.erase(++it);
	// 	v2.push_back(mp.size());
	// 	it = mp.begin();
	// 	v2.push_back(it->first);
	// 	std::map<int, int>::iterator it4 = mp.begin();
	// 	for (; it4 != mp.end(); it4 = mp.begin())
	// 		mp.erase(it4);
	// 	v2.push_back(mp.size());
	// 	std::map<int, int> mp2;
	// 	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
	// 		mp2.insert(std::make_pair(i, j));
	// 	std::map<int, int>::iterator ittest = mp2.begin();
	// 	for (int i = 0; i < 2; ++i) ittest++;
	// 	mp2.erase(ittest);
	// 	ittest = mp2.begin();
	// 	for (int i = 0; i < 5; ++i) ittest++;
	// 	mp2.erase(ittest);
	// 	std::map<int, int>::iterator it3 = mp2.begin();
	// 	for (; it3 != mp2.end(); ++it3)
	// 	{
	// 		v2.push_back(it3->first);
	// 		v2.push_back(it3->second);
	// 	}
	// }
	// compare_print_vectors(v2, v);
	}
}