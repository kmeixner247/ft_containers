/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:03:24 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/05 08:03:43 by kmeixner         ###   ########.fr       */
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
	typedef typename ft::RBT_iterator<typename tree_type::node, tree_type> iterator;
	typedef typename ft::const_RBT_iterator<typename tree_type::node, tree_type> const_iterator;
	typedef typename ft::reverse_iterator<iterator> reverse_iterator;
	typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	
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
		this->insert(first, last);
	}

	//Copy constructor
	map (const map& x)
	{
		*this = x;
	}

	//Destructor
	~map()
	{
		this->_tree.clear();
		this->_tree.deleteEnds();
	}

	//Assignment operator
	map &operator=(const map &rhs)
	{
		this->_allocator = rhs._allocator;
		this->_comp = rhs._comp;
		this->clear();
		this->_tree = rhs._tree;
		return (*this);
	}

	/*	
		ITERATOR RELATED MEMBER FUNCTIONS
	*/
	iterator begin()
	{
		// return(iterator(this->_tree.minimum(this->_tree.getRoot()), &this->_tree));
		return (this->_tree.begin());
	}

	const_iterator begin() const
	{
		// return(const_iterator(this->_tree.minimum(this->_tree.getRoot()), &this->_tree));
		return (this->_tree.begin());
	}

	iterator end()
	{
		// return(iterator(this->_tree.getEnd(), &this->_tree));
		return (this->_tree.end());
	}
	
	const_iterator end() const
	{
		// return(const_iterator(this->_tree.getEnd(), &this->_tree));
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
		return (reverse_iterator(this->_tree.begin()));
	}
	
	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(this->_tree.begin()));
	}

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
		return((*((this->insert(ft::make_pair(k,mapped_type()))).first)).second);
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
		iterator temp = iterator(this->_tree.insert(val), this->_tree.getEnd(), this->_tree.getRend());
		return (ft::make_pair<iterator, bool>(temp, booltemp));
	}

	//Single element insert with hint (???)
	iterator insert (iterator position, const value_type& val)
	{
		(void)position;
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
		this->_tree.erase(*position);
	}
	
	size_type erase (const key_type& k)
	{
		return(this->_tree.erase(k));
	}
	
	void erase (iterator first, iterator last)
	{
		map<key_type, mapped_type> temp(first, last);
		for (iterator it = temp.begin(); it != temp.end(); it++)
			this->erase(it->first);
	}

	void swap (map& x)
	{
		map temp = *this;
		*this = x;
		x = temp;
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
	
	value_compare value_comp() const
	{
		return (value_compare(this->_comp));
	}
	// value_compare value_comp() const
	// {}

	/*	
		OPERATIONS MEMBER FUNCTIONS
	*/
	iterator find (const key_type& k)
	{
		return (iterator(this->_tree.template find_node<key_type>(k), this->_tree.getEnd(), this->_tree.getRend()));
	}

	const_iterator find (const key_type& k) const
	{
		return (const_iterator(this->_tree.template find_node<const key_type>(k), this->_tree.getEnd(), this->_tree.getRend()));
	}	

	size_type count (const key_type& k) const
	{
		if (this->find(k) == this->end())
			return (0);
		else
			return (1);
	}

	iterator lower_bound (const key_type& k)
	{
		iterator it = this->begin();
		while (it != this->end() && this->_comp(it->first, k))
			it++;
		return (it);
	}
	
	const_iterator lower_bound (const key_type& k) const
	{
		const_iterator it = this->begin();
		while (it != this->end() && this->_comp(it->first, k))
			it++;
		return (it);
	}

	iterator upper_bound (const key_type& k)
	{
		iterator it = this->begin();
		while (it != this->end() && !(this->_comp(k, it->first)))
			it++;
		return (it);
	}
	
	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator it = this->begin();
		while (it != this->end() && !(this->_comp(k, it->first)))
			it++;
		return (it);
	}

	pair<iterator,iterator> equal_range (const key_type& k)
	{
		iterator it = this->find(k);
		if (it != this->end())
			return (ft::make_pair<iterator, iterator>(it, ++it));
		it = this->begin();
		while (it != this->end() && this->_comp(it->first, k))
			it++;
		return (ft::make_pair<iterator, iterator>(it, it));
	}

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const
	{
		const_iterator it = this->find(k);
		if (it != this->end())
			return (ft::make_pair<const_iterator, const_iterator>(it, ++it));
		it = this->begin();
		while (it != this->end() && this->_comp(it->first, k))
			it++;
		return (ft::make_pair<const_iterator, const_iterator>(it, it));
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
bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal<typename ft::map<Key, T>::const_iterator, typename ft::map<Key, T>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator< ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return (ft::lexicographical_compare<typename ft::map<Key, T>::const_iterator, typename ft::map<Key, T>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
{
	return (!(lhs < rhs));
}

}	//end of namespace ft

//swap
namespace std
{
	template <class Key, class T, class Compare, class Alloc>
	void swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
}
#endif
