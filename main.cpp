/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:58:44 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/05 00:00:48 by kmeixner         ###   ########.fr       */
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
# include <sys/time.h>
typedef struct timeval	t_timeval;

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}
template <class T, class V, class C>
void fillMap(_map<T, V, C> &mp) {
	mp.insert(_make_pair(16, 3));
	mp.insert(_make_pair(8, 3));
	mp.insert(_make_pair(23, 3));
	mp.insert(_make_pair(7, 3));
	mp.insert(_make_pair(19, 3));
	mp.insert(_make_pair(29, 3));
	mp.insert(_make_pair(41, 3));
	mp.insert(_make_pair(4, 3));
	mp.insert(_make_pair(11, 3));
}
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
	{
	// ft::map<int, int> mp;
	// mp.insert(ft::make_pair(10, 10));
    // mp.insert(ft::make_pair(20, 20));
    // mp.insert(ft::make_pair(30, 30));
    // mp.insert(ft::make_pair(40, 40));
    // mp.insert(ft::make_pair(50, 50));
    // mp.insert(ft::make_pair(60, 60));
    // const ft::pair<ft::map<int, int>::const_iterator , ft::map<int, int>::const_iterator>& pair = mp.equal_range(10);
	// std::vector<int>v;
	// std::vector<int>v2;
	// int _ratio = 1;
	// {
	// 	_map<int, int> mp;
	// 	fillMap(mp);
	// 	for (_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v.push_back(it->first); }
	// 	for (_map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v.push_back(it->first); }
	// 	_map<int, int, std::greater<int> > mp1;
	// 	fillMap(mp1);
	// 	v.push_back(mp1.begin()->first);
	// 	mp1.erase(41);
	// 	v.push_back(mp1.begin()->first);
	// 	mp1.erase(29);
	// 	v.push_back(mp1.begin()->first);
	// 	_map<int, int, std::greater<int> > mp2;
	// 	mp2.insert(_make_pair(3, 3));
	// 	v.push_back(mp2.begin()->first);
	// 	mp2.erase(3);
	// 	if (mp2.begin() == mp2.end())
	// 		v.push_back(1);
	// 	_map<int, int, std::plus<int> > mp3;
	// 	fillMap(mp3);
	// 	for (_map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v.push_back(it->first); }
	// 	for (_map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v.push_back(it->first); }
	// 	_map<int, int, std::minus<int> > mp4;
	// 	fillMap(mp4);
	// 	for (_map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v.push_back(it->first); }
	// 	for (_map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v.push_back(it->first); }
	// 	_map<int, int, std::greater_equal<int> > mp5;
	// 	fillMap(mp5);
	// 	for (_map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v.push_back(it->first); }
	// 	for (_map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v.push_back(it->first); }
	// 	_map<int, int, std::multiplies<int> > mp6;
	// 	fillMap(mp6);
	// 	for (_map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v.push_back(it->first); }
	// 	for (_map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v.push_back(it->first); }
	// 	_map<int, int, std::bit_xor<int> > mp7;
	// 	fillMap(mp7);
	// 	for (_map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v.push_back(it->first); }
	// 	for (_map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v.push_back(it->first); }
	// 	std::map<int, int, std::logical_and<int> > mp8;
	// 	fillMap(mp8);
	// 	for (std::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v.push_back(it->first); }
	// 	v.push_back(mp1.size());
	// }
	// {
	// 	std::map<int, int> mp;
	// 	fillMap(mp);
	// 	for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) { v2.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp.end(); it != mp.begin(); it--) { v2.push_back(it->first); }
	// 	std::map<int, int, std::greater<int> > mp1;
	// 	fillMap(mp1);
	// 	v2.push_back(mp1.begin()->first);
	// 	mp1.erase(41);
	// 	v2.push_back(mp1.begin()->first);
	// 	mp1.erase(29);
	// 	v2.push_back(mp1.begin()->first);
	// 	std::map<int, int, std::greater<int> > mp2;
	// 	mp2.insert(std::make_pair(3, 3));
	// 	v2.push_back(mp2.begin()->first);
	// 	mp2.erase(3);
	// 	if (mp2.begin() == mp2.end())
	// 		v2.push_back(1);
	// 	std::map<int, int, std::plus<int> > mp3;
	// 	fillMap(mp3);
	// 	for (std::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++) { v2.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp3.end(); it != mp3.begin(); it--) { v2.push_back(it->first); }
	// 	std::map<int, int, std::minus<int> > mp4;
	// 	fillMap(mp4);
	// 	for (std::map<int, int>::iterator it = mp4.begin(); it != mp4.end(); it++) { v2.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp4.end(); it != mp4.begin(); it--) { v2.push_back(it->first); }
	// 	std::map<int, int, std::greater_equal<int> > mp5;
	// 	fillMap(mp5);
	// 	for (std::map<int, int>::iterator it = mp5.begin(); it != mp5.end(); it++) { v2.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp5.end(); it != mp5.begin(); it--) { v2.push_back(it->first); }
	// 	std::map<int, int, std::multiplies<int> > mp6;
	// 	fillMap(mp6);
	// 	for (std::map<int, int>::iterator it = mp6.begin(); it != mp6.end(); it++) { v2.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp6.end(); it != mp6.begin(); it--) { v2.push_back(it->first); }
	// 	std::map<int, int, std::bit_xor<int> > mp7;
	// 	fillMap(mp7);
	// 	for (std::map<int, int>::iterator it = mp7.begin(); it != mp7.end(); it++) { v2.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp7.end(); it != mp7.begin(); it--) { v2.push_back(it->first); }
	// 	std::map<int, int, std::logical_and<int> > mp8;
	// 	fillMap(mp8);
	// 	for (std::map<int, int>::iterator it = mp8.begin(); it != mp8.end(); it++) { v2.push_back(it->first); }
	// 	for (std::map<int, int>::iterator it = --mp8.end(); it != mp8.begin(); it--) { v2.push_back(it->first); }
	// 	v.push_back(mp1.size());
	// }
	// compare_print_vectors(v2, v);
	}
	// std::vector<int> v;
    // mp.clear();
    // for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
    //     mp.insert(_make_pair(i, j));
    // v.push_back(mp.size());
    // mp.clear();
    // v.push_back(mp.size());
    // _map<int, int>::iterator it = mp.begin();
    // if (it == mp.end())
    //     v.push_back(1);

	// {
	// 	_map<int, int> mp;
	// 	for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
	// 		mp.insert(_make_pair(i, j));
	// 	}
	// 	_map<int, int> mp2(mp.begin(), mp.end());
	// 	_map<int, int>::iterator it = mp2.begin();
	// 	for (int i = 0; i < 30 * _ratio; ++i, it++) {
	// 		v.push_back(it->first);
	// 		v.push_back(it->second);
	// 	}
	// }
	// {
	// 	std::map<int, int> mp;
	// 	for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
	// 		mp.insert(std::make_pair(i, j));
	// 	}
	// 	std::map<int, int> mp2(mp.begin(), mp.end());
	// 	std::map<int, int>::iterator it = mp2.begin();
	// 	for (int i = 0; i < 30 * _ratio; ++i, it++) {
	// 		v.push_back(it->first);
	// 		v.push_back(it->second);
	// 	}
	// }
