/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:28:49 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/05 11:13:51 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <stdexcept>
#include "ft_random_access_iterator.hpp"
#include "utils.hpp"
namespace ft
{
template <typename T, typename Alloc = std::allocator<T> >
class vector {
public:
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename ft::random_access_iterator<value_type> iterator;
	typedef typename ft::constant_random_access_iterator<const value_type> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;

	// Empty container constructor / default constructor
	explicit vector(const allocator_type &alloc = allocator_type()) :_start(0), _end(0), _capacity(0), _allocator(alloc)
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
		InputIterator test = first;
		size_type n = 0;
		while (test++ != last)
			n++;
		// this->_capacity = last - first;
		this->_capacity = n;
		this->_start = this->_allocator.allocate(this->_capacity);
		this->_end = this->_start;
		while (first != last)
			this->_allocator.construct(this->_end++, *(first++));
	}

	// Copy constructor
	vector (const vector& x) : _start(0), _end(0), _capacity(x.capacity())
	{
		this->_start = this->_allocator.allocate(this->_capacity);
		this->_end = this->_start;
		this->insert(this->_end, x.begin(), x.end());
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
		this->insert(this->_end, x.begin(), x.end());
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
	
	reverse_iterator rbegin()
	{
		reverse_iterator temp(this->_end);
		return (temp);
	}

	reverse_iterator rend()
	{
		reverse_iterator temp(this->_start);
		return (temp);
	}
	
	const_iterator begin() const
	{
		const_iterator temp(this->_start);
		return (temp);
	}

	const_iterator end() const
	{
		const_iterator temp(this->_end);
		return (temp);
	}
	
	const_reverse_iterator rbegin() const
	{
		const_reverse_iterator temp(this->_end);
		return (temp);
	}

	const_reverse_iterator rend() const
	{
		const_reverse_iterator temp(this->_start); 
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
		{
			if (n > this->_capacity * 2)
				this->reserve(n);
			else
				this->reserve(this->_capacity * 2);
		}
		if (n < this->size())
			for (size_type i = this->size(); i > n; i--)
				this->_allocator.destroy((this->_end--) - 1);
		else if (n > this->size())
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
				this->_allocator.destroy(tempstart++);
			}	
			this->_allocator.deallocate(tempstart - this->size(), this->_capacity);
			this->_capacity = n;
		}
	}

	/*
		ELEMENT ACCESS
	*/

	reference operator[] (size_type n)
	{
		return (*(this->_start + n));
	}
	const_reference operator[] (size_type n) const
	{
		return (*(this->_start + n));
	}
	
	reference at (size_type n)
	{
		if (n >= this->size())
			throw std::out_of_range("index out of range");
		return (*(this->_start + n));
	}
	const_reference at (size_type n) const
	{
		if (n >= this->size())
			throw std::out_of_range("index out of range");
		return (*(this->_start + n));
	}

	reference front()
	{
		return (*this->_start);
	}
	
	const_reference front() const
	{
		return (*this->_start);
	}

	reference back()
	{
		return (*(this->_end - 1));
	}
	
	const_reference back() const
	{
		return (*(this->_end - 1));
	}

	value_type* data() 
	{
		return (this->_start);
	}

	const value_type* data() const
	{
		return (this->_start);
	}
	/*
		MODIFIER MEMBER FUNCTIONS
	*/
	// assign
	template <class InputIterator>
  	void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
	{
		this->clear();
		this->insert(this->_end, first, last);
	}

	void assign (size_type n, const value_type& val)
	{
		this->clear();
		this->insert(this->_end, n, val);
	}
	// push_back
	void push_back (const value_type& val)
	{
		this->insert(this->_end, val);
	}
	
	void pop_back()
	{
		this->erase(this->_end - 1);
	}
	// insert single
	iterator insert (iterator position, const value_type& val)
	{
		size_type distance = position - this->begin();
		this->insert(position, 1, val);
		return (this->begin() + distance);
	}

	// insert fill
	void insert (iterator position, size_type n, const value_type& val)
	{
		ft::vector<T> temp(n, val);
		this->insert(position, temp.begin(), temp.end());
	}

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
	{
		InputIterator test = first;
		size_type n = 0;
		while (test++ != last)
			n++;
		size_type distance = this->end() - position;
		pointer new_start = NULL;
		pointer new_end = NULL;
		size_type new_capacity = 0;
		pointer ppos = position.base();
		InputIterator pfirst = first;
		InputIterator plast = last;
		pointer temp;
		if (this->size() + n > this->_capacity)
		{
			new_capacity = this->size() + n;
			if (this->size() + n > this->_capacity * 2)
				new_capacity = this->size() + n;
			else
				new_capacity = this->_capacity * 2;
			new_start = this->_allocator.allocate(new_capacity);
			temp = this->_start;
			new_end = new_start;
			try
			{
				while (temp != ppos)
				{
					this->_allocator.construct(new_end, *temp);
					this->_allocator.destroy(temp);
					new_end++;
					temp++;
				}
				while (pfirst != plast)
				{
					this->_allocator.construct(new_end, *pfirst);
					new_end++;
					pfirst++;
				}
				while (temp != this->_end)
				{
					this->_allocator.construct(new_end, *temp);
					this->_allocator.destroy(temp);
					new_end++;
					temp++;
				}
			}
			catch (...)
			{
				while (new_start != new_end)
				{
					this->_allocator.destroy(new_end--);
				}
				this->_allocator.destroy(new_end);
				this->_allocator.deallocate(new_start, new_capacity);
				throw ;
			}
			this->_allocator.deallocate(this->_start, this->_capacity);
			this->_start = new_start;
			this->_end = new_end;
			this->_capacity = new_capacity;
		}
		else
		{
			temp = this->_end - distance;
			if (this->_start != this->_end)
			{
				for (pointer p = this->_end + n - 1; p > this->_end + n - distance - 1 ; p--)
				{
					this->_allocator.construct(p, *(p - n));
					this->_allocator.destroy(p - n);
				}
			}
			for (size_type i = 0; i < n; i++)
			{
				this->_allocator.construct(temp++, *(pfirst++));
			}
			this->_end += n;
		}
	}

	// erase
	iterator erase (iterator position)
	{
		return(this->erase(position, position + 1));
	}

	iterator erase (iterator first, iterator last)
	{
		difference_type n = last - first;
		pointer pfirst = first.base();
		pointer plast = pfirst + n;
		while (pfirst != plast)
			this->_allocator.destroy(pfirst++);
		std::copy(pfirst, this->_end, first.base());
		
		for (difference_type i = 1; i <= n; i++)
		{
			this->_allocator.destroy(this->_end - 1);
			this->_end--;
		}
		return (last - n);
	}

	// swap
	void swap (vector& x)
	{
		pointer starttemp = this->_start;
		pointer endtemp = this->_end;
		size_type capacitytemp = this->_capacity;
		allocator_type allocatortemp = this->_allocator;

		this->_start = x._start;
		this->_end = x._end;
		this->_capacity = x._capacity;
		this->_allocator = x._allocator;
	
		x._start = starttemp;
		x._end = endtemp;
		x._capacity = capacitytemp;
		x._allocator = allocatortemp;
	}

	// clear
	void clear()
	{
		for (size_type i = 0; i < this->size(); i++)
			this->_allocator.destroy(this->_start + i);
		this->_end = this->_start;
	}
	
	// get_allocator
	allocator_type get_allocator() const
	{
		return (this->_allocator);
	}

private:
	pointer			_start;
	pointer 		_end;
	size_type		_capacity;
	allocator_type	_allocator;
};
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	else
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs < rhs));
}

}	//end of namespace ft

namespace std
{
	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}
#endif
