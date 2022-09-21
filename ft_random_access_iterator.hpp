/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:24:20 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/22 00:53:05 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
#define FT_RANDOM_ACCESS_ITERATOR_HPP
#include "ft_iterator.hpp"
#include "utils.hpp"
#include <iterator>
namespace ft
{
template<typename T>
class constant_random_access_iterator;

template<typename T>
class random_access_iterator : public iterator<random_access_iterator_tag, T>
{
public:
typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;

	random_access_iterator() : _current(0) {}
	random_access_iterator(random_access_iterator const &rhs) : _current(rhs._current) {}
	random_access_iterator(pointer p) : _current(p) {}
	pointer base() const
	{
		return (this->_current);
	}
	random_access_iterator &operator=(random_access_iterator<T> const &rhs)
	{
		this->_current = rhs._current;
		return (*this);
	}
	random_access_iterator &operator++()
	{
		this->_current++;
		return (*this);
	}
	random_access_iterator operator++(int)
	{
		random_access_iterator temp(*this);
		this->_current++;
		return(temp);
	}
	random_access_iterator &operator--()
	{
		this->_current--;
		return (*this);
	}
	random_access_iterator operator--(int)
	{
		random_access_iterator temp(*this);
		this->_current--;
		return(temp);
	}
	random_access_iterator operator+(difference_type n) const
	{
		return (this->_current + n);
	}
	
	random_access_iterator operator-(difference_type n) const
	{
		return (this->_current - n);
	}
	
	// difference_type operator-(random_access_iterator<T> rhs)
	// {
	// 	return (this->_current - rhs._current);
	// }

	bool operator<(random_access_iterator<T> rhs) const
	{
		return (this->_current < rhs.base());
	}
	
	bool operator<(constant_random_access_iterator<const T> rhs) const
	{
		return (this->_current < rhs.base());
	}

	bool operator>(random_access_iterator<T> rhs) const
	{
		return (this->_current > rhs.base());
	}
	
	bool operator>(constant_random_access_iterator<const T> rhs) const
	{
		return (this->_current > rhs.base());
	}

	bool operator<=(random_access_iterator<T> rhs) const
	{
		return (this->_current <= rhs.base());
	}
	
	bool operator<=(constant_random_access_iterator<const T> rhs) const
	{
		return (this->_current <= rhs.base());
	}
	
	bool operator>=(random_access_iterator<T> rhs) const
	{
		return (this->_current >= rhs.base());
	}
	
	bool operator>=(constant_random_access_iterator<const T> rhs) const
	{
		return (this->_current >= rhs.base());
	}
	
	bool operator==(random_access_iterator<T> rhs) const
	{
		return (this->_current == rhs.base());
	}
	
	bool operator==(constant_random_access_iterator<const T> rhs) const
	{
		return (this->_current == rhs.base());
	}
	
	bool operator!=(random_access_iterator<T> rhs) const
	{
		return (this->_current != rhs.base());
	}
	
	bool operator!=(constant_random_access_iterator<const T> rhs) const
	{
		return (this->_current != rhs.base());
	}

	random_access_iterator &operator+=(difference_type n)
	{
		this->_current += n;
		return (*this);
	}
	
	random_access_iterator &operator-=(difference_type n)
	{
		this->_current -= n;
		return (*this);
	}
	
	T &operator*() const
	{
		return (*(this->_current));
	}
	
	pointer operator->() const
	{
		return (this->_current);
	}

	reference operator[](difference_type n) const
	{
		return (*(this->_current + n));
	}
	
private:
	pointer _current;
};

template<typename T>
class constant_random_access_iterator : public iterator<random_access_iterator_tag, T>
{
public:

typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
typedef const typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
	constant_random_access_iterator() : _current(0) {}
	template <typename X>
	constant_random_access_iterator(const random_access_iterator<X> &rhs) : _current(rhs.base()) {}
	constant_random_access_iterator(const constant_random_access_iterator &rhs) : _current(rhs.base()) {}
	constant_random_access_iterator(pointer p) : _current(p) {}
	
