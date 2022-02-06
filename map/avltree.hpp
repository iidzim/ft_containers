/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:16:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/06 11:08:36 by iidzim           ###   ########.fr       */
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

	template <typename T, typename Compare = std::less<T>, typename Alloc_node = std::allocator<ft::node<T> >, 
		typename Alloc = std::allocator <T> >
	class avltree{

		typedef T		value_type;
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

			bool exist(value_type value){
				return exist(_root, value);
			}

			bool insert(value_type value){

				if (!exist(_root, value)){
					_root = insert(_root, value);
					_nbr_node += 1;
					return (true);
				}
				return (false);
			}

			//? return the min value in the tree
			value_type min(node_type *root){

				while (root->left_node != NULL)
					root = root->left_node;
				return (root->data);
			}

			//? return the max value in the tree
			value_type max(node_type *root){

				while (root->right_node != NULL)
					root = root->right_node;
				return (root->data);
			}

			bool search (node_type root, value_type data){
				if (root == NULL)
					return false;
				else if (root.data == data)
					return true;
				else if (root.data > data)
					return search(root.left_node, data);
				else // (root.data < data)
					return search(root.right_node, data);
			}

			void display(const node_type* n){
				display("", n, false);
			}

			node_type* get_root(void){
				return (_root);
			}

			bool remove(value_type value){

				if (exist(_root, value)){
					_root = remove(_root, value);
					_nbr_node -= 1;
					return (true);
				}
				return (false);
			}

		private:

			bool exist(node_type *n, value_type value){

				if (n == NULL)
					return (false);
				int diff = _comp(value, n->data);
				if (n->data == value)
					return (true);
				if (diff == true)
					return exist(n->left_node, value);
				if (diff == false)
					return exist(n->right_node, value);
				return (true);
			}

			node_type* insert(node_type *n, value_type value){

				if (n == NULL){
					_root = _alloc_node.allocate(1);
					// _root->data = _alloc.allocate(1);
					_alloc.construct(&_root->data, value);
					_root->height = _root->bf = 0;
					_root->left_node = _root->right_node = _root->parent_node = NULL;
					return (_root);
				}
				int diff = _comp(value, n->data);
				if (diff == true) // Insert node in left subtree
					n->left_node = insert(n->left_node, value);
				else // Insert node in right subtree
					n->right_node = insert(n->right_node, value);
				update(n);	// Update balance factor and height values
				// return (n);
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

			node_type* remove(node_type *n, value_type value){

				if (n == NULL)
					return (NULL);
				int diff = _comp(value, n->data);
				std::cout << "diff = " << diff << std::endl;
				if (diff > 0){
					std::cout << "1 --> " << n->left_node->data  << " - difff = " << diff << "\n";
					n->left_node = remove(n->left_node, value);
				}
				else if (diff == 0 && n->right_node != NULL && n->data != value){
					std::cout << "2 --> " << n->right_node->data << "\n";
					n->right_node = remove(n->right_node, value);
				}
				else{
					//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
					std::cout << "3\n";
					if ((n->left_node != NULL && n->right_node == NULL) ||
						(n->left_node == NULL && n->right_node != NULL)){
						std::cout << "here\n";
						node_type *tmp = (n->left_node != NULL) ? n->left_node : n->right_node;
						_root = tmp;
						tmp = NULL;
						delete tmp;
						return (_root);
					}
					//? choose th successor from the subtree with the greatest hight (± tree balanced)
					else if (n->left_node != NULL && n->right_node != NULL){
						std::cout << "left node height = " << n->left_node->height << std::endl;
						std::cout << "right node height = " << n->right_node->height << std::endl;
						if (n->left_node->height >= n->right_node->height){
							value_type successor = max(n->left_node);
							std::cout << "successor = " << successor << std::endl;
							n->data = successor;
							n->left_node = remove(n->left_node, successor);
						}
						else{
							std::cout << "++++++++++++++" << "\n";
							value_type successor = min(n->right_node);
							std::cout << "successor = " << successor << std::endl;
							n->data = successor;
							n->right_node = remove(n->right_node, successor);
						}
					}
					else{// (n->left_node == NULL && n->right_node == NULL){
						std::cout << "ennddd"  << "\n";
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
					std::cout << n->data << std::endl;
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