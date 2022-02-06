/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:16:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/06 13:46:35 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
# define AVLTREE_HPP

#include <iostream>
#include <functional>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include "../tools/tools.hpp"

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

	template <typename T, typename Compare = std::less<typename T::first_type>, typename Alloc_node = std::allocator<ft::node<T> >, 
		typename Alloc = std::allocator <T> >
	class avltree{

		typedef typename T::first_type	key_type;
		typedef typename T::second_type	value_type;
		typedef node<T> node_type;

		public:

			avltree(void): _nbr_node(0), _root() {}
			~avltree(void){}
			//? The height of a rooted tree is the number of edges between the tree's root and its furthest leaf
			int height(void){
				if (_root == NULL)
					return (0);
				return _root->height;
			}

			//? the number of nodes in the tree
			int size(void){ return _nbr_node; }
	
			bool is_empty(void){
				if (_nbr_node == 0)
					return true;
				return false;
			}

			bool exist(T value){
				return exist(_root, value);
			}

			bool insert(T data){

				if (!exist(_root, data)){
					_root = insert(_root, data);
					_nbr_node += 1;
					return (true);
				}
				return (false);
			}

			//? return the min value in the tree
			T min(node_type *root){

				while (root->left_node != NULL)
					root = root->left_node;
				return (root->data);
			}

			//? return the max value in the tree
			T max(node_type *root){

				while (root->right_node != NULL)
					root = root->right_node;
				return (root->data);
			}

			bool search (node_type root, key_type key){

				if (root == NULL)
					return false;
				else if (root.data.first == key)
					return true;
				else if (root.data.first > key)
					return search(root.left_node, key);
				else
					return search(root.right_node, key);
			}

			void display(const node_type* n){
				display("", n, false);
			}

			node_type* get_root(void){
				return (_root);
			}

			bool remove(T data){

				if (exist(_root, data)){
					_root = remove(_root, data);
					_nbr_node -= 1;
					return (true);
				}
				return (false);
			}

		private:

			bool exist(node_type *n, T data){

				if (n == NULL)
					return (false);
				int diff = _comp(data.first, n->data.first);
				if (n->data.first == data.first)
					return (true);
				if (diff == true)
					return exist(n->left_node, data);
				if (diff == false)
					return exist(n->right_node, data);
				return (true);
			}

			node_type* insert(node_type *n, T data){

				if (n == NULL){
					_root = _alloc_node.allocate(1);
					// _root->data = _alloc.allocate(1);
					_alloc.construct(&_root->data, data);
					_root->height = _root->bf = 0;
					_root->left_node = _root->right_node = _root->parent_node = NULL;
					return (_root);
				}
				int diff = _comp(data.first, n->data.first);
				if (diff == true) // Insert node in left subtree
					n->left_node = insert(n->left_node, data);
				else // Insert node in right subtree
					n->right_node = insert(n->right_node, data);
				update(n);	// Update balance factor and height values
				// return (n); // unbalanced bstree
				return balance(n); // Re-balance tree
			}

			void update(node_type *n){

				int left_height, right_height;
				left_height = (n->left_node == NULL) ? -1 : n->left_node->height;
				right_height = (n->right_node == NULL) ? -1 : n->right_node->height;
				n->height = std::max(right_height, left_height) + 1;
				n->bf = right_height - left_height;
			}

			node_type *balance(node_type *n){

				//? left heavy subtree
				if (n->bf == -2){
					// left_left case
					if (n->left_node->bf <= 0)
						return leftleft_case(n);
					// left_right case
					else
						return leftright_case(n);
				}
				//? right heavy subtree
				else if (n->bf == 2){
					// right_right case
					if (n->right_node->bf >= 0)
						return rightright_case(n);
					// right_left case
					else
						return rightleft_case(n);
				}
				// we return node without any rotation if |bf| < 1
				return (n);
			}

			node_type* leftleft_case(node_type* n){
				return right_rotation(n);				
			}

			node_type* rightright_case(node_type* n){
				return left_rotation(n);
			}

			node_type* leftright_case(node_type* n){
				n->left_node = left_rotation(n->left_node);
				return (right_rotation(n));
			}

			node_type* rightleft_case(node_type* n){
				n->right_node = right_rotation(n->right_node);
				return (left_rotation(n));
			}

			node_type* right_rotation(node_type* n){

				node_type *new_parent = n->left_node;
				n->left_node = new_parent->right_node;
				new_parent->right_node = n;
				update(n);
				update(new_parent);
				return (new_parent);
			}

			node_type* left_rotation(node_type* n){

				node_type *new_parent = n->right_node;
				n->right_node = new_parent->left_node;
				new_parent->left_node = n;
				update(n);
				update(new_parent);
				return (new_parent);
			}

			node_type* remove(node_type *n, T data){

				if (n == NULL)
					return (NULL);
				int diff = _comp(data.first, n->data.first);
				if (diff > 0)
					n->left_node = remove(n->left_node, data);
				else if (diff == 0 && n->right_node != NULL && n->data.first != data.first)
					n->right_node = remove(n->right_node, data);
				else{
					if ((n->left_node != NULL && n->right_node == NULL) ||
							(n->left_node == NULL && n->right_node != NULL)){
						node_type *tmp = (n->left_node != NULL) ? n->left_node : n->right_node;
						_root = tmp;
						tmp = NULL;
						delete tmp;
						return (_root);
					}
					//? choose the successor from the subtree with the greatest hight (± tree balanced)
					else if (n->left_node != NULL && n->right_node != NULL){
						if (n->left_node->height >= n->right_node->height){
							T successor = max(n->left_node);
							n->data = successor;
							n->left_node = remove(n->left_node, successor);
						}
						else{
							T successor = min(n->right_node);
							n->data = successor;
							n->right_node = remove(n->right_node, successor);
						}
					}
					else{ // n->left_node == NULL && n->right_node == NULL
						delete n;
						return (NULL);
					}	
				}
				update(n);
				return (balance(n));
			}

			void display(const std::string& prefix, const node_type* n, bool is_left){

				if (n != NULL){
					std::cout << prefix;
					std::cout << (is_left ? "├L──" : "└R──");
					//? print the value of the node
					std::cout << n->data.first << std::endl;
					//? next level tree left & right branch
					display(prefix + (is_left ? "|	" : "	"), n->left_node, true);
					display(prefix + (is_left ? "|	" : "	"), n->right_node, false);
				}
			}


			node_type   *_root;
			Compare     _comp;
			Alloc_node  _alloc_node;
			Alloc       _alloc;
			int         _nbr_node;
	};
	
}

#endif