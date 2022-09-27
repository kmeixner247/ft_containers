/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:24 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/28 00:26:14 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "RBT.hpp"
#include "RBT_iterator.hpp"
#include "utils.hpp"
#include <memory>
namespace ft
{
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
class map
{
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef pair<const key_type, mapped_type> value_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef RBT<value_type, key_compare, allocator_type> tree_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	//iterators
	typedef typename ft::RBT_iterator<value_type, tree_type> iterator;
	typedef typename ft::constant_RBT_iterator<const value_type, tree_type> const_iterator;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	
	//Default / empty container constructor
	// explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : c(comp), mem_alloc(alloc)
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _comp(comp)
	{
	}

	void tempprint()
	{
		this->_tree.printBT(this->_tree.getRoot());
	}

	//Range constructor
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _comp(comp)
	{
		(void)first;
		(void)last;
	}

	//Copy constructor
	map (const map& x)
	{
		*this = x;
	}

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

	// reverse_iterator rbegin()
	// {}
	
	// const_reverse_iterator rbegin() const
	// {}
	
	// reverse_iterator rend()
	// {}
	
	// const_reverse_iterator rend() const
	// {}
	
	const_iterator cbegin() const
	{}

	const_iterator cend() const
	{}

	// const_reverse_iterator crbegin() const
	// {}

	// const_reverse_iterator crend() const
	// {}

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
	{
		//change thisprobably
		bool booltemp = this->_tree.find_node(val);
		iterator temp = iterator(this->_tree.insert(val), &(this->_tree));
		return (ft::make_pair<iterator, bool>(temp, booltemp));
	}

	//Single element insert with hint (???)
	iterator insert (iterator position, const value_type& val)
	{
		
	}

	//Range insert
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		while (first != last)
			this->_tree->insert(*(first++));
	}

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

	// value_compare value_comp() const
	// {}

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
	ft::RBT<value_type, key_compare, allocator_type> _tree;
	key_compare _comp;
	
};

/*	
	RELATIONAL OPERATORS
*/
// template <class Key, class T, class Compare, class Alloc>
// bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
// {
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
// {}

// template <class Key, class T, class Compare, class Alloc>
// bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
// {}

// template <class Key, class T, class Compare, class Alloc>
// bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
// {}

// template <class Key, class T, class Compare, class Alloc>
// bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
// {}

// template <class Key, class T, class Compare, class Alloc>
// bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
// {}

// //swap
// template <class Key, class T, class Compare, class Alloc>
// void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
// {}

}
#endif