// {
//     std::map<int, int> mp;
//     std::vector<int> v;
//     for (int i = 0, j = 10; i < 20 * _ratio; ++i, ++j)
//         mp.insert(std::make_pair(i, j));
//     std::map<int, int> mp2;
//     for (int i = 20 * _ratio, j = 200010; i < 40 * _ratio; ++i, ++j)
//         mp2.insert(std::make_pair(i, j));
//     mp2 = mp;
//     std::map<int, int>::iterator it = mp2.begin();
//     for (; it != mp2.end(); it++) {
//         v.push_back(it->first);
//         v.push_back(it->second);
//     }
//     v.push_back(mp2.size());
// }

// {
// 	_map<int, int> mp;
// 	std::vector<int> v;
// 	for (int i = 0, j = 10; i < 20 * _ratio; ++i, ++j)
// 		mp.insert(_make_pair(i, j));
// 	_map<int, int> mp2;
// 	for (int i = 20 * _ratio, j = 200010; i < 40 * _ratio; ++i, ++j)
// 		mp2.insert(_make_pair(i, j));
// 	mp2 = mp;
// 	_map<int, int>::iterator it = mp2.begin();
// 	for (; it != mp2.end(); it++) {
// 		v2.push_back(it->first);
// 		v2.push_back(it->second);
// 	}
// 	v2.push_back(mp2.size());
// }
	



