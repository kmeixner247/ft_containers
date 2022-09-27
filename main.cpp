/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/28 00:25:42 by kmeixner         ###   ########.fr       */
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
	// ft::RBT<int> test;
	// test.insert(10);
	// test.insert(30);
	// test.insert(25);
	// test.insert(40);
	// test.insert(-10);
	// test.insert(4);
	// test.insert(3);
	// test.insert(9);
	// test.insert(2);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(4);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(40);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(30);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(2);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(9);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(25);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(3);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(-10);
	// test.printBT(test.getRoot());
	// std::cout << test.size() << std::endl;
	// std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	// test.delete_by_value(10);
	// std::cout << test.size() << std::endl;
	// ft::RBT<char> test2;
	// test2.insert('A');
	// test2.insert('J');
	// test2.insert('R');
	// test2.insert('X');
	// test2.printBT(test2.getRoot());
	
	// test.delete_by_value(2);
	// test.printBT(test.getRoot());
	ft::map<int, std::string> test;
	test.insert(ft::make_pair<int, std::string>(5, "hello"));
	test.insert(ft::make_pair<int, std::string>(1, "hello"));
	test.insert(ft::make_pair<int, std::string>(8, "hello"));
	test.insert(ft::make_pair<int, std::string>(1234, "hello"));
	test.insert(ft::make_pair<int, std::string>(33, "hello"));
	test.insert(ft::make_pair<int, std::string>(-42, "hello"));
	test.insert(ft::make_pair<int, std::string>(42, "hello"));
	test.tempprint();
}