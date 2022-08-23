/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomtests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:28:49 by kmeixner          #+#    #+#             */
/*   Updated: 2022/08/23 14:22:58 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMTESTS_HPP
#define RANDOMTESTS_HPP
#include <memory>
#include <iostream>
#include "ft_iterator.hpp"
namespace ft
{

template <typename T, typename Alloc = std::allocator<T> >
class vector {
	typedef T value_type;
	typedef Alloc allocator_type;
public:
	vector(const allocator_type &alloc = allocator_type()) : _allocator(alloc)
	{
	std::cout << "default allocator called" << std::endl;
	}
	
	vector(size_t n, const allocator_type &alloc = allocator_type()) : _allocator(alloc)
	{
		this->_content = this->_allocator.allocate(n);
	std::cout << "size allocator called" << std::endl;
	}
	~vector(){
		std::cout << "Brain out" << std::endl;
	}
	vector_iterator begin();	//how?
	vector_iterator end();		//how?
private:
	allocator_type _allocator;
	T	*_content;	//move to iterator?
};

}	//end of namespace
#endif