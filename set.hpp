/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:47:11 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/05 21:39:14 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP
#include "RBT.hpp"
#include "RBT_iterator.hpp"
#include "utils.hpp"
#include <memory>
namespace ft
{
template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class set
{
public:
typedef T key_type;
typedef T value_type;
typedef Compare key_compare;
typedef Compare value_compare;
typedef Alloc allocator_type;
typedef RBT<value_type, key_compare, allocator_type> tree_type;
typedef typename allocator_type::reference reference;
typedef typename allocator_type::const_reference const_reference;
typedef typename allocator_type::pointer pointer; 
typedef typename allocator_type::const_pointer const_pointer;
typedef typename ft::const_RBT_iterator<typename tree_type::node, tree_type> iterator;
typedef typename ft::const_RBT_iterator<typename tree_type::node, tree_type> const_iterator;
typedef typename ft::reverse_iterator<iterator> reverse_iterator;
typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
typedef ptrdiff_t difference_type;
typedef size_t size_type;


//constructors

//Default / empty container constructor
explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _comp(comp), _allocator(alloc)
{
}

//Range constructor
template <class InputIterator>
set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _comp(comp), _allocator(alloc)
{
	this->insert(first, last);
}

//Copy constructor
set (const set& x)
{
	*this = x;
}

//destructor
~set()
{
	this->_tree.clear();
	this->_tree.deleteEnds();
}

//assignment operator
set& operator= (const set& rhs)
{
	this->_allocator = rhs._allocator;
	this->_comp = rhs._comp;
	this->clear();
	this->_tree = rhs._tree;
	return (*this);
}

//iterator stuff
iterator begin()
{
	return (this->_tree.begin());
}
const_iterator begin() const
{
	return (this->_tree.begin());
}
iterator end()
{
	return (this->_tree.end());
}
const_iterator end() const
{
	return (this->_tree.end());
}
reverse_iterator rbegin()
{
	reverse_iterator temp(this->end());
	return (temp);
}
const_reverse_iterator rbegin() const
{
	const_reverse_iterator temp(this->end());
	return (temp);
}
reverse_iterator rend()
{
	reverse_iterator temp(this->begin());
	return (temp);
}
const_reverse_iterator rend() const
{
	const_reverse_iterator temp(this->begin());
	return (temp);
}

//capacity stuff
bool empty() const
{
	return (!this->size());
}
size_type size() const
{
	return (this->_tree.size());
}
size_type max_size() const
{
	return (this->_allocator.max_size());
}

//modifying stuff
ft::pair<iterator,bool> insert (const value_type& val)
{
	bool booltemp = (this->_tree.find_node(val)) == this->_tree.getEnd();
	iterator temp = iterator(this->_tree.insert(val), this->_tree.getEnd(), this->_tree.getRend());
	return (ft::make_pair<iterator, bool>(temp, booltemp));
}

iterator insert (iterator position, const value_type& val)
{
	(void)position;
	return (insert(val).first);
}

template <class InputIterator>
void insert (InputIterator first, InputIterator last)
{
	while (first != last)
		this->_tree.insert(*(first++));
}

void erase (iterator position)
{
	this->_tree.erase(*position);
}
size_type erase (const value_type& k)
{
	return(this->_tree.erase(k));
}

void erase (iterator first, iterator last)
{
	set<value_type> temp(first, last);
	for (iterator it = temp.begin(); it != temp.end(); it++)
		this->erase(it);
}

void swap (set& x)
{
	this->_tree.swap(x._tree);
}
void clear()
{
	this->_tree.clear();
}

//observer stuff
key_compare key_comp() const
{
	return (this->_comp);
}
value_compare value_comp() const
{
	return (this->_comp);
}

//operation stuff
iterator find (const value_type& k)
{
	return (iterator(this->_tree.template find_node<key_type>(k), this->_tree.getEnd(), this->_tree.getRend()));
}
const_iterator find( const value_type& k ) const
{
		return (const_iterator(this->_tree.template find_node<const key_type>(k), this->_tree.getEnd(), this->_tree.getRend()));
}
size_type count (const value_type& k) const
{
	if (this->find(k) == this->end())
		return (0);
	else
		return (1);
}

ft::pair<iterator,iterator> equal_range( const key_type& k )
{
	iterator it = this->find(k);
	if (it != this->end())
		return (ft::make_pair<iterator, iterator>(it, ++it));
	it = this->begin();
	while (it != this->end() && this->_comp(*it, k))
		it++;
	return (ft::make_pair<iterator, iterator>(it, it));
}

ft::pair<const_iterator,const_iterator> equal_range( const key_type& k ) const
{
	const_iterator it = this->find(k);
	if (it != this->end())
		return (ft::make_pair<const_iterator, const_iterator>(it, ++it));
	it = this->begin();
	while (it != this->end() && this->_comp(*it, k))
		it++;
	return (ft::make_pair<const_iterator, const_iterator>(it, it));
}

iterator lower_bound (const value_type& k)
{
	iterator it = this->begin();
	while (it != this->end() && this->_comp(*it, k))
		it++;
	return (it);
}

const_iterator lower_bound (const value_type& k) const
{
	const_iterator it = this->begin();
	while (it != this->end() && this->_comp(*it, k))
		it++;
	return (it);
}

iterator upper_bound( const value_type& k )
{
	iterator it = this->begin();
	while (it != this->end() && !(this->_comp(k, *it)))
		it++;
	return (it);
}

const_iterator upper_bound( const value_type& k ) const
{
	const_iterator it = this->begin();
	while (it != this->end() && !(this->_comp(k, *it)))
		it++;
	return (it);
}

//allocator stuff
allocator_type get_allocator() const
{
	return (this->_allocator);
}

private:
	ft::RBT<value_type, key_compare, allocator_type> _tree;
	key_compare _comp;
	allocator_type _allocator;
	
};

template< class Key, class Compare, class Alloc >
bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal<typename ft::set<Key>::const_iterator, typename ft::set<Key>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin()));
}
template< class Key, class Compare, class Alloc >
bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template< class Key, class Compare, class Alloc >
bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (ft::lexicographical_compare<typename ft::set<Key>::const_iterator, typename ft::set<Key>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class Compare, class Alloc >
bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (!(rhs < lhs));
}

template< class Key, class Compare, class Alloc >
bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (rhs < lhs);
}

template< class Key, class Compare, class Alloc >
bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs )
{
	return (!(lhs < rhs));
}
}	//namespace ft end

namespace std
{
template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& x, ft::set<Key,Compare,Alloc>& y )
	{
		x.swap(y);
	}
}

#endif