// {
// 	std::map<int, int> mp;
// 	std::vector<int> v;
// 	for (int i = 0, j = 0; i < 25 * _ratio; ++i, ++j)
// 		mp.insert(std::make_pair(i, j));
// 	std::map<int, int> mp2;
// 	for (int i = 25 * _ratio, j = 0; i < 35 * _ratio; ++i, --j)
// 		mp.insert(std::make_pair(i, j));
// 	long *adr1 = reinterpret_cast<long *>(&mp);
// 	long *adr2 = reinterpret_cast<long *>(&mp2);
// 	mp.swap(mp2);
// 	if (reinterpret_cast<long *>(&mp) == adr1 && reinterpret_cast<long *>(&mp2) == adr2)
// 		v.push_back(1);
// 	v.push_back(mp2.size());
// 	std::map<int, int>::iterator it = mp2.begin();
// 	for (; it != mp2.end(); ++it) {
// 		v.push_back(it->first);
// 		v.push_back(it->second);
// 	}
// 	std::swap(mp, mp2);
// 	std::map<int, int>::iterator it2 = mp2.begin();
// 	for (; it2 != mp2.end(); ++it2) {
// 		v.push_back(it2->first);
// 		v.push_back(it2->second);
// 	}
// }

	int _ratio = 1;

t_timeval start;
{
	// gettimeofday(&start, NULL);
	// std::map<int,int> mp;
    // v.push_back(mp.erase(3));
    // for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
    //     mp.insert(std::make_pair(i, j));
    // std::map<int, int>::iterator it = mp.begin();
    // v.push_back(it->first);
    // v.push_back(mp.erase(-5));
    // v.push_back(mp.size());
    // v.push_back(mp.erase(0));
    // v.push_back(mp.size());
    // it = mp.begin();
    // v.push_back(it->first);
    // std::map<int, int>::iterator it4 = mp.begin();
    // for (; it4 != mp.end(); it4 = mp.begin()){
    //     mp.erase(it4->first);}
    // v.push_back(mp.erase(30 * _ratio - 1));
    // v.push_back(mp.size());
    // std::map<int, int> mp2;
    // for (int i = 0, j = 0; i < 10 ; ++i, ++j)
    //     mp2.insert(std::make_pair(i, j));
    // mp2.erase(2);
    // mp2.erase(7);
    // std::map<int, int>::iterator it3 = mp2.begin();
    // for (; it3 != mp2.end(); ++it3) {
    //     v.push_back(it3->first);
    //     v.push_back(it3->second);
    // }
	// std::cerr << "STD TOOK " << gettime(start) << "ms" << std::endl;
}

