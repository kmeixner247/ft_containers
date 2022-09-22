/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:43:29 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/22 22:11:49 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP
#include <functional>
#include <memory>
#include <iostream>
#define RED true
#define BLACK false
namespace ft
{
struct Node
{
	int content;
	Node *parent;
	Node *lc;
	Node *rc;
	bool colour;
};

// template<typename T, class Alloc = std::allocator<T>, class Compare = std::less<T>>
class RBT
{
public:
	RBT()
	{
		this->_null = new Node;
		this->_null->colour = BLACK;
		this->_null->lc = NULL;
		this->_null->rc = NULL;
		this->_root = this->_null;
	}

	void print_tree()
	{
		std::cout << this->_root->content << std::endl;
	}

	void find_number(int num)
	{
		Node *current = this->_root;
		std::cout << "###############################################" << std::endl;
		std::cout << "TRYING TO FIND " << num << std::endl;
		std::cout << "ROOT IS " << this->_root->content << " and " << (current->colour == RED ? "red" : "black") << std::endl;
		while (current)
		{
			if (current->content == num)
			{
				std::cout << "Found " << num << " in a " << (current->colour == RED ? "red" : "black") << " node!" << std::endl;
				return ;
			}
			else if (current->content > num)
			{
				std::cout << current->content << " is larger than " << num << ". ";
				if (current->lc)
				{
					std::cout << "Going down the tree to the left." << std::endl;
					current = current->lc;
				}
				else
				{
					std::cout << num << "is not in the tree!" << std::endl;
					return ;
				}
			}
			else
			{
				std::cout << current->content << " is smaller than " << num << ". ";
				if (current->rc)
				{
					std::cout << "Going down the tree to the right." << std::endl;
					current = current->rc;
				}
				else
				{
					std::cout << num << " is not in the tree!" << std::endl;
					return ;
				}
			}
		}
	}

	void insert(int val)
	{
		Node *newnode = new Node;
		newnode->content = val;
		newnode->parent = NULL;
		newnode->lc = NULL;
		newnode->rc = NULL;
		if (this->_root == this->_null)	//Case 1: Tree is empty - insert at root and make black
		{
			newnode->colour = BLACK;
			newnode->parent = NULL;
			this->_root = newnode;
			return ;
		}
		newnode->colour = RED;
		bst_insertion(newnode);
		if (newnode->parent->colour == BLACK)	//Case 2: Parent is black - nothing to be done
			return ;
		else	//Case 3: Parent is red
		{
			if (newnode->parent->parent->lc && newnode->parent->parent->rc && newnode->parent->parent->lc->colour == RED && newnode->parent->parent->rc->colour == RED)	//Case 3.1: Parent and Uncle are both red - recolour Parent, Uncle and Grandparent
			{
				if (newnode->parent->parent != this->_root)
					recolour(newnode->parent->parent);
				recolour(newnode->parent->parent->rc);
				recolour(newnode->parent->parent->lc);
				return ;
			}
			else	//Case 3.2: Parent is red and Uncle is black or NULL 
			{
				if (newnode->parent == newnode->parent->parent->rc)	//Parent is right child of Grandparent
				{
					// if (newnode == newnode->parent->lc) //Case 3.2.2: Parent is right child of Grandparent and newnode is left child of Parent - right rotate to get to Case 3.2.1
						// rotate_right(newnode->parent);
					//Case 3.2.1: Parent is right child of Grandparent and newnode is right child of Parent - left rotation at Grandparent, change (new) Sibling to red and Parent to Black
					rotate_left(newnode->parent->parent);
					recolour(newnode->parent->lc);
					recolour(newnode->parent);
				}
				else
				{
					if (newnode == newnode->parent->rc) //Case 3.2.4: Mirrored version of 3.2.2
						rotate_left(newnode->parent);
					// rotate_left(newnode->parent->parent);
					recolour(newnode->parent->rc);
					recolour(newnode->parent);
				}
			}
		}
	}

private:
	Node *_root;
	Node *_null;
	void bst_insertion(Node *node)
	{
		Node *current = this->_root;
		while (current)
		{
			if (node->content < current->content)
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
	void recolour(Node *node)
	{
		if (node->colour == BLACK)
		{
			node->colour = RED;
		}
		else
			node->colour = BLACK;
	}
	void rotate_left(Node *node)
	{
		if (node == this->_root)
			this->_root = node->rc;
		else
			node->parent->rc = node->rc;
		node->rc->lc = node;
		node->rc->parent = node->parent;
		node->parent = node->rc;
		node->rc = NULL;
	}
};
}	//namespace ft end
#endif