/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:24:20 by kmeixner          #+#    #+#             */
/*   Updated: 2022/08/24 22:57:25 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
#define FT_RANDOM_ACCESS_ITERATOR_HPP
#include "ft_iterator.hpp"

template<typename T>
class random_access_iterator : public iterator<random_access_iterator_tag, T>
{
typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;
typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;

public:
	random_access_iterator() : _current(nullptr) {}
	random_access_iterator(random_access_iterator const &rhs) : _current(rhs._current) {}
	random_access_iterator(typename T) : _current(&T) {}
	random_access_iterator &operator=(random_access_iterator const &rhs) {}
	random_access_iterator &operator++() {}
	random_access_iterator operator++(random_access_iterator) {}
	random_access_iterator 
	
private:
	pointer _current;
};

#endif