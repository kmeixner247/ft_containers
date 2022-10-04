/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:21:42 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/04 20:03:41 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP
#include "RBT.hpp"
#include "ft_iterator.hpp"

namespace ft
{
template <typename T, class Tree>
class const_RBT_iterator;

template<typename T, typename Tree>
class RBT_iterator: public iterator<bidirectional_iterator_tag, T>
{
public:
	typedef typename Tree::value_type value_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::difference_type difference_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::pointer pointer;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::reference reference;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category iterator_category;

	RBT_iterator() : _current(0), _end(0), _rend(0) {}
	RBT_iterator(T *p, T *end, T *rend) : _current(p), _end(end), _rend(rend) {}
	RBT_iterator(const RBT_iterator &rhs) : _current(rhs._current), _end(rhs._end), _rend(rhs._rend) {}

	RBT_iterator &operator=(const RBT_iterator &rhs)
	{
		this->_current = rhs._current;
		this->_end = rhs._end;
		this->_rend = rhs._rend;
		return (*this);
	}

	T *base() const
	{
		return(this->_current);
	}
	
	T* getEnd() const
	{
		return (this->_end);
	}
	
	T* getRend() const
	{
		return (this->_rend);
	}
	
	reference operator*() const
	{
		return (*(this->_current)->content);
	}
	
	pointer operator->() const
	{
		return (this->_current->content);
	}

	RBT_iterator &operator++()
	{
		T *temp = this->_current;
		//if iterator is at _rend, go to min
		if (temp == this->_rend)
			temp = this->_rend->parent;
		//if right child exist, find minimum of right tree
		else if (temp->rc)
		{
			temp = temp->rc;
			while (temp->lc)
				temp = temp->lc;
		}
		//otherwise go to first right parent
		else 
		{
			while (temp->parent && temp == temp->parent->rc)
				temp = temp->parent;
			if (temp->parent)
				temp = temp->parent;
			//if there is no right parent it means that the iterator was at max and gets set to _end
			else
				temp = this->_end;
		}
		this->_current = temp;
		return (*this);
	}

	RBT_iterator operator++(int)
	{
		RBT_iterator temp = *this;
		++(*this);
		return (temp);
	}

	RBT_iterator &operator--()
	{
		T *temp = this->_current;
		//if iterator is at _end, go to max
		if (temp == this->_end)
			temp = this->_end->parent;
		//if left child exist, find maximum of left tree
		else if (temp->lc)
		{
			temp = temp->lc;
			while (temp->rc)
				temp = temp->rc;
		}
		//otherwise go to first left parent
		else 
		{
			while (temp->parent && temp == temp->parent->lc)
				temp = temp->parent;
			if (temp->parent)
				temp = temp->parent;
			else //if there is no right parent it means that the iterator was at min and gets set to _rend
				temp = this->_rend;
		}
		this->_current = temp;
		return (*this);
	}

	RBT_iterator operator--(int)
	{
		RBT_iterator temp = *this;
		--(*this);
		return (temp);
	}

	bool operator==(RBT_iterator<T, Tree> rhs)
	{
		return ((this->base() == rhs.base()));
	}
	
	bool operator==(const_RBT_iterator<T, Tree> rhs) const
	{
		return ((this->base() == rhs.base()));
	}
	
	bool operator!=(RBT_iterator<T, Tree> rhs)
	{
		return ((this->base() != rhs.base()));
	}

	bool operator!=(const_RBT_iterator<T, Tree> rhs) const
	{
		return ((this->base() != rhs.base()));
	}
	
private:
	T *_current;
	T *_end;
	T *_rend;
};

template<typename T, typename Tree>
class const_RBT_iterator: public iterator<bidirectional_iterator_tag, T>
{
public:
	typedef  const typename Tree::value_type value_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::difference_type difference_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::pointer pointer;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::reference reference;
	typedef typename ft::iterator<bidirectional_iterator_tag, value_type>::iterator_category iterator_category;

	const_RBT_iterator() : _current(0), _end(0), _rend(0) {}
	const_RBT_iterator(T *p, T *end, T *rend) : _current(p), _end(end), _rend(rend) {}
	const_RBT_iterator(const const_RBT_iterator &rhs) : _current(rhs._current), _end(rhs._end), _rend(rhs._rend) {}
	const_RBT_iterator(const RBT_iterator<T, Tree> &rhs)
	{
		*this = rhs;
	}
	const_RBT_iterator &operator=(const const_RBT_iterator &rhs)
	{
		this->_current = rhs._current;
		this->_end = rhs._end;
		this->_rend = rhs._rend;
		return (*this);
	}
	
	const_RBT_iterator &operator=(const RBT_iterator<T, Tree> &rhs)
	{
		this->_current = rhs.base();
		this->_end = rhs.getEnd();
		this->_rend = rhs.getRend();
		return (*this);
	}

	T *base() const
	{
		return(this->_current);
	}
	
	T* getEnd() const
	{
		return (this->_end);
	}
	
	T* getRend() const
	{
		return (this->_rend);
	}
	
	const reference operator*() const
	{
		return (*(this->_current)->content);
	}
	
	const pointer operator->() const
	{
		return (this->_current->content);
	}

	const_RBT_iterator &operator++()
	{
		T *temp = this->_current;
		//if iterator is at _rend, go to min
		if (temp == this->_rend)
			temp = this->_rend->parent;
		//if right child exist, find minimum of right tree
		else if (temp->rc)
		{
			temp = temp->rc;
			while (temp->lc)
				temp = temp->lc;
		}
		//otherwise go to first right parent
		else 
		{
			while (temp->parent && temp == temp->parent->rc)
				temp = temp->parent;
			if (temp->parent)
				temp = temp->parent;
			//if there is no right parent it means that the iterator was at max and gets set to _end
			else
			{
				temp = this->_end;
			}
		}
		this->_current = temp;
		return (*this);
	}

	const_RBT_iterator operator++(int)
	{
		const_RBT_iterator temp = *this;
		++(*this);
		return (temp);
	}

	const_RBT_iterator &operator--()
	{
		T *temp = this->_current;
		//if iterator is at _end, go to max
		if (temp == this->_end)
		{
			std::cerr << "hi" << std::endl;
			temp = this->_end->parent;
		}
		//if left child exist, find maximum of left tree
		else if (temp->lc)
		{
			temp = temp->lc;
			while (temp->rc)
				temp = temp->rc;
		}
		//otherwise go to first left parent
		else 
		{
			while (temp->parent && temp == temp->parent->lc)
				temp = temp->parent;
			if (temp->parent)
				temp = temp->parent;
			else //if there is no right parent it means that the iterator was at min and gets set to _rend
				temp = this->_rend;
		}
		this->_current = temp;
		return (*this);
	}

	const_RBT_iterator operator--(int)
	{
		const_RBT_iterator temp = *this;
		--(*this);
		return (temp);
	}

	bool operator==(RBT_iterator<T, Tree> rhs)
	{
		return ((this->base() == rhs.base()));
	}
	
	bool operator==(const_RBT_iterator<T, Tree> rhs) const
	{
		return ((this->base() == rhs.base()));
	}
	
	bool operator!=(RBT_iterator<T, Tree> rhs)
	{
		return ((this->base() != rhs.base()));
	}

	bool operator!=(const_RBT_iterator<T, Tree> rhs) const
	{
		return ((this->base() != rhs.base()));
	}
	
private:
	T *_current;
	T *_end;
	T *_rend;
};




} //end of namespace ft

#endif