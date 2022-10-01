/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:24 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/01 15:01:23 by kmeixner         ###   ########.fr       */
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
	
	class value_compare : std::binary_function<value_type,value_type,bool>
	{ // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

	void printBT()
	{
		this->_tree.printBT(this->_tree.getRoot());
	}

	//Default / empty container constructor
	// explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : c(comp), mem_alloc(alloc)
	explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _comp(comp), _allocator(alloc)
	{
	}

	//Range constructor
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc), _comp(comp), _allocator(alloc)
	{
		while (first != last)
			this->_tree.insert(*(first++));
	}

	//Copy constructor
	map (const map& x)
	{
		*this = x;
	}

	//Destructor
	~map()
	{}

	map &operator=(const map &rhs)
	{
		this->_allocator = rhs._allocator;
		this->_comp = rhs._comp;
		this->clear();
		this->_tree = rhs._tree;
		return (*this);
	}
// ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::const_iterator
// ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::iterator

// constant_RBT_iterator<const pair<const int, int>, RBT<pair<const int, int>, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > > >
// RBT_iterator<pair<const int, int>, RBT<pair<const int, int>, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > > >')

	/*	
		ITERATOR RELATED MEMBER FUNCTIONS
	*/
	iterator begin()
	{
		iterator temp(this->_tree.minimum(this->_tree.getRoot()), &this->_tree);
		return (temp);
		// return (iterator(this->_tree.minimum(this->_tree.getRoot()), &(this->_tree)));
	}

	const_iterator begin() const
	{
		const_iterator temp;
		temp = const_iterator(this->_tree.minimum(this->_tree.getRoot()), &this->_tree);
		return (temp);
	}

	iterator end()
	{
		return(iterator(this->_tree.getEnd(), &this->_tree));
	}
	
	const_iterator end() const
	{
		return(const_iterator(this->_tree.getEnd(), &this->_tree));
	}

	// reverse_iterator rbegin()
	// {}
	
	// const_reverse_iterator rbegin() const
	// {}
	
	// reverse_iterator rend()
	// {}
	
	// const_reverse_iterator rend() const
	// {}


	// const_iterator cbegin() const
	// {
	// 	const_iterator temp(iterator(this->_tree.minimum(this->_tree.getRoot()), &this->_tree), &this->_tree);
	// 	return (temp);
	// }

	// const_iterator cend() const
	// {}

	// const_reverse_iterator crbegin() const
	// {}

	// const_reverse_iterator crend() const
	// {}

	/*	
		CAPACITY RELATED MEMBER FUNCTIONS
	*/

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

	/*	
		ELEMENT ACCESS MEMBER FUNCTIONS
	*/

	mapped_type& operator[] (const key_type& k)
	{
		 return((*((this->insert(make_pair(k,mapped_type()))).first)).second);
	}

	mapped_type& at (const key_type& k)
	{
		return ((*find(k)).second);
		// return (mapped_type());
	}
	
	const mapped_type& at (const key_type& k) const
	{
		return ((*find(k)).second);
		// return (mapped_type());
	}
	
	/*	
		MODIFIER MEMBER FUNCTIONS
	*/

	//Single element insert
	pair<iterator,bool> insert (const value_type& val)
	{
		bool booltemp = (this->_tree.find_node(val)) == this->_tree.getEnd();
		iterator temp = iterator(this->_tree.insert(val), &this->_tree);
		return (ft::make_pair<iterator, bool>(temp, booltemp));
	}

	//Single element insert with hint (???)
	iterator insert (iterator position, const value_type& val)
	{
		return (insert(val).first);
	}

	//Range insert
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last)
	{
		while (first != last)
			this->_tree.insert(*(first++));
	}

	void erase (iterator position)
	{
		this->_tree.delete_by_iterator(position);
	}
	
	size_type erase (const key_type& k)
	{
		// std::cout << "hello" << std::endl;
		// return (this->_tree.delete_by_key(k));
		(void)k;
		return (0);
	}
	
	void erase (iterator first, iterator last)
	{
		
	}

	void swap (map& x)
	{
		map temp = x;
		x = *this;
		*this = x;
	}

	void clear()
	{
		this->_tree.clear();
	}

	/*	
		OBSERVERS MEMBER FUNCTIONS
	*/
	key_compare key_comp() const
	{
		return (this->_comp);
	}

	// value_compare value_comp() const
	// {}

	/*	
		OPERATIONS MEMBER FUNCTIONS
	*/
	iterator find (const key_type& k)
	{
		value_type lol = ft::make_pair<key_type, mapped_type>(k, mapped_type());
		return (iterator(this->_tree.find_node(lol), &this->_tree));

		// iterator it = this->begin();
		// for (; it != this->end(); it++)
		// 	if ((*it).first == k)
		// 		break;
		// return (it);
	}

	const_iterator find (const key_type& k) const
	{
		value_type lol = ft::make_pair<key_type, mapped_type>(k, mapped_type());
		return (const_iterator(iterator(this->_tree.find_node(lol), &this->_tree)));

		// const_iterator it = this->begin();
		// for (; it != this->end(); it++)
		// 	if ((*it).first == k)
		// 		break;
		// return (const_iterator());
	}	

	size_type count (const key_type& k) const
	{
		if (find(k) == this->end())
			return (0);
		else
			return (1);
	}

	iterator lower_bound (const key_type& k)
	{
		(void)k;
		return (iterator());
	}
	
	const_iterator lower_bound (const key_type& k) const
	{
		(void)k;
		return (const_iterator());
	}

	iterator upper_bound (const key_type& k)
	{
		(void)k;
		return (iterator());
	}
	
	const_iterator upper_bound (const key_type& k) const
	{
		(void)k;
		return (const_iterator());
	}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		(void)k;
		return (ft::make_pair<const_iterator, const_iterator>(const_iterator(), const_iterator()));
	}
	
	pair<iterator,iterator> equal_range (const key_type& k)
	{
		(void)k;
		return (ft::make_pair<iterator,iterator>(iterator(), iterator()));
	}

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
	allocator_type _allocator;
	
};

/*	
	RELATIONAL OPERATORS
*/
template <class Key, class T, class Compare, class Alloc>
bool operator== (  map<Key,T,Compare,Alloc>& lhs,  map<Key,T,Compare,Alloc>& rhs ) 
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal<typename ft::map<Key, T>::iterator, typename ft::map<Key, T>::iterator>(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= (  map<Key,T,Compare,Alloc>& lhs,  map<Key,T,Compare,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator< (  map<Key,T,Compare,Alloc>& lhs,  map<Key,T,Compare,Alloc>& rhs )
{
	return (ft::lexicographical_compare<typename ft::map<Key, T>::iterator, typename ft::map<Key, T>::iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<= (  map<Key,T,Compare,Alloc>& lhs,  map<Key,T,Compare,Alloc>& rhs )
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>  (  map<Key,T,Compare,Alloc>& lhs,  map<Key,T,Compare,Alloc>& rhs )
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>= (  map<Key,T,Compare,Alloc>& lhs,  map<Key,T,Compare,Alloc>& rhs )
{
	return (!(lhs < rhs));
}

// //swap
// template <class Key, class T, class Compare, class Alloc>
// void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
// {}

}
#endif