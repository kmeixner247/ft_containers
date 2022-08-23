/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:10:02 by kmeixner          #+#    #+#             */
/*   Updated: 2022/08/23 14:24:54 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP
#include <memory>
#include <iostream>
namespace ft
{

template <typename T>
class vector_iterator {
	public:
	bool operator==(const vector_iterator<T>&rhs) const
	{
		return (&this == &rhs);
	}
	vector_iterator<T> &operator++();
	vector_iterator<T> operator++(int);
	T& operator*();
	T* operator->();
	private:
	T	*_content;
	// T	&ptr;
	};

}	//end of namespace
#endif