{
	// gettimeofday(&start, NULL);
	// _map<int, int>mp;
    // v2.push_back(mp.erase(3));
    // for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
    //     mp.insert(_make_pair(i, j));
    // _map<int, int>::iterator it = mp.begin();
    // v2.push_back(it->first);
    // v2.push_back(mp.erase(-5));
    // v2.push_back(mp.size());
    // v2.push_back(mp.erase(0));
    // v2.push_back(mp.size());
    // it = mp.begin();
    // v2.push_back(it->first);
    // _map<int, int>::iterator it4 = mp.begin();
	// std::cerr << mp.size() << std::endl;
    // for (; it4 != mp.end(); it4 = mp.begin())
    //     mp.erase(it4->first);
    // v2.push_back(mp.erase(30 * _ratio - 1));
    // v2.push_back(mp.size());
    // _map<int, int> mp2;
    // for (int i = 0, j = 0; i < 10 ; ++i, ++j)
    //     mp2.insert(_make_pair(i, j));
    // mp2.erase(2);
    // mp2.erase(7);
    // _map<int, int>::iterator it3 = mp2.begin();
    // for (; it3 != mp2.end(); ++it3) {
    //     v2.push_back(it3->first);
    //     v2.push_back(it3->second);
    // }
	// std::cerr << "FT TOOK " << gettime(start) << "ms" << std::endl;
	// ft::map<int, int> mp;
	// for (int i = 0; i < 10; i++)
	// 	mp.insert(ft::make_pair(i, i));
	// ft::map<int, int>::const_iterator it = mp.begin();
	// while (it != mp.end())
	// 	std::cerr << it++ << std::endl;
}
// ft::map<int, int> mp1;
// ft::map<int, int> mp2;
// mp1.insert(ft::make_pair(1,1));
// mp1.insert(ft::make_pair(2,1));
// mp1.insert(ft::make_pair(3,1));
// mp2.insert(ft::make_pair(1,1));
// mp2.insert(ft::make_pair(2,1));
// mp2.insert(ft::make_pair(3,1));
// ft::map<int, int>::const_iterator it = mp1.begin();
// std::cout << "1: " << it->first << std::endl;
// mp1.printBT();

// it++;
// std::cout << "2: " << it->first << std::endl;
// it++;
// std::cout << "3: " << it->first << std::endl;
// it++;
// std::cout << "end: " << it->first << std::endl;
// it--;
// it == --mp1.end();
// std::cout << "3: " << it->first << std::endl;
// it--;
// std::cout << "2: " << it->first << std::endl;
// it--;
// std::cout << "1: " << it->first << std::endl;
// it--;
// std::cout << "rend: " << it->first << std::endl;
// it++;
// std::cout << "1: " << it->first << std::endl;


// std::cerr<< std::boolalpha << (mp1.end() == mp2.end()) << std::endl;
// for (ft::map<int, int>::iterator it = mp1.begin(); it != mp1.end(); ++it)
// 	std::cout << it->first << std::endl;
// {
// 	std::map<int, int> mp;
//     for (int i = 0, j = 0; i < 5 * _ratio; ++i, ++j)
//         mp.insert(std::make_pair(i, j));

//     mp.erase(mp.begin(), --mp.end());
//     v.push_back(mp.begin()->first);
// }

// {
// 	_map<int, int> mp;
//     for (int i = 0, j = 0; i < 5 * _ratio; ++i, ++j)
//         mp.insert(_make_pair(i, j));
//     mp.erase(mp.begin(), --mp.end());
//     v2.push_back(mp.begin()->first);
// }



// compare_print_vectors(v, v2);
// std::vector<int> v1;
// std::vector<int> v2;
// {
// 	std::map<int, int> mp;
//     for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
//         mp.insert(std::make_pair(i, j));
//     }
//     std::map<int, int> mp2(mp.begin(), mp.end());
//     std::map<int, int>::iterator it = mp2.begin();
//     for (int i = 0; i < 30 * _ratio; ++i, it++) {
//         v1.push_back(it->first);
//         v1.push_back(it->second);
//     }
// }

// {

// 	_map<int, int> mp;
//     for (int i = 0, j = 10; i < 30 * _ratio; ++i, ++j) {
//         mp.insert(_make_pair(i, j));
//     }
// 	mp.printBT();
//     _map<int, int> mp2(mp.begin(), mp.end());
//     _map<int, int>::iterator it = mp2.begin();
//     for (int i = 0; i < 30 * _ratio; ++i, it++) {
//         v2.push_back(it->first);
//         v2.push_back(it->second);
//     }
// }
// compare_print_vectors(v1, v2);

