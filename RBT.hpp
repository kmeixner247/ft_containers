/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:43:29 by kmeixner          #+#    #+#             */
/*   Updated: 2022/09/26 20:16:22 by kmeixner         ###   ########.fr       */
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

	Node *find_node(int num)
	{
		Node *current = this->_root;
		while (current)
		{
			if (current->content == num)
				return (current);
			else if (current->content > num)
			{
				if (current->lc)
					current = current->lc;
				else
					return (NULL);
			}
			else
			{
				if (current->rc)
					current = current->rc;
				else
					return (NULL);
			}
		}
		return (NULL);
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
		// if (newnode->parent->colour == BLACK)	//Case 2: Parent is black - nothing to be done
		// 	return ;
		// else	//Case 3: Parent is red
		// {
		while (newnode->parent && newnode->parent->colour == RED)
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
	}

	void printBT(const Node *node)
	{
		printBT("", node, false);
	}

	Node *getRoot()
	{
		return (this->_root);
	}

	Node *successor(Node *node)
	{
		if (node->rc)
			return (minimum(node->rc));
		Node *temp = node->parent;
		while (temp && node == temp->rc)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	}

	Node *predecessor(Node *node)
	{
		if (node->lc)
			return (maximum(node->lc));
		Node *temp = node->parent;
		while (temp && node == temp->lc)
		{
			node = temp;
			temp = temp->parent;
		}
		return (temp);
	}

	Node *minimum(Node *node)
	{
		while (node->lc)
			node = node->lc;
		return (node);
	}

	Node *maximum(Node *node)
	{
		while (node->rc)
			node = node->rc;
		return (node);
	}
	void delete_by_value(int n)
	{
		Node *node = bst_deletion(find_node(n));
		Node *temp = NULL;
		Node *sibling;
		Node *org;
		if (node->colour == RED)	//NODE RED WE CAN JUST DELETE
		{
			if ((temp = node->lc) || (temp = node->rc))
			{
				swap_nodes(node, temp);
				node = temp;
			}
			if (node == node->parent->lc)
				node->parent->lc = NULL;
			else
				node->parent->rc = NULL;
			delete node;
		}
		else if (((temp = node->lc) && node->lc->colour == RED) || ((temp = node->rc) && node->rc->colour == RED))
		{	//CHILD RED WE CAN JUST SWAP AND DELETE
			swap_nodes(node, temp);
			node = temp;
			node->parent->colour = BLACK;
			node->parent->lc = NULL;
			node->parent->rc = NULL;
			delete node;
		}
		else	//NODE BLACK AND NO RED CHILD: MANY OPTIONS
		{
			org = node;
			while (true)
			{
				if (!node->parent)
				{
					//I AM ROOT TERMINAL
					break ;
				}
				else if (node == node->parent->lc)
				{
					sibling = node->parent->rc;
					if (sibling->colour == RED)	//CASE 2 RED SIBLING
					{
						recolour(sibling);
						recolour(node->parent);
						rotate_left(node->parent);
					}
					else if (sibling->colour == BLACK && node->parent->colour == BLACK && (!sibling->rc || sibling->rc->colour == BLACK) && (!sibling->lc || sibling->lc->colour == BLACK))
					{	//CASE 3 PARENT BLACK SIBLING BLACK SIBLING CHILDREN BLACK OR NULL
						recolour(sibling);
						node = node->parent;
					}
					else if (node->parent->colour == RED && sibling->colour == BLACK && (!sibling->rc || sibling->rc->colour == BLACK) && (!sibling->lc || sibling->lc->colour == BLACK))
					{	//CASE 4 PARENT RED SIBLING BLACK SIBLING CHILDREN BLACK OR NULL TERMINAL
						recolour(sibling);
						recolour(node->parent); 
						break ;
					}
					else if (node->parent->colour == BLACK && sibling->colour == BLACK && sibling->lc && sibling->lc->colour == RED && (!sibling->rc || sibling->rc->colour == BLACK))
					{	//CASE 5 PARENT BLACK SIBLING BLACK SIBLING LEFT CHILD RED SIBLING RIGHT CHILD BLACK OR NULL
						recolour(sibling);
						recolour(sibling->lc);
						rotate_right(sibling);
					}
					else
					{	//ALL OTHER CASES? TERMINAL
						sibling->colour = node->parent->colour;
						node->parent->colour = BLACK;
						sibling->rc->colour = BLACK;
						rotate_left(node->parent);
						break ;
					}
				}
				else
				{
					sibling = node->parent->lc;
					if (sibling->colour == RED)
					{	//CASE 2 MIRROR
						recolour(sibling);
						recolour(node->parent);
						rotate_right(node->parent);
					}
					else if (sibling->colour == BLACK && node->parent->colour == BLACK && (!sibling->rc || sibling->rc->colour == BLACK) && (!sibling->lc || sibling->lc->colour == BLACK))
					{	//CASE 3 MIRROR
						recolour(sibling);
						node = node->parent;
					}
					else if (node->parent->colour == RED && sibling->colour == BLACK && (!sibling->rc || sibling->rc->colour == BLACK) && (!sibling->lc || sibling->lc->colour == BLACK))
					{	//CASE 4 MIRROR
						recolour(sibling);
						recolour(node->parent);
						break ;
					}
					else if (node->parent->colour == BLACK && sibling->colour == BLACK && sibling->rc && sibling->rc->colour == RED && (!sibling->lc || sibling->lc->colour == BLACK))
					{	//CASE 5 MIRROR
						recolour(sibling);
						recolour(sibling->rc);
						rotate_left(sibling);
					}
					else
					{	//CASE 6 MIRROR
						sibling->colour = node->parent->colour;
						node->parent->colour = BLACK;
						sibling->lc->colour = BLACK;
						rotate_right(node->parent);
						break ;
					}
				}
			}
			if ((temp = org->lc) || (temp = org->rc))
			{
				swap_nodes(temp, org);
				org = temp;
			}
			if (org == org->parent->lc)
				org->parent->lc = NULL;
			else
				org->parent->rc = NULL;
			delete org;
		}
	}
private:
	Node *_root;
	Node *_null;

	void printBT(const std::string &prefix, const Node *node, bool isLeft)
	{
		if (node)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "├──" : "└──" );
			std::cout << (node->colour == RED ? "\x1B[31m" : "");
			std::cout << node->content << std::endl;
			std::cout << (node->colour == RED ? "\033[0m" : "");
        	printBT( prefix + (isLeft ? "│   " : "    "), node->lc, true);
        	printBT( prefix + (isLeft ? "│   " : "    "), node->rc, false);
		}
	}

	Node *bst_deletion(Node *node)
	{
		Node *temp = node;
		while (node && node->rc && node->lc)
		{
			temp = successor(node);
			swap_nodes(node, successor(node));
			node = temp;
		}
		return (node);
	}

	void swap_nodes(Node *node, Node *other)
	{
		int temp;
		temp = node->content;
		node->content = other->content;
		other->content = temp;
	}

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
		if (!node)
			return ;
		node->colour = !node->colour;
	}
	void rotate_left(Node *node)
	{
		Node *temp = node->rc;
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
	
	void rotate_right(Node *node)
	{
		Node *temp = node->lc;
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