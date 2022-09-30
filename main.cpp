/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/30 14:40:19 by kmeixner         ###   ########.fr       */
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
	std::cout << one.size() << std::endl;
	one.erase(5);
	std::cout << one.size() << std::endl;
	one.clear();
	ft::map<int, int>::iterator it = one.begin();
	std::cout << it->first << " " << it->second << std::endl;
	std::cout << "one == two: " << std::boolalpha	<< (one == two) << std::endl;
	std::cout << "one != two: " << std::boolalpha	<< (one != two) << std::endl;
	std::cout << "one < two: " << std::boolalpha << (one < two) << std::endl;
	// std::cout << (one == two) <<std::endl;;
	int _ratio = 5000;

	// ft::map<int, int> mp1;
	// std::vector<int> v1;
    // for (int i = 0, j = 0; i < 100 * _ratio; ++i, ++j)
    //     mp1.insert(ft::make_pair(i, j));
    // v1.push_back(mp1.size());
    // for (int i = 0; i < 43 * _ratio; ++i)
    //     mp1.erase(i);
    // v1.push_back(mp1.size());

	
	// std::map<int, int> mp2;
	// std::vector<int> v2;
    // for (int i = 0, j = 0; i < 100 * _ratio; ++i, ++j)
    //     mp2.insert(std::make_pair(i, j));
    // v2.push_back(mp2.size());
    // for (int i = 0; i < 43 * _ratio; ++i)
    //     mp2.erase(i);
    // v2.push_back(mp2.size());
	// print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores2(v1);
	// print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores2(v2);
	}
}