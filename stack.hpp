/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:37:18 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/03 19:20:51 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <stack>
namespace ft
{
	
template <class T, class Container = ft::vector<T> > 
class stack
{
public:
	typedef T value_type;
	typedef Container container_type;
	typedef size_t size_type;
	typedef typename container_type::reference reference;
	typedef typename container_type::const_reference const_reference;
	explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

	stack& operator=( const stack& other )
	{
		this->c = other.c;
		return (*this);
	}

	~stack() {}

	bool empty() const 
	{
		return (!this->c.size());
	}
	
	size_type size() const
	{
		return (this->c.size());
	}

	value_type& top()
	{
		return (this->c.back());
	}

	const_reference top() const
	{
		return (this->c.back());
	}	

	void push (const value_type& val)
	{
		this->c.push_back(val);
	}

	void pop()
	{
		this->c.pop_back();
	}

	template<typename A, typename B>
	friend bool operator== (const stack<A,B>& lhs, const stack<A,B>& rhs);
	
	template<typename A, typename B>
	friend bool operator<  (const stack<A,B>& lhs, const stack<A,B>& rhs);

protected:
	container_type c;

};

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c == rhs.c);
}

template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c < rhs.c);
}

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (!(lhs < rhs));
}

}	//end of namespace ft