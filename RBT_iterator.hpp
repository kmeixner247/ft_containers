/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:15:00 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/28 00:46:52 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP
#include "RBT.hpp"
namespace ft
{
template<typename T, typename Tree>
class constant_RBT_iterator;
template<typename T>
struct Node;
template<typename T, typename Tree>
class RBT_iterator: public iterator<bidirectional_iterator_tag, T>
{
public:
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference reference;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
private:
	typedef Node<T> node;
	typedef node * node_pointer;
public:
	RBT_iterator() : _current(0), _tree(0) {}
	RBT_iterator(RBT_iterator const &rhs) : _current(rhs._current), _tree(rhs._tree) {}
	RBT_iterator(node_pointer p, Tree *tree) : _current(p), _tree(tree) {}


	pointer base() const
	{
		return (this->_current);
	}

	RBT_iterator &operator=(RBT_iterator<T, Tree> const &rhs)
	{
		this->_current = rhs._current;
		return (*this);
	}
	RBT_iterator &operator++()
	{
		*this = this->_tree->successor(this->_current);
		return (*this);
	}
	RBT_iterator operator++(int)
	{
		RBT_iterator temp(*this);
		*this = this->_tree->successor(this->_current);
		return (temp);
	}

	RBT_iterator &operator--()
	{
		*this = this->_tree->predecessor(this->_current);
	}
	RBT_iterator operator--(int)
	{
		RBT_iterator temp(*this);
		*this = this->_tree->predecessor(this->_current);
		return (temp);
	}
	
	bool operator==(RBT_iterator<T, Tree> rhs) const
	{
		return ((*this == *rhs));
	}
	bool operator==(constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((*this == *rhs));
	}
	bool operator!=(RBT_iterator<T, Tree> rhs) const
	{
		return ((*this != *rhs));
	}
	bool operator!=(constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((*this != *rhs));
	}
	T &operator*() const
	{
		return (this->_current->content);
	}
	pointer operator->() const
	{
		return (&(this->_current->content));
	}
private:
	node_pointer _current;
	Tree *_tree;
};

template<typename T, typename Tree>
class constant_RBT_iterator: public iterator<bidirectional_iterator_tag, T>
{
public:
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
	typedef const typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference reference;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
private:
	typedef Node<T> node;
	typedef node * node_pointer;
public:
	constant_RBT_iterator() : _current(0), _tree(0) {}
	template<typename X, typename XTree>
	constant_RBT_iterator(const RBT_iterator<X, XTree> &rhs) : _current(rhs._current), _tree(rhs._tree) {}
	constant_RBT_iterator(const constant_RBT_iterator &rhs) : _current(rhs._current), _tree(rhs._tree) {}
	constant_RBT_iterator(node_pointer p, Tree *tree) : _current(p), _tree(tree) {}

	pointer base() const
	{
		return (this->_current);
	}

	constant_RBT_iterator &operator=(constant_RBT_iterator<T, Tree> const &rhs)
	{
		this->_current = rhs._current;
		return (*this);
	}
	constant_RBT_iterator &operator++()
	{
		*this = this->_tree->successor(this->_current);
		return (*this);
	}
	constant_RBT_iterator operator++(int)
	{
		constant_RBT_iterator temp(*this);
		*this = this->_tree->successor(this->_current);
		return (temp);
	}
	constant_RBT_iterator &operator--()
	{
		*this = this->_tree->predecessor(this->_current);
	}
	constant_RBT_iterator operator--(int)
	{
		constant_RBT_iterator temp(*this);
		*this = this->_tree->predecessor(this->_current);
		return (temp);
	}
	bool operator==(const RBT_iterator<T, Tree> rhs) const
	{
		return ((*this == *rhs));
	}
	bool operator==(const constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((*this == *rhs));
	}
	bool operator!=(const RBT_iterator<T, Tree> rhs) const
	{
		return ((*this != *rhs));
	}
	bool operator!=(const constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((*this != *rhs));
	}
	T &operator*() const
	{
		return (this->_current->content);
	}
	pointer operator->() const
	{
		return (&(this->_current->content));
	}
private:
	pointer _current;
	Tree *_tree;
};
}	//namespace ft end
#endif