// {
//     std::map<int, int> mp;
//     std::map<int, int> mpp;
//     fillMap(mpp);
//     for (std::map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++) { v1.push_back(it->first); }
//     for (std::map<int, int>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v1.push_back(it->first); }
//     std::map<int, int> mp0;
//     std::map<int, int>::iterator ii = mp0.insert(std::make_pair(3, 3)).first;
//     ii++;
//     v1.push_back((--ii)->first);
//     for (int i = 0, j = 10; i < 5; ++i, ++j)
//         mp.insert(std::make_pair(i, j));
//     std::map<int, int>::iterator it = mp.begin();
//     std::map<int, int>::iterator it2 = mp.end();
//     v1.push_back(it->first);
//     it++;
//     it++;
//     it++;
//     it++;
//     v1.push_back(it->first);
//     it++;
//     it--;
//     v1.push_back(it->first);
//     it2--;
//     v1.push_back(it2->first);
//     v1.push_back(it2 == it);
//     v1.push_back((--it2)->first);
//     v1.push_back((it2--)->first);
//     v1.push_back((it2++)->first);
//     v1.push_back((++it2)->first);
// }

// {
//     _map<int, int> mp;
//     _map<int, int> mpp;
//     fillMap(mpp);
//     for (_map<int, int>::iterator it = mpp.begin(); it != mpp.end(); it++) { v2.push_back(it->first); }
//     for (_map<int, int>::iterator it = --mpp.end(); it != mpp.begin(); it--) { v2.push_back(it->first); }
//     _map<int, int> mp0;
//     _map<int, int>::iterator ii = mp0.insert(_make_pair(3, 3)).first;
//     ii++;
//     v2.push_back((--ii)->first);
//     for (int i = 0, j = 10; i < 5; ++i, ++j)
//         mp.insert(_make_pair(i, j));
//     _map<int, int>::iterator it = mp.begin();
//     _map<int, int>::iterator it2 = mp.end();
//     v2.push_back(it->first);
//     it++;
//     it++;
//     it++;
//     it++;
//     v2.push_back(it->first);
//     it++;
//     it--;
//     v2.push_back(it->first);
//     it2--;
//     v2.push_back(it2->first);
//     v2.push_back(it2 == it);
//     v2.push_back((--it2)->first);
//     v2.push_back((it2--)->first);
//     v2.push_back((it2++)->first);
//     v2.push_back((++it2)->first);
// }
std::vector<int> v1;
std::vector<int> v2;

ft::map<int, std::string> mp;
mp.insert(ft::make_pair(0, "AAAAAAAAAA"));
mp.insert(ft::make_pair(1, "BBBBBBBBB"));
mp.insert(ft::make_pair(2, "CCCCCCCC"));
mp.insert(ft::make_pair(3, "DDDDDDD"));
mp.insert(ft::make_pair(4, "EEEEEE"));
mp.insert(ft::make_pair(5, "FFFFF"));
mp.insert(ft::make_pair(6, "GGGG"));
mp.insert(ft::make_pair(7, "HHH"));
mp.insert(ft::make_pair(8, "II"));
mp.insert(ft::make_pair(9, "J"));
std::cout << mp.size() << std::endl;
mp.erase(++mp.begin());
mp.erase(mp.begin());
mp.erase(--mp.end());
mp.erase(mp.begin(), ++(++(++mp.begin())));
mp.erase(--(--(--mp.end())), --mp.end());
mp[10] = "hyo";
mp[11] = "hya";
mp.printBT();
std::cout << (--(--(--mp.end())))->first << std::endl;
mp.erase(--(--(--mp.end())), mp.end());
mp.printBT();
mp[12] = "ONE";
std::cout << mp.size() << std::endl;

// compare_print_vectors(v1, v2);

}
// 	     RBT_iterator<      pair<const int, int>, RBT<pair<const int, int>, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > > >
// constant_RBT_iterator<const pair<const int, int>, RBT<pair<const int, int>, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > > >