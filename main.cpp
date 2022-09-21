/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/22 01:14:39 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
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

void print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores(ft::vector<int> vector)
{
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	for (ft::random_access_iterator<int> it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
}

void print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores2(std::vector<int> vector)
{
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
	for (size_t n = 0; vector.begin() + n != vector.end(); n++)
		std::cout << vector[n] << std::endl;
	std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
}

int main()
{   
	// size_t _ratio = 1;
	// {
	// 	ft::vector<int> v;
	// 	ft::vector<int> vector;
	// 	vector.assign(9900 * _ratio, 1);
	// 	vector.resize(5000 * _ratio);
	// 	vector.reserve(5000 * _ratio);
	// 	v.push_back(vector.size());
	// 	v.push_back(vector.capacity());
	// 	vector.resize(7000 * _ratio);
	// 	v.push_back(vector.size());
	// 	v.push_back(vector.capacity());
	// 	vector.resize(15300 * _ratio, int());
	// 	v.push_back(vector.size());
	// 	v.push_back(vector.capacity());
	// 	v.push_back(vector[65]);
	// 	print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores(v);
	// }
	// 	std::vector<int> v;
	// 	std::vector<int> vector;
	// 	size_t _ratio = 10000;
	// 	vector.assign(9900 * _ratio, 1);
	// 	vector.resize(5000 * _ratio);
	// 	vector.reserve(5000 * _ratio);
	// 	v.push_back(vector.size());
	// 	v.push_back(vector.capacity());
	// 	vector.resize(7000 * _ratio);
	// 	v.push_back(vector.size());
	// 	v.push_back(vector.capacity());
	// 	std::cout << vector.capacity() << std::endl;
	// 	vector.resize(15300 * _ratio, int());
	// 	std::cout << 15300 * _ratio << "???" << vector.capacity() << " wtf " << std::endl;
	// 	v.push_back(vector.size());
	// 	v.push_back(vector.capacity());
	// 	v.push_back(vector[65]);
	// 	print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores2(v);
	// {
	// }
	// std::cout << (std::is_integral<long long>() == ft::is_integral<long long>()) << std::endl;
	ft::vector<int> vct3;
	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores(vct3);
	std::cout << vct3.capacity() << std::endl;
	vct3.insert(vct3.begin() + 1, 2, 111);
	print_the_fucking_vector_mate_bro_yo_whatever_haha_underscores(vct3);
	}