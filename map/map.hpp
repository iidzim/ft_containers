/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:12:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/03 18:56:40 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include "tools.hpp"

namespace ft{

	template <typename T>
	struct node
	{
		T data; //? type must be comparable
		int bf; //? balance factor
		int height; //? height of this node in the tree
		node* parent_node;
		node* left_node;
		node* right_node;
	};

	template <typename T, typename Compare = std::less<T>, typename Alloc_node = std::allocator<ft::node<T> >, 
		typename Alloc = std::allocator <T> >
	class avltree{
		
		public:
			//? The height of a rooted tree is the number of edges between the tree's root and its furthest leaf
			int height(void){
				if (_root == NULL)
					return (0);
				return _root.height;
			}

			//? the number of nodes in the tree
			int size(void){ return _nbr_node; }
	
			bool is_empty(void){
				_nbr_node == 0 ? return true : return false;
			}

			bool exist(T value){
				return exist(_root, value);
			}

			bool insert(T value){

				if (!exist(_root, value)){
					_root = insert(_root, value);
					_nbr_node += 1;
					return (true);
				}
				return (false);
			}

		private:
			node<T> *_root;
			int _nbr_node;
			// int _height_tree;
			Compare _comp;
			Alloc_node _alloc_node;
			Alloc _alloc;

			bool exist(node<T> n, T value){

				if (_root == NULL)
					return (false);
				int diff = _comp(value, n.data);
				if (diff < 0)
					return exist(n.left_node, value);
				if (diff > 0)
					return exist(n.right_node, value);
				return (true);
			}

			node insert(node n, T value){

				if (node == NULL){
					_root = _alloc_node.allocate(1);
					_root->data = _alloc.allocate(1);
					_alloc.construct(_root->data, value);
					_root->height = _root->bf = 0;
					_root->left_node = _root->right_node = _root->parent_node = NULL;
					return (_root);
				}
				int diff = _comp(value, n.value);
				//? Insert node in left subtree
				if (diff < 0)
					n.left_node = insert(node.left_node, value);
				//? Insert node in right subtree
				else
					n.right_node = insert(node.right_node, value);
				// //? Update balance factor and height values.
    			update(node);
    			// //? Re-balance tree.
    			// return balance(node);
			}

			void update(node n){

				int left_height, right_height;
				left_height = (n.left_node == NULL) ? -1 : n->left_node.height;
				right_height = (n.right_node == NULL) ? -1 : n->right_node.height;
				n.height = std::max(right_height, left_height) + 1;
				node.bf = right_height - left_height;
			}

			node balance(node n){

				//? left heavy subtree
				if (n.bf == -2){
					//? left_left case
					if (n.left_node.bf <= 0)
						return leftleft_case(n);
					//? left_right case
					else
						return leftright_case(n);
				}
				//? right heavy subtree
				else if (n.bf == 2){
					//? right_right case
					if (n.right_node.bf >= 0)
						return rightright_case(n);
					//? right_left case
					else
						return rightleft_case(n);
				}
				//* we return node without any additional rotation if |bf| < 1
				return (n);
			}

			node leftleft_case(node n){
				return right_rotation(n);				
			}

			node leftright_case(node n){}
			node rightright_case(node n){}
			node rightleft_case(node n){}

			node right_rotation(node n){

				node parent = n.left_node;
				n.left_node = parent.right_node;
				//todo  to be continued
			}

			node left_rotation(node n){}

	};


	template < typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{
		
	};

};


#endif

////////////////////////////ToDo
//* calculate the balance factor for each node of the tree
//* implement helpers :
	//! int height(void); √
		//? The height of a rooted tree is the number of edges between the tree's
		//? root and its furthest leaf. This means that a tree containing a single
		//? node has a height of 0.
	//! int size(){ return nbr_node; } √
	//! bool isEmpty(); √
	//! bool exist(node root, T value){} √
		//? Return true/false depending on whether a value exists in the tree.
//* insert non duplicate value to the avl-tree -left node or right node-
	//? allocate new nod √
		//? allocate value √
// // * update max, min, nbr_node value after each insertion 
//* update height and bf
//* rebalance the tree if |bf| == 2
	//! leftLeft rotation
	//! rightright rotation
	//! leftright rotation  *update height and bf child node first then the parent node*
	//! rightLeft rotation  *update height and bf child node first then the parent node*
//* display the tree
//* remove node..
//* check if the value E [min, max] -> locate the node
//* 3 cases
	//! case1: the node is a leaf
	//! case2: the node have at most 1 child
	//! case3: the node have left and right child
		//? choose the successor and swap its value into the node
			// The successor is either the smallest value in the right subtree
			// or the largest value in the left subtree.
		//? remove the successor's node
		//? rebalance the tree
//* update max, min, nbr_node value after each insertion 
////(didn't figured out how to update the min and the max value yet)
// use min max functions instead (easy node removal)
//* update height and bf
