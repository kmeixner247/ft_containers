/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:28:49 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/13 21:11:02 by kmeixner         ###   ########.fr       */
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
	explicit vector(const allocator_type &alloc = allocator_type()) :_start(0), _end(0), _allocator(alloc)
	{
	}
	
	// Fill constructor
	// Constructs a container with n elements. Each element is a copy of val.
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _capacity(n), _allocator(alloc)
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
		this->_start = this->_allocator.allocate(this->_capacity);
		this->_end = this->_start;
		while (first != last)
			this->_allocator.construct(this->_end++, *(first++));
	}

	// Copy constructor
	vector (const vector& x) : _start(0), _end(0), _capacity(0)
	{
		this->insert(this->begin(), x.begin(), x.end()); //gonna need const iterators for this
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
		return (this->_end - this->_start);
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
			this->reserve(n);
		if (n < this->size())
			for (size_type i = this->size(); i > n; i--)
				this->_allocator.destroy((this->_end--) - 1);
		if (n > this->size())
			for (size_type i = this->size(); i < n; i++)
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
		return (!(this->size()));
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
			this->_allocator.deallocate(tempstart - this->size(), this->_capacity);
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
	template <class InputIterator>
  	void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
	{
		this->clear();
		this->insert(this->_start, first, last);
	}

	void assign (size_type n, const value_type& val)
	{
		this->clear();
		this->insert(this->_start, n, val);
	}
	// push_back
	void push_back (const value_type& val)
	{
		this->insert(this->_end, val);
	}
	// pop_back
	void pop_back()
	{
		this->erase(this->end() - 1);
	}
	// insert single
	iterator insert (iterator position, const value_type& val)
	{
		pointer temp;
		size_type distance = position - this->begin();
		
		if (this->size() == this->_capacity)
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
	void insert (iterator position, size_type n, const value_type& val)
	{
		pointer temp;
		size_type distance = position - this->begin();
		if (this->size() + n > this->_capacity * 2)
			this->reserve(this->size() + n);
		else if (this->size() + n > this->_capacity)
			this->reserve(this->_capacity * 2);
		if (distance < this->size())
		{
			temp = this->_end + n - 1;
			this->_end += n;
			while (this->_start + distance != temp)
			{
				this->_allocator.construct(temp, *(temp - n));
				this->_allocator.destroy(temp - n);
				temp--;
			}
			for (size_type i = 0; i < n; i++)
				this->_allocator.construct(temp + i, val);
		}
		else
		{
			for (size_type i = 0; i < n; i++)
			{
				this->_allocator.construct(this->_start + distance + i, val);
				this->_end++;
			}
		}
	}
	// insert range
	template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last)
	{
		pointer temp;
		size_type n = last - first;
		size_type distance = position - this->begin();
		if (this->size() + n > this->_capacity * 2)
			this->reserve(this->size() + n);
		else if (this->size() + n > this->_capacity)
			this->reserve(this->_capacity * 2);
		if (distance < this->size())
		{
			temp = this->_end + n - 1;
			this->_end += n;
			for (size_type i = 0; (this->_start + distance + i) < this->_end; i++)
			{
				this->_allocator.construct(temp, *(temp - n));
				this->_allocator.destroy(temp - n);
				temp--;
			}
			for (size_type i = 0; i < n; i++)
			{
				this->_allocator.construct(this->_start + distance + i, *(first + i));
			}
		}
		else
		{
			for (; first != last; first++)
				this->insert(this->end(), *first);
		}
	}
	// erase
	iterator erase (iterator position)
	{
		pointer p = &*position;
		if (this->size() == 1)
			this->_allocator.destroy(p);
		else
		{
			while (p + 1 != this->_end)
			{
				this->_allocator.construct(p, *(p + 1));
				this->_allocator.destroy(p + 1);
				p++;
			}
		}	
		this->_end--;
		return (0);
	}

	iterator erase (iterator first, iterator last)
	{
		pointer pfirst = &*first;
		pointer plast = &*last;
		size_type distance = last - first;
		plast--;
		while (plast-- != pfirst)
		{
			this->_allocator.destroy(plast);
		}
		while (pfirst + distance < this->_end)
		{
			this->_allocator.construct(pfirst, *(pfirst + distance));
			this->_allocator.destroy(pfirst + distance);
			pfirst++;
		}
		this->_end -= distance;
		return (first);
	}
	// swap
	// clear
	void clear()
	{
		for (size_type i = 0; i < this->size(); i++)
			this->_allocator.destroy(this->_start + i);
		this->_end = this->_start;
	}
	
private:
	pointer			_start;
	pointer 		_end;
	size_type		_capacity;
	allocator_type	_allocator;
};

}	//end of namespace
#endif

