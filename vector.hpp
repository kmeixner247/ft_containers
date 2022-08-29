/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:28:49 by kmeixner          #+#    #+#             */
/*   Updated: 2022/08/27 13:37:12 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMTESTS_HPP
#define RANDOMTESTS_HPP
#include <memory>
#include <iostream>
#include "ft_random_access_iterator.hpp"
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
	typedef typename ft::random_access_iterator<T> iterator;				//convertible to const?
	// typedef typename ft::random_access_iterator<const T> const_iterator;	//?
	// typedef typename ft::reverse_iterator<iterator> reverse_iterator		//?
	// typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator		//?
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
public:

	// Empty container constructor / default constructor
	explicit vector(const allocator_type &alloc = allocator_type()) :_start(nullptr), _end(nullptr), _allocator(alloc)
	{
	}
	
	// Fill constructor
	// Constructs a container with n elements. Each element is a copy of val.
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _allocator(alloc)
	{
		this->_start = this->_allocator.allocate(n);
		this->_end = this->_start;
		for (size_type i = 0; i < n; i++)
		{
			this->_allocator.construct(this->_end, val);
			(this->_end)++;
		}
	}

	// Range constructor
	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _allocator(alloc)
	{
		this->_capacity = last - first;
		this->_start = this->_allocator.allocate(this->_capacity);
		std::cout << n << " from range constructor." << std::endl;
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
		std::cout << "destructor called." << std::endl;
		//?
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
	// check cplusplus for exact mechanics
	void resize (size_type n, value_type val = value_type())
	{
		(void)n;
		(void)val;
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
		(void)n;
		//?
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
	// insert
	// erase
	// swap
	// clear
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

