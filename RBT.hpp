/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:43:29 by kmeixner          #+#    #+#             */
/*   Updated: 2022/10/05 23:37:02 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP
#include "utils.hpp"
#include "RBT_iterator.hpp"
#include <functional>
#include <memory>
#include <iostream>
#define RED true
#define BLACK false
namespace ft
{
template<typename T>
struct Node
{
public:
	T *content;
	Node *parent;
	Node *lc;
	Node *rc;
	bool colour;
};
template<typename T>
struct ConstNode
{
public:
	ConstNode(Node<T> node) : content(node->content), parent(node->parent), lc(node->lc), rc(node->rc), colour(node->colour) {}
	T * const content;
	ConstNode *parent;
	ConstNode *lc;
	ConstNode *rc;
	bool colour;
};

template<typename T, typename Compare, typename Alloc = std::allocator<T> >
class RBT
{
public:
	typedef T value_type;
	typedef Compare key_compare;
	typedef Alloc allocator_type;
	typedef Node<T> node;
	typedef Node<T>* node_pointer;
	typedef Node<const T>* const_node_pointer;
	typedef RBT<value_type, key_compare, allocator_type> tree_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename ft::RBT_iterator<node, tree_type> iterator;
	typedef typename ft::const_RBT_iterator<node, tree_type> const_iterator;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;

	RBT(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{
		this->_compare = comp;
		this->_allocator = alloc;
		this->create_ends();
		this->_root = this->_end;
		this->_size = 0;
	}

	void create_ends()
	{
		this->_end = this->_nodealloc.allocate(1);
		this->_end->content = this->_allocator.allocate(1);
		this->_allocator.construct(this->_end->content);
		this->_end->colour = BLACK;
		this->_end->parent = NULL;
		this->_end->lc = NULL;
		this->_end->rc = NULL;
		this->_rend = this->_nodealloc.allocate(1);
		this->_rend->content = this->_allocator.allocate(1);
		this->_allocator.construct(this->_rend->content);
		this->_rend->colour = BLACK;
		this->_rend->parent = NULL;
		this->_rend->lc = NULL;
		this->_rend->rc = NULL;
	}

	RBT (const RBT &rhs)
	{
		*this = rhs;
	}
	
	~RBT()
	{
	}
	
	RBT &operator=(const RBT &rhs)
	{
		this->clear();
		this->_compare = rhs.getCompare();
		this->_allocator = rhs._allocator;
		this->_size = rhs._size;
		if (rhs.getRoot() != rhs.getEnd())
		{
			this->_root = this->_nodealloc.allocate(1);
			this->_root->parent = NULL;
			this->_root->lc = NULL;
			this->_root->rc = NULL;
			this->_root->colour = BLACK;
			this->_root->content = this->_allocator.allocate(1);
			this->_allocator.construct(this->_root->content, *(rhs.getRoot()->content));
			this->copy_rec(this->_root, rhs.getRoot());
		}
		this->_end->parent = this->maximum(this->_root);
		this->_rend->parent = this->minimum(this->_root);
		return (*this);
	}

	key_compare getCompare() const
	{
		return (this->_compare);
	}
	
	allocator_type getAlloc() const
	{
		return (this->_allocator);
	}

	node_pointer getEnd() const
	{
		return (this->_end);
	}

	node_pointer getRend() const
	{
		return (this->_rend);
	}

	node_pointer getRoot() const
	{
		return (this->_root);
	}

	void copy_rec(node_pointer node, node_pointer rhsnode)
	{
		if (rhsnode->lc)
		{
			node->lc = this->_nodealloc.allocate(1);
			node->lc->parent = node;
			node->lc->lc = NULL;
			node->lc->rc = NULL;
			node->lc->colour = rhsnode->lc->colour;
			node->lc->content = this->_allocator.allocate(1);
			this->_allocator.construct(node->lc->content, *(rhsnode->lc->content));
			copy_rec(node->lc, rhsnode->lc);
		}
		if (rhsnode->rc)
		{
			node->rc = this->_nodealloc.allocate(1);
			node->rc->parent = node;
			node->rc->lc = NULL;
			node->rc->rc = NULL;
			node->rc->colour = rhsnode->rc->colour;
			node->rc->content = this->_allocator.allocate(1);
			this->_allocator.construct(node->rc->content, *(rhsnode->rc->content));
			copy_rec(node->rc, rhsnode->rc);
		}
	}
	
	size_type size() const
	{
		return (this->_size);
	}
	
	size_type max_size() const
	{
		return (this->_allocator.max_size());
	}

	template<typename Key>
	node_pointer find_node(Key k) const
	{
		node_pointer current = this->_root;
		if (current == this->_end)
			return (this->_end);
		while (current)
		if (k == get_key(current->content))
			return (current);
		else if (this->_compare(k, get_key(current->content)))
		{
			if (current->lc)
				current = current->lc;
			else
				return (this->_end);
		}
		else
		{
			if (current->rc)
				current = current->rc;
			else
				return (this->_end);
		}
		return (this->_end);
	}

	node_pointer find_node(value_type val) const
	{
		node_pointer current = this->_root;
		if (current == this->_end)
			return (this->_end);
		while (current)
		{
			if (get_key(&val) == get_key(current->content))
				return (current);
			else if (this->_compare(get_key(&val), get_key(current->content)))
			{
				if (current->lc)
					current = current->lc;
				else
					return (this->_end);
			}
			else
			{
				if (current->rc)
					current = current->rc;
				else
					return (this->_end);
			}
		}
		return (this->_end);
	}

	node_pointer insert(value_type val)
	{
		node_pointer temp = find_node(val);
		if (temp != this->_end)
			return (temp);
		this->_size++;
		node_pointer newnode = this->_nodealloc.allocate(1);
		node_pointer org = newnode;
		newnode->content = this->_allocator.allocate(1);
		this->_allocator.construct(newnode->content, val);
		newnode->parent = NULL;
		newnode->lc = NULL;
		newnode->rc = NULL;
		if (this->_root == this->_end)	//Case 1: Tree is empty - insert at root and make black
		{
			newnode->colour = BLACK;
			newnode->parent = NULL;
			this->_root = newnode;
			this->_end->parent = this->_root;
			this->_rend->parent = this->_root;
			return (newnode);
		}
		newnode->colour = RED;
		bst_insertion(newnode);
		//Case 2: Parent is black - nothing to be done
		while (newnode->parent && newnode->parent->colour == RED)		//Case 3: Parent is red
		{
			if (newnode->parent->parent->lc && newnode->parent->parent->rc && newnode->parent->parent->lc->colour == RED && newnode->parent->parent->rc->colour == RED)	//Case 3.1: Parent and Uncle are both red - recolour Parent, Uncle and Grandparent
			{
				if (newnode->parent->parent != this->_root)
					recolour(newnode->parent->parent);
				recolour(newnode->parent->parent->rc);
				recolour(newnode->parent->parent->lc);
				newnode = newnode->parent->parent;
			}
			else	//Case 3.2: Parent is red and Uncle is black or NULL 
			{
				if (newnode->parent == newnode->parent->parent->rc)	//Parent is right child of Grandparent
				{
					if (newnode == newnode->parent->lc) //Case 3.2.2: Parent is right child of Grandparent and newnode is left child of Parent - right rotate to get to Case 3.2.1
					{
						newnode = newnode->parent;
						rotate_right(newnode);
					}
					//Case 3.2.1: Parent is right child of Grandparent and newnode is right child of Parent - left rotation at Grandparent, change (new) Sibling to red and Parent to Black
					rotate_left(newnode->parent->parent);
					recolour(newnode->parent);
					recolour(newnode->parent->lc);
				}
				else
				{
					if (newnode == newnode->parent->rc) //Case 3.2.4: Mirrored version of 3.2.2
					{
						newnode = newnode->parent;	
						rotate_left(newnode);
					}
					rotate_right(newnode->parent->parent);
					recolour(newnode->parent);
					recolour(newnode->parent->rc);
				}
			}
		}
		this->_end->parent = this->maximum(this->_root);
		this->_rend->parent = this->minimum(this->_root);
		return (org);
	}

	node_pointer successor(node_pointer node)
	{
		if (node == this->maximum(this->_root))
			return (this->_end);
		if (node->rc)
			return (minimum(node->rc));
		node_pointer temp = node->parent;
		while (temp && node == temp->rc)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	}

	node_pointer successor(node_pointer node) const
	{
		if (node == this->maximum(this->_root))
			return ((this->_end));
		if (node->rc)
			return ((minimum(node->rc)));
		node_pointer temp = node->parent;
		while (temp && node == temp->rc)
		{
			node = temp;
			temp = temp->parent;
		}
		return ((temp));
	}

	node_pointer predecessor(node_pointer node)
	{
		if (node == this->_end)
			return (this->maximum(this->_root));
		if (node->lc)
			return (maximum(node->lc));
		node_pointer temp = node->parent;
		while (temp && node == temp->lc)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	}
	node_pointer predecessor(node_pointer node) const
	{
		if (node == this->_end)
			return (this->maximum(this->_root));
		if (node->lc)
			return (maximum(node->lc));
		node_pointer temp = node->parent;
		while (temp && node == temp->lc)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	}

	node_pointer minimum(node_pointer node)
	{
		node_pointer temp;
		temp = node;
		if (!_root)
			return (this->_end);
		while (temp->lc)
			temp = temp->lc;
		return (temp);
	}
	node_pointer minimum(node_pointer node) const
	{
		node_pointer temp;
		temp = node;
		if (!_root)
			return (this->_end);
		while (temp->lc)
			temp = temp->lc;
		return (temp);
	}

	node_pointer maximum(node_pointer node) const
	{
		node_pointer temp;
		temp = node;
		if (!_root)
			return (this->_end);
		while (temp->rc)
			temp = temp->rc;
		return (temp);
	}

	iterator begin()
	{
		return (iterator(this->minimum(this->_root), this->_end, this->_rend));
	}

	const_iterator begin() const
	{
		return(const_iterator(this->minimum(this->_root), this->_end, this->_rend));
	}

	iterator end()
	{
		return (iterator(this->_end, this->_end, this->_rend));
	}

	const_iterator end()  const
	{
		return (const_iterator(this->_end, this->_end, this->_rend));
	}
	iterator rend()
	{
		return (iterator(this->_rend, this->_end, this->_rend));
	}

	const_iterator rend()  const
	{
		return (const_iterator(this->_rend, this->_end, this->_end));
	}

	void erase(iterator position)
	{
		node_pointer node = position->getNodeptr();
		if (node == this->_end || node == this->_rend)
			return ;
		node_pointer temp;
		temp = this->maximum(this->_root);
		if (node == temp)
			this->_end->parent = this->predecessor(temp);
		temp = this->minimum(this->_root);
		if (node == temp)
			this->_rend->parent = this->successor(temp);
		this->erase(node);
	}

	template<typename Key>
	size_type erase (Key &k)
	{
		node_pointer node = this->find_node<Key>(k);
		if (node == this->_end || node == this->_rend)
			return (0);
		node_pointer temp;
		temp = this->maximum(this->_root);
		if (node == temp)
			this->_end->parent = this->predecessor(temp);
		temp = this->minimum(this->_root);
		if (node == temp)
			this->_rend->parent = this->successor(temp);
		this->erase(node);
		return (1);
	}

	void erase(value_type &val)
	{
		node_pointer node = this->find_node(val);
		if (node == this->_end || node == this->_rend)
			return ;
		node_pointer temp;
		temp = this->maximum(this->_root);
		if (node == temp)
			this->_end->parent = this->predecessor(temp);
		temp = this->minimum(this->_root);
		if (node == temp)
			this->_rend->parent = this->successor(temp);
		this->erase(node);
	}

	void erase(node_pointer node)
	{
		if (!this->_root->lc && !this->_root->rc && this->_root != this->_end)
		{
			delete_node(this->_root);
			this->_root = this->_end;
			this->_size--;
			return ;
		}
		this->_size--;
		node_pointer movedupnode;
		bool deletednodecolour;
		if (!node->lc || !node->rc)
		{
			deletednodecolour = node->colour;
			movedupnode = deletenodewithzerooronechild(node);
		}
		else
		{
			node_pointer successor = this->successor(node);
			this->_allocator.destroy(node->content);
			this->_allocator.construct(node->content, *(successor->content));
			deletednodecolour = successor->colour;
			movedupnode = deletenodewithzerooronechild(successor);
		}
		if (deletednodecolour == BLACK)
		{
			fixTreeErase(movedupnode);
		}
		if (movedupnode && !movedupnode->content)
		{
			if (movedupnode == movedupnode->parent->lc)
				movedupnode->parent->lc = NULL;
			else if (movedupnode == movedupnode->parent->rc)
				movedupnode->parent->rc = NULL;
			this->_nodealloc.deallocate(movedupnode, 1);
		}
	}

	void fixTreeErase(node_pointer node)
	{
		if (node == this->_root)
		{
			node->colour = BLACK;	
			return ;
		}
		node_pointer sibling = node->parent->lc;
		if (sibling == node)
			sibling = node->parent->rc;
		if (sibling->colour == RED)
		{
			sibling->colour = BLACK;
			node->parent->colour = RED;
			if (node == node->parent->lc)
				rotate_left(node->parent);
			else
				rotate_right(node->parent);
			sibling = node->parent->lc;
			if (sibling == node)
				sibling = node->parent->rc;
		}
		if (isBlack(sibling->lc) && isBlack(sibling->rc))
		{
			sibling->colour = RED;
			if (node->parent->colour == RED)
				node->parent->colour = BLACK;
			else
				fixTreeErase(node->parent);
		}
		else
		{
			bool isLeft = (node == node->parent->lc);
			if (isLeft && isBlack(sibling->rc))
			{
				sibling->lc->colour = BLACK;
				sibling->colour = RED;
				rotate_right(sibling);
				sibling = node->parent->rc;
			}
			else if (!isLeft && isBlack(sibling->lc))
			{
				sibling->rc->colour = BLACK;
				sibling->colour = RED;
				rotate_left(sibling);
				sibling = node->parent->lc;
			}
			sibling->colour = node->parent->colour;
			node->parent->colour = BLACK;
			if (isLeft)
			{
				sibling->rc->colour = BLACK;
				rotate_left(node->parent);
			}
			else
			{
				sibling->lc->colour = BLACK;
				rotate_right(node->parent);
			}
		}
	}

	bool isBlack(node_pointer node)
	{
		 return (!node || node->colour == BLACK);
	}

	node_pointer deletenodewithzerooronechild(node_pointer node)
	{
		node_pointer temp;
		if (node->lc || node->rc)
		{
			return (delete_only_child(node));
		}
		else if (node->colour == RED)
		{
			delete_node(node);
			return (NULL);
		}
		else
		{
			temp = this->_nodealloc.allocate(1);
			temp->colour = BLACK;
			temp->lc = NULL;
			temp->rc = NULL;
			temp->content = NULL;
			temp->parent = node->parent;
			if (node == node->parent->lc)
				node->parent->lc = temp;
			else
				node->parent->rc = temp;
			delete_node(node);
			return (temp);
		}
	}

	node_pointer delete_only_child(node_pointer node)
	{
		node_pointer child;
		if (node->lc)
			child = node->lc;
		else if (node->rc)
			child = node->rc;
		else
			return (NULL);
		node->colour = child->colour;
		this->_allocator.destroy(node->content);
		this->_allocator.construct(node->content, *(child->content));
		delete_node(child);
		return (node);
	}

	void swap(RBT &x)
	{
		node_pointer troot = this->_root;
		node_pointer tend = this->_end;
		node_pointer trend = this->_rend;
		allocator_type talloc = this->_allocator;
		key_compare tcomp = this->_compare;
		size_type tsize = this->_size;

		this->_root = x._root;
		this->_end = x._end;
		this->_rend = x._rend;
		this->_allocator = x._allocator;
		this->_compare = x._compare;
		this->_size = x._size;
		
		x._root = troot;
		x._end = tend;
		x._rend = trend;
		x._allocator = talloc;
		x._compare = tcomp;
		x._size = tsize;
	}

	void clear()
	{
		this->clear_subtree(this->_root);
		this->_root = this->_end;
		this->_size = 0;
	}

	void deleteEnds()
	{
		this->_allocator.destroy(this->_end->content);
		this->_allocator.deallocate(this->_end->content, 1);
		this->_nodealloc.deallocate(this->_end, 1);
		this->_allocator.destroy(this->_rend->content);
		this->_allocator.deallocate(this->_rend->content, 1);
		this->_nodealloc.deallocate(this->_rend, 1);
	}
private:
	node_pointer _root;
	node_pointer _end;
	node_pointer _rend;
	allocator_type _allocator;
	key_compare _compare;
	std::allocator<Node<T> > _nodealloc;
	size_type _size;

	void clear_subtree(node_pointer node)
	{
		if (!node || node == this->_end)
			return ;
		if (node->lc)
			clear_subtree(node->lc);
		if (node->rc)
			clear_subtree(node->rc);
		delete_node(node);
	}

	void delete_node(node_pointer node)
	{
		if (!node)
			return ;
		if (node->parent)
		{
			if (node == node->parent->lc)
				node->parent->lc = NULL;
			else if (node == node->parent->rc)
				node->parent->rc = NULL;
		}
		this->_allocator.destroy(node->content);
		this->_allocator.deallocate(node->content, 1);
		this->_nodealloc.deallocate(node, 1);
	}

	node_pointer find_node_to_delete(node_pointer node)
	{
		node_pointer temp = node;
		while (node && node->rc && node->lc)
		{
			temp = successor(node);
			swap_nodes(node, successor(node));
			node = temp;
		}
		return (node);
	}

	void swap_nodes(node_pointer node, node_pointer other)
	{
		this->_allocator.destroy(node->content);
		this->_allocator.construct(node->content, *(other->content));
	}

	void bst_insertion(node_pointer node)
	{
		node_pointer current = this->_root;
		while (current)
		{
			if (this->_compare(get_key(node->content), get_key(current->content)))
			{
				if (current->lc)
					current = current->lc;
				else
				{
					current->lc = node;
					node->parent = current;
					return ;
				}
			}
			else
			{
				if (current->rc)
					current = current->rc;
				else
				{
					current->rc = node;
					node->parent = current;
					return ;
				}
			}
		}
	}

	void recolour(node_pointer node)
	{
		if (!node)
			return ;
		node->colour = !node->colour;
	}
	void rotate_left(node_pointer node)
	{
		node_pointer temp = node->rc;
		node->rc = temp->lc;
		if (temp->lc)
			temp->lc->parent = node;
		temp->parent = node->parent;
		if (!node->parent)
			this->_root = temp;
		else if (node == node->parent->lc)
			node->parent->lc = temp;
		else
			node->parent->rc = temp;
		temp->lc = node;
		node->parent = temp;
	}
	
	void rotate_right(node_pointer node)
	{
		node_pointer temp = node->lc;
		node->lc = temp->rc;
		if (temp->rc)
			temp->rc->parent = node;
		temp->parent = node->parent;
		if (!node->parent)
			this->_root = temp;
		else if (node == node->parent->rc)
			node->parent->rc = temp;
		else
			node->parent->lc = temp;
		temp->rc = node;
		node->parent = temp;
	}
	
};
}	//namespace ft end
#endif
