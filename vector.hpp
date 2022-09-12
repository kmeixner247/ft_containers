/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:28:49 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/12 12:59:53 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMTESTS_HPP
#define RANDOMTESTS_HPP
#include <memory>
#include <iostream>
#include "ft_random_access_iterator.hpp"
#include "utils.hpp"
namespace ft
{
template <typename T, typename Alloc = std::allocator<T> >
class vector {
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename ft::random_access_iterator<T> iterator;	//convertible to const?
	// typedef typename ft::random_access_iterator<const T> const_iterator;	//?
	// typedef typename ft::reverse_iterator<iterator> reverse_iterator		//?
	// typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator		//?
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
public:

	// Empty container constructor / default constructor
	explicit vector(const allocator_type &alloc = allocator_type()) :_start(0), _end(0), _size(0), _allocator(alloc)
	{
	}
	
	// Fill constructor
	// Constructs a container with n elements. Each element is a copy of val.
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc)
	{
		this->_start = this->_allocator.allocate(n);
		this->_end = this->_start;
		for (size_type i = 0; i < n; i++)
			this->_allocator.construct(this->_end++, val);
	}

	// Range constructor
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), \
	typename enable_if<!is_integral<InputIterator>::value>::type* = 0) : _allocator(alloc)
	{
		this->_capacity = last - first;
		this->_size = last - first;
		this->_start = this->_allocator.allocate(this->_capacity);
		this->_end = this->_start;
		while (first != last)
			this->_allocator.construct(this->_end++, *(first++));
	}

	// Copy constructor
	vector (const vector& x)
	{
		(void) x;
		//?
	}

	// Destructor
	~vector()
	{
		this->clear();
		this->_allocator.deallocate(this->_start, this->_capacity);
	}
	
	vector& operator= (const vector& x)
	{
		if (*this == x)
			return (*this);
		this->clear();
		this->_allocator.deallocate(this->_start, this->_capacity);		//do more stuff, for real mate
		return (*this);
	}

	/*	
		ITERATOR RELATED MEMBER FUNCTIONS
	*/
	iterator begin()
	{
		iterator temp(this->_start);
		return (temp);
	}

	iterator end()
	{
		iterator temp(this->_end);
		return (temp);
	}
	
	iterator rbegin()	//change
	{
		iterator temp(this->_start);
		return (temp);
	}

	iterator rend()		//change
	{
		iterator temp(this->_end);
		return (temp);
	}
	
	iterator cbegin()	//change
	{
		iterator temp(this->_start);
		return (temp);
	}

	iterator cend()		//change
	{
		iterator temp(this->_end);
		return (temp);
	}
	
	iterator crbegin()	//change
	{
		iterator temp(this->_start);
		return (temp);
	}

	iterator crend()		//change
	{
		iterator temp(this->_end);
		return (temp);
	}
	/* 
		CAPACITY RELATED MEMBER FUNCTIONS
	*/
	
	// Returns size of the vector
	size_type size() const
	{
		return (this->_size);
	}

	//returns maximum possible size of a vector
	size_type max_size() const
	{
		return (this->_allocator.max_size());
	}

	// Resizes the container so that it contains n elements.
	// if n < size, vector is reduced to the first n elements, destroying all after
	// if capacity > n > size, content is expanded to n elements, all new ones initialized with val
	// if n > capacity, capacity is increased to n, new elements being initialized with val
	
	void resize (size_type n, value_type val = value_type())
	{
		if (n > this->_capacity)
		{
			
		}
		if (n < this->_size)
			while (this->_size-- > n)
				this->_allocator.destroy((this->_end--) - 1);
		if (n > this->_size)
			while (this->_size++ < n)
				this->_allocator.construct(this->_end++, val);
		//?
	}
	
	// Returns current allocated capacity of the vector
	size_type capacity() const
	{
		return (this->_capacity);
	}

	// Checks if vector is empty (size 0), returns true if empty, false if not
	bool empty() const
	{
		return (!(this->_size));
	}

	// If n > capacity, capacity is increased to n, otherwise does nothing
	void reserve (size_type n)
	{
		if (n > this->max_size())
			throw std::length_error("allocator<T>::allocate(size_t n) \'n\' exceeds maximum supported size");
		if (n > this->_capacity)
		{
			pointer tempstart = this->_start;
			pointer tempend = this->_end;

			this->_start = this->_allocator.allocate(n);
			this->_end = this->_start;
			while (tempstart != tempend)
			{
				this->_allocator.construct(this->_end++, *tempstart);
				this->_allocator.destroy(tempstart);
				tempstart++;
			}	
			this->_allocator.deallocate(tempstart - this->_size, this->_capacity);
			this->_size = this->_end - this->_start;
			this->_capacity = n;
		}
	}

	// Pretty self-explanatory innit
	void shrink_to_fit()
	{
		
	}
	/*
		MODIFIER MEMBER FUNCTIONS
	*/
	// assign
	// push_back
	// pop_back
	// insert single
	iterator insert (iterator position, const value_type& val)
	{
		pointer temp;
		size_type distance = position - this->begin();
		
		if (this->_size == this->_capacity)
			this->reserve(this->_capacity * 2);
		if (position < this->_end)
		{
			temp = this->_end;
			this->_end++;
			while (this->_start + distance != temp)
			{
				this->_allocator.construct(temp, *(temp - 1));
				this->_allocator.destroy(temp - 1);
				temp--;
			}
			this->_allocator.construct(temp, val);
			return (this->begin() + distance);
		}
		else
		{
			this->_allocator.construct(&*position, val);
			this->_end++;
			return (position);
		}
	}
	// insert fill
	// void insert (iterator position, size_type n, const value_type& val)
	// {
	// 	pointer temp;
	// 	size_type distance = position - this->begin();
		
	// 	if (this->_size + n > this->_capacity)
	// 		this->reserve(this->_capacity * 2);
	// 	if (position < this->_end)
	// 	{
	// 		temp = this->_end;
	// 		this->_end++;
	// 		while (this->_start + distance != temp)
	// 		{
	// 			this->_allocator.construct(temp, *(temp - 1));
	// 			this->_allocator.destroy(temp - 1);
	// 			temp--;
	// 		}
	// 		this->_allocator.construct(temp, val);
	// 		return (this->begin() + distance);
	// 	}
	// 	else
	// 	{
	// 		this->_allocator.construct(&*position, val);
	// 		this->_end++;
	// 		return (position);
	// 	}
	// }
	// insert range
	// erase
	// swap
	// clear
	void clear()
	{
		this->_end--;
		while (this->_start && this->_end != this->_start)
			this->_allocator.destroy(this->_end--);
		this->_allocator.destroy(this->_start);
	}
	// emplace
	// emplace_back
	
private:
	pointer			_start;
	pointer 		_end;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_allocator;
};

}	//end of namespace
#endif

