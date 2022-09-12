/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:24:20 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/11 18:00:02 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
#define FT_RANDOM_ACCESS_ITERATOR_HPP
#include "ft_iterator.hpp"
#include <iterator>
namespace ft
{
template<typename T>
class random_access_iterator : public iterator<random_access_iterator_tag, T>
{
typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;

public:
	random_access_iterator() : _current(0) {}
	random_access_iterator(random_access_iterator const &rhs) : _current(rhs._current) {}
	random_access_iterator(pointer p) : _current(p) {}
	random_access_iterator<T> &operator=(random_access_iterator<T> const &rhs)
	{
		this->_current = rhs->_current;
		return (*this);
	}
	random_access_iterator<T> &operator++()
	{
		this->_current++;
		return (*this);
	}
	random_access_iterator<T> operator++(int)
	{
		random_access_iterator<T> temp(*this);
		this->_current++;
		return(temp);
	}
	random_access_iterator<T> &operator--()
	{
		this->_current--;
		return (*this);
	}
	random_access_iterator<T> operator--(int)
	{
		random_access_iterator<T> temp(*this);
		this->_current--;
		return(temp);
	}
	random_access_iterator<T> operator+(difference_type n)	//size_type?
	{
		return (this->_current + n);
	}
	
	random_access_iterator<T> operator-(difference_type n)	//size_type?
	{
		return (this->_current - n);
	}
	
	difference_type operator-(random_access_iterator<T> rhs)	//size_type?
	{
		return (this->_current - rhs._current);
	}

	bool operator<(random_access_iterator<T> rhs)
	{
		return (this->_current < rhs._current);
	}

	bool operator>(random_access_iterator<T> rhs)
	{
		return (this->_current > rhs._current);
	}

	bool operator<=(random_access_iterator<T> rhs)
	{
		return (this->_current <= rhs._current);
	}
	
	bool operator>=(random_access_iterator<T> rhs)
	{
		return (this->_current >= rhs._current);
	}
	
	bool operator==(random_access_iterator<T> rhs)
	{
		return (this->_current == rhs._current);
	}
	
	bool operator!=(random_access_iterator<T> rhs)
	{
		return (this->_current != rhs._current);
	}

	
	
	T &operator*()
	{
		return (*(this->_current));
	}
	
private:
	pointer _current;
};

} //end of namespace
#endif