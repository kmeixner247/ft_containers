/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:15:00 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/01 16:10:33 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP
#include "RBT.hpp"
#include "ft_iterator.hpp"
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
	RBT_iterator() : _current(0), _currentnode(0), _tree(0) {}
	RBT_iterator(RBT_iterator const &rhs) : _current(rhs._current), _currentnode(rhs._currentnode), _tree(rhs._tree) {}
	RBT_iterator(node_pointer p, Tree *tree) : _current(p->content), _currentnode(p), _tree(tree) {}

	pointer base() const
	{
		return (this->_current);
	}

	node_pointer getNodeptr() const
	{
		return (this->_currentnode);
	}

	Tree getTree() const
	{
		return (this->_tree);
	}

	RBT_iterator &operator=(RBT_iterator<T, Tree> const &rhs)
	{
		this->_current = rhs._current;
		this->_currentnode = rhs._currentnode;
		this->_tree = rhs._tree;
		return (*this);
	}
	
	RBT_iterator &operator++()
	{
		this->_currentnode = this->_tree->successor(this->_currentnode);
		this->_current = this->_currentnode->content;
		return (*this);
	}
	
	RBT_iterator operator++(int)
	{
		RBT_iterator temp(*this);

		this->_currentnode = this->_tree->successor(this->_currentnode);
		this->_current = this->_currentnode->content;
		return (temp);
	}

	RBT_iterator &operator--()
	{
		this->_currentnode = this->_tree->predecessor(this->_currentnode);
		this->_current = this->_currentnode->content;
		return (*this);
	}
	
	RBT_iterator operator--(int)
	{
		RBT_iterator temp(*this);
		this->_currentnode = this->_tree->predecessor(this->_currentnode);
		this->_current = this->_currentnode->content;
		return (temp);
	}
	
	bool operator==(RBT_iterator<T, Tree> rhs) const
	{
		
		return ((this->_current == rhs._current));
	}
	
	bool operator==(constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((this->_current == rhs._current));
	}
	
	bool operator!=(RBT_iterator<T, Tree> rhs) const
	{
		return ((this->_current != rhs._current));
	}

	bool operator!=(constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((this->_current != rhs._current));
	}
	
	reference operator*() const
	{
		return (*this->_current);
	}
	
	pointer operator->() const
	{
		return (this->_current);
	}
private:
	pointer	_current;
	node_pointer _currentnode;
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
	constant_RBT_iterator() : _current(0), _currentnode(0), _tree(0) {}
	constant_RBT_iterator(constant_RBT_iterator const &rhs) : _current(rhs._current), _currentnode(rhs._currentnode), _tree(rhs._tree) {}
	constant_RBT_iterator(RBT_iterator<T, Tree> const &rhs) : _current(rhs.base()), _currentnode(rhs.getNodeptr()), _tree(rhs.getTree()) {}
	constant_RBT_iterator(node_pointer p, Tree *tree) : _current(&p->content), _currentnode(p), _tree(tree) {}
	const pointer base() const
	{
		return (this->_current);
	}

	constant_RBT_iterator &operator=(RBT_iterator<T, Tree> const &rhs)
	{
		this->_current = rhs._current;
		this->_currentnode = rhs._currentnode;
		this->_tree = rhs._tree;
		return (*this);
	}
	
	constant_RBT_iterator &operator=(constant_RBT_iterator<T, Tree> const &rhs)
	{
		this->_current = rhs._current;
		this->_currentnode = rhs._currentnode;
		this->_tree = rhs._tree;
		return (*this);
	}
	
	constant_RBT_iterator &operator++()
	{
		this->_currentnode = this->_tree->successor(this->_currentnode);
		this->_current = &this->_currentnode->content;
		return (*this);
	}
	
	constant_RBT_iterator operator++(int)
	{
		constant_RBT_iterator temp(*this);

		this->_currentnode = this->_tree->successor(this->_currentnode);
		this->_current = &this->_currentnode->content;
		return (temp);
	}

	constant_RBT_iterator &operator--()
	{
		this->_currentnode = this->_tree->predecessor(this->_currentnode);
		this->_current = &this->_currentnode->content;
		returm (*this);
	}
	
	constant_RBT_iterator operator--(int)
	{
		constant_RBT_iterator temp(*this);
		this->_currentnode = this->_tree->predecessor(this->_currentnode);
		this->_current = &this->_currentnode->content;
		return (temp);
	}
	
	bool operator==(RBT_iterator<T, Tree> rhs) const
	{
		
		return ((*this->_current == *rhs._current));
	}
	
	bool operator==(constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((*this->_current == *rhs._current));
	}
	
	bool operator!=(RBT_iterator<T, Tree> rhs) const
	{
		return ((*this->_current != *rhs._current));
	}

	bool operator!=(constant_RBT_iterator<T, Tree> rhs) const
	{
		return ((*this->_current != *rhs._current));
	}
	
	const reference operator*() const
	{
		return (*this->_current);
	}
	
	const pointer operator->() const
	{
		return (this->_current);
	}
private:
	pointer	_current;
	node_pointer _currentnode;
	Tree *_tree;
};

}	//namespace ft end
#endif