	pointer base() const
	{
		return (this->_current);
	}
	constant_random_access_iterator &operator=(constant_random_access_iterator<T> const &rhs)
	{
		this->_current = rhs._current;
		return (*this);
	}
	constant_random_access_iterator &operator++()
	{
		this->_current++;
		return (*this);
	}
	constant_random_access_iterator operator++(int)
	{
		constant_random_access_iterator temp(*this);
		this->_current++;
		return(temp);
	}
	constant_random_access_iterator &operator--()
	{
		this->_current--;
		return (*this);
	}
	constant_random_access_iterator operator--(int)
	{
		constant_random_access_iterator temp(*this);
		this->_current--;
		return(temp);
	}
	constant_random_access_iterator operator+(difference_type n) const
	{
		return (this->_current + n);
	}
	
	constant_random_access_iterator operator-(difference_type n) const
	{
		return (this->_current - n);
	}
	
	// difference_type operator-(const constant_random_access_iterator<T> rhs)
	// {
	// 	return (this->_current - rhs._current);
	// }

	bool operator<(const random_access_iterator<T> rhs) const
	{
		return (this->_current < rhs._current);
	}
	
	bool operator<(const constant_random_access_iterator<T> rhs) const
	{
		return (this->_current < rhs._current);
	}

	bool operator>(const random_access_iterator<T> rhs) const
	{
		return (this->_current > rhs._current);
	}
	
	bool operator>(const constant_random_access_iterator<T> rhs) const
	{
		return (this->_current > rhs._current);
	}

	bool operator<=(const random_access_iterator<T> rhs) const
	{
		return (this->_current <= rhs._current);
	}
	
	bool operator<=(const constant_random_access_iterator<T> rhs) const
	{
		return (this->_current <= rhs._current);
	}
	
	bool operator>=(const random_access_iterator<T> rhs) const
	{
		return (this->_current >= rhs._current);
	}
	
	bool operator>=(const constant_random_access_iterator<T> rhs) const
	{
		return (this->_current >= rhs._current);
	}
	
	bool operator==(const random_access_iterator<T> rhs) const
	{
		return (this->_current == rhs._current);
	}
	
	bool operator==(const constant_random_access_iterator<T> rhs) const
	{
		return (this->_current == rhs._current);
	}
	
	bool operator!=(const random_access_iterator<T> rhs) const
	{
		return (this->_current != rhs._current);
	}
	
	bool operator!=(const constant_random_access_iterator<T> rhs) const
	{
		return (this->_current != rhs._current);
	}
	
	constant_random_access_iterator &operator+=(difference_type n)
	{
		this->_current += n;
		return (*this);
	}
	
	constant_random_access_iterator &operator-=(difference_type n)
	{
		this->_current -= n;
		return (*this);
	}
	
	T &operator*() const
	{
		return (*(this->_current));
	}
	
	pointer operator->() const
	{
		return (this->_current);
	}

	reference operator[](difference_type n) const
	{
		return (*(this->_current + n));
	}
	
private:
	pointer _current;
};

template<typename T>
random_access_iterator<T> operator+ (typename ft::iterator<random_access_iterator_tag, T>::difference_type n, random_access_iterator<T> &it)
{
	return (it.base() + n);
}

template<typename T>
random_access_iterator<T> operator+ (typename ft::iterator<random_access_iterator_tag, T>::difference_type n, constant_random_access_iterator<T> &it)
{
	return (it.base() + n);
}

template<typename T>
typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
{
	return (lhs.base() - rhs.base());
}

template<typename T>
typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, const constant_random_access_iterator<const T> &rhs)
{
	return (lhs.base() - rhs.base());
}

template<typename T>
typename random_access_iterator<T>::difference_type operator-(const constant_random_access_iterator<const T> &lhs, const random_access_iterator<T> &rhs)
{
	return (lhs.base() - rhs.base());
}

template<typename T>
typename random_access_iterator<T>::difference_type operator-(const constant_random_access_iterator<T> &lhs, const constant_random_access_iterator<T> &rhs)
{
	return (lhs.base() - rhs.base());
}
} //end of namespace
#endif