/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:10:02 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/28 11:48:35 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP
#include <memory>
#include <iostream>
// #include "ft_random_access_iterator.hpp"
namespace ft
{
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

struct output_iterator_tag {};
struct input_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template <class Iterator>
class iterator_traits
{
public:
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};

template <class T>
class iterator_traits<T*>
{
public:
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template <class T> 
class iterator_traits<const T*>
{
public:
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template <class Iterator> 
class reverse_iterator
{
public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename iterator_traits<Iterator>::value_type value_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	typedef typename iterator_traits<Iterator>::reference reference;
	
	reverse_iterator() : _iterator()
	{
	}

	explicit reverse_iterator (iterator_type it) : _iterator(it)
	{
	}

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iterator(rev_it.base())
	{
	}

	iterator_type base() const
	{
		return (this->_iterator);
	}
	
	reverse_iterator &operator=(const reverse_iterator &rhs)
	{
		this->_iterator = rhs.base();
		return (*this);
	}

	reference operator*() const
	{
		iterator_type temp(this->_iterator);
		temp--;
		return (*temp);
	}

	reverse_iterator operator+ (difference_type n) const
	{
		return (reverse_iterator(this->_iterator - n));
	}

	reverse_iterator& operator++()
	{
		this->_iterator--;
		return (*this);
	}

	reverse_iterator  operator++(int)
	{
		reverse_iterator temp = *this;
		++(*this);
		return temp;
	}

	reverse_iterator& operator+= (difference_type n)
	{
		this->_iterator -= n;
		return (*this);
	}

	reverse_iterator operator- (difference_type n) const
	{
		return (reverse_iterator(this->_iterator + n));
	}

	reverse_iterator& operator--()
	{
		this->_iterator++;
		return (*this);
	}
	
	reverse_iterator  operator--(int)
	{
		reverse_iterator temp = *this;
		--(*this);
		return temp;
	}

	reverse_iterator& operator-= (difference_type n)
	{
		this->_iterator += n;
		return (*this);
	}

	pointer operator->() const
	{
		return (&(operator*()));
	}

	reference operator[] (difference_type n) const
	{
		return (this->base()[-n - 1]);
	}
private:
	iterator_type _iterator;
};

template <class Iterator>
bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class left, class right>
bool operator== (const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
{
	return (lhs.base() == rhs.base());
}

template <class Iterator>
bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class left, class right>
bool operator!= (const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
{
	return (lhs.base() != rhs.base());
}

template <class Iterator>
bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class left, class right>
bool operator< (const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
{
	return (lhs.base() > rhs.base());
}

template <class Iterator>
bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class left, class right>
bool operator<= (const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class Iterator>
bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class left, class right>
bool operator> (const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
{
	return (lhs.base() < rhs.base());
}

template <class Iterator> 
bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class left, class right> 
bool operator>= (const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class Iterator>
reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
	return (rev_it + n);
}

template <typename left, typename right>
typename reverse_iterator<left>::difference_type operator-(const reverse_iterator<left>& lhs, const reverse_iterator<right>& rhs)
{
	return (rhs.base() - lhs.base());
}

}	//end of namespace
#endif