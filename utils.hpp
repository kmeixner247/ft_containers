/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:06:12 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/29 17:16:25 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP


namespace ft
{
template<bool, class T = void>
struct enable_if {};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
};


template <class T, T v>
class integral_constant {
public:
	static const T value = v;
	typedef T value_type;
	typedef integral_constant<T,v> type;
	operator value_type() {return (this->value);}
};

typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;

template <class T> struct is_integral : public false_type {};

template <> struct is_integral<bool> : public true_type {};
template <> struct is_integral<char> : public true_type {};
template <> struct is_integral<char16_t> : public true_type {};
template <> struct is_integral<char32_t> : public true_type {};
template <> struct is_integral<wchar_t> : public true_type {};
template <> struct is_integral<signed char> : public true_type {};
template <> struct is_integral<short int> : public true_type {};
template <> struct is_integral<int> : public true_type {};
template <> struct is_integral<long int> : public true_type {};
template <> struct is_integral<long long int> : public true_type {};
template <> struct is_integral<unsigned char> : public true_type {};
template <> struct is_integral<unsigned short int> : public true_type {};
template <> struct is_integral<unsigned int> : public true_type {};
template <> struct is_integral<unsigned long int> : public true_type {};
template <> struct is_integral<unsigned long long int> : public true_type {};


template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1!=last1) {
	if (!(*first1 == *first2))
		return false;
	++first1;
	++first2;
	}
	return true;
}
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1!=last1) {
	if (!pred(*first1,*first2))
		return false;
	++first1; ++first2;
	}
	return true;
}
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	while (first1!=last1)
	{
		if (first2==last2 || comp(*first2, *first1)) return false;
		else if (comp(*first1, *first2)) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

template <class T1, class T2>
class pair
{
public:
	typedef T1 first_type;
	typedef T2 second_type;
	
	first_type first;
	second_type second;

	pair() : first(), second() {};
	template<class U, class V>
	pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
	pair(const first_type& a, const second_type& b) : first(a), second(b) {};
	pair& operator= (const pair& pr)
	{
		this->first = pr.first;
		this->second = pr.second;
		return (*this);
	}
};

template <class T1, class T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first==rhs.first && lhs.second==rhs.second);
}

template <class T1, class T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(lhs==rhs));
}

template <class T1, class T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
}

template <class T1, class T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(rhs<lhs));
}

template <class T1, class T2>
bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return rhs<lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return !(lhs<rhs);
}

template <class T1, class T2> 
pair<T1,T2> make_pair (T1 x, T2 y)
{
	return (pair<T1,T2>(x,y));
}

template<typename T>
T get_key(T *key)
{
	return (*key);
}

template<typename key, typename value>
key get_key(ft::pair<key, value> *pair)
{
	return (pair->first);
}
}		//namespace end
#endif