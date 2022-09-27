/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:24 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/27 11:05:06 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "RBT.hpp"
#include "utils.hpp"
#include <memory>
namespace ft
{
template < class Key, map::key_type class T, map::mapped_type class Compare = less<Key>,\
map::key_compare class Alloc = allocator<pair<const Key,T> > map::allocator_type > 
class map
{
public:
	typedef pair<const Key, T> value_type;
	typedef Key key_type;
	typedef T mapped_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_Type::pointer xpointer;
	typedef typename allocator_Type::const_pointer const_pointer;
	//iterators
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef RBT<value_type> tree_type;
	//Default / empty container constructor
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(ft::RBT()), _allocator(alloc), _compare(comp)
	{}

	//Range constructor
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{}

	//Copy constructor
	map (const map& x)
	{}

	//Destructor
	~map()
	{}

	/*	
		ITERATOR RELATED MEMBER FUNCTIONS
	*/
	iterator begin()
	{}

	const_iterator begin() const
	{}

	iterator end()
	{}
	
	const_iterator end() const
	{}

	reverse_iterator rbegin()
	{}
	
	const_reverse_iterator rbegin() const
	{}
	
	reverse_iterator rend()
	{}
	
	const_reverse_iterator rend() const
	{}
	
	const_iterator cbegin() const
	{}

	const_iterator cend() const
	{}

	const_reverse_iterator crbegin() const
	{}

	const_reverse_iterator crend() const
	{}

	/*	
		CAPACITY RELATED MEMBER FUNCTIONS
	*/

	bool empty() const
	{}

	size_type size() const
	{}

	size_type max_size() const
	{}

	/*	
		ELEMENT ACCESS MEMBER FUNCTIONS
	*/

	mapped_type& operator[] (const key_type& k)
	{}

	mapped_type& at (const key_type& k)
	{}
	
	const mapped_type& at (const key_type& k) const
	{}
	
	/*	
		MODIFIER MEMBER FUNCTIONS
	*/

	//Single element insert
	pair<iterator,bool> insert (const value_type& val)
	{}

	//Single element insert with hint (???)
	iterator insert (iterator position, const value_type& val)
	{}

	//Range insert
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{}

	void swap (map& x)
	{}

	void clear()
	{
		this->_tree.clear();
	}

	/*	
		OBSERVERS MEMBER FUNCTIONS
	*/
	key_compare key_comp() const
	{}

	value_compare value_comp() const
	{}

	/*	
		OPERATIONS MEMBER FUNCTIONS
	*/
	iterator find (const key_type& k)
	{}

	const_iterator find (const key_type& k) const
	{}

	size_type count (const key_type& k) const
	{}

	iterator lower_bound (const key_type& k)
	{}
	
	const_iterator lower_bound (const key_type& k) const
	{}

	iterator upper_bound (const key_type& k)
	{}
	
	const_iterator upper_bound (const key_type& k) const
	{}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{}
	
	pair<iterator,iterator> equal_range (const key_type& k)
	{}

	/*	
		ALLOCATOR
	*/

	allocator_type get_allocator() const
	{
		return (this->_allocator);
	}
	
private:
	ft::RBT<value_type> _tree;
	allocator_type _allocator;
	key_compare _compare;
	
};

/*	
	RELATIONAL OPERATORS
*/
template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{}

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{}

template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{}

template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{}

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{}

//swap
template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{}

}