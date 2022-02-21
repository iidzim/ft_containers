/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avltree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:16:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/21 15:05:50 by iidzim           ###   ########.fr       */
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
		T		data; //? pair<U, V>
		int		bf; //? balance factor
		int		height; //? height of this node in the tree
		node*	parent_node;
		node*	left_node;
		node*	right_node;

		bool operator== (const node& rhs) const{
			return (data == rhs.data && bf == rhs.bf && height == rhs.height
				&& left_node == rhs.left_node && right_node == rhs.right_node
					&& parent_node == rhs.parent_node);
		}
	};

	template <typename T, typename Compare = std::less<typename T::first_type>,
		typename Alloc = std::allocator <T> >
	class avltree{

		typedef node<T>					node_type;
		typedef typename T::first_type	key_type;
		typedef typename T::second_type	mapped_value;
		typedef typename Alloc::template rebind<node_type>::other Alloc_node;

		public:

			avltree(void): _nbr_node(0), _root(){}
			~avltree(void){ clear(); }
			avltree& operator=(const avltree& t){

				clear();
				_comp = t._comp;
				_alloc = t._alloc;
				_alloc_node = t._alloc_node;
				_nbr_node = 0;
				insert_nodes(t._root);
				return (*this);
			}

			void insert_nodes(node_type* x){

				if (x != NULL){
					insert(x->data);
					insert_nodes(x->left_node);
					insert_nodes(x->right_node); 
				}
			}

			//* Capacity ************************************************** //

			//? The height of a rooted tree is the number of edges between the tree's root and its furthest leaf
			int height(void){
				if (_root == NULL)
					return (0);
				return (_root->height);
			}

			//? the number of nodes in the tree
			int size(void) const { return (_nbr_node); }
	
			bool is_empty(void) const {
				if (_nbr_node == 0)
					return (true);
				return (false);
			}

			//* Operations ************************************************* //

			bool exist(T value) const {
				return exist(_root, value);
			}

			bool exist(key_type key) const {
				return exist(_root, key);
			}

			T min(node_type *root)const {

				while (root->left_node != NULL)
					root = root->left_node;
				return (root->data);
			}

			T max(node_type *root)const {

				while (root->right_node != NULL)
					root = root->right_node;
				return (root->data);
			}

			mapped_value* search(key_type& key){
				return search(_root, key);
			}

			node_type* find_(T p) const {
				return find_(_root, p.first);
			}

			node_type* find_(key_type key) const {
				return find_(_root, key);
			}

			//* Modifiers ************************************************* //

			node_type* insert(T data){

				if (!exist(_root, data)){
					_root = insert(_root, data);
					_nbr_node += 1;
					return (_root);
				}
				return (NULL);
			}

			int remove_(key_type key){

				if (exist(_root, key)){
					_root = remove_(_root, key);
					_nbr_node -= 1;
					return (1);
				}
				return (0);
			}

			void clear(void){
				clear(_root);
			}

			//* Print Content ************************************************* //

			void display(const node_type* n){
				display("", n, false);
			}

			void print_parent(node_type* n){

				if(n->left_node != NULL)
					print_parent(n->left_node);
				if(n->right_node != NULL)
					print_parent(n->right_node);
				if(n->parent_node != NULL)
					std::cout << "Parent of " << n->data.first << " is " << n->parent_node->data.first << std::endl;
				else
					std::cout << "The root node is " << n->data.first << std::endl;
			}

		private:

			//* Operations ************************************************* //

			node_type* find_(node_type *root, key_type key) const {

				if (root == NULL)
					return (NULL);
				else if (root->data.first == key)
					return (root);
				else if (root->data.first > key)
					return find_(root->left_node, key);
				else
					return find_(root->right_node, key);
			}

			mapped_value* search (node_type *root, key_type& key){

				if (root == NULL)
					return (0);
				else if (root->data.first == key)
					return (&(root->data.second));
				else if (root->data.first > key)
					return search(root->left_node, key);
				else
					return search(root->right_node, key);
			}

			bool exist(node_type *n, T data) const {

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

			bool exist(node_type *n, key_type key) const {

				if (n == NULL)
					return (false);
				int diff = _comp(key, n->data.first);
				if (n->data.first == key)
					return (true);
				if (diff == true)
					return exist(n->left_node, key);
				if (diff == false)
					return exist(n->right_node, key);
				return (true);
			}

			//* Modifiers ************************************************* //

			node_type* insert(node_type *n, T data){

				if (n == NULL){
					_root = _alloc_node.allocate(1);
					_alloc.construct(&_root->data, data);
					_root->height = _root->bf = 0;
					_root->left_node = _root->right_node = _root->parent_node = NULL;
					return (_root);
				}
				int diff = _comp(data.first, n->data.first);
				if (diff == true){
					node_type* lnode = insert(n->left_node, data);
					n->left_node = lnode;
					lnode->parent_node = n;
				}
				else{
					node_type* rnode = insert(n->right_node, data);
					n->right_node = rnode;
					rnode->parent_node = n;
				}
				update(n);	// Update balance factor and height values
				return balance(n);
			}

			node_type* remove_(node_type *n, key_type key){

				if (n == NULL)
					return (NULL);
				int diff = _comp(key, n->data.first);
				if (diff > 0)
					n->left_node = remove_(n->left_node, key);
				else if (diff == 0 && n->right_node != NULL && n->data.first != key)
					n->right_node = remove_(n->right_node, key);
				else{
					if ((n->left_node != NULL && n->right_node == NULL) ||
							(n->left_node == NULL && n->right_node != NULL)){
						//? one child (left or right)
						node_type *tmp = (n->left_node != NULL) ? n->left_node : n->right_node;
						_root = tmp;
						_root->parent_node = n->parent_node;	//! update parent
						tmp = NULL;
						delete tmp; //todo----------leaks
						return (_root);
					}
					//* The successor is either the smallest value in the right subtree
					//* or the largest value in the left subtree.
					//? choose the successor from the subtree with the greatest height (~ tree balanced)
					else if (n->left_node != NULL && n->right_node != NULL){
						node_type *parent = n->parent_node;
						if (n->left_node->height >= n->right_node->height){
							T successor = max(n->left_node);
							_alloc.construct(&n->data, successor);
							n->parent_node = parent;
							n->left_node = remove_(n->left_node, successor.first);
						}
						else{
							T successor = min(n->right_node);
							_alloc.construct(&n->data, successor);
							n->parent_node = parent;
							n->right_node = remove_(n->right_node, successor.first);
						}
					}
					else{ //? n->left_node == NULL && n->right_node == NULL -> leaf
						delete n;
						return (NULL);
					}
				}
				update(n);
				return (balance(n));
			}

			void clear(node_type* root){

				if (root != NULL){
					_alloc.destroy(&(root->data));
					clear(root->left_node);
					clear(root->right_node);
					_alloc_node.deallocate(root, 1); //! heap-use-after-free
				}
				_nbr_node = 0;
			}

			//* Rotations ************************************************* //

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

				// std::cout << "right_rotation\n";
				node_type *new_parent = n->left_node;
				n->left_node = new_parent->right_node;
				new_parent->right_node = n;
				//? update parent
				new_parent->parent_node = n->parent_node;
				n->parent_node = new_parent;
				if (n->left_node != NULL)
					n->left_node->parent_node = new_parent->right_node;
				update(n);
				update(new_parent);
				return (new_parent);
			}

			node_type* left_rotation(node_type* n){

				// std::cout << "left_rotation\n";
				node_type *new_parent = n->right_node;
				n->right_node = new_parent->left_node;
				new_parent->left_node = n;
				//? update parent
				new_parent->parent_node = n->parent_node;
				n->parent_node = new_parent;
				if (n->right_node != NULL)
					n->right_node->parent_node = new_parent->left_node;
				update(n);
				update(new_parent);
				return (new_parent);
			}

			//* Print Tree ************************************************* //

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


			Compare     _comp;
			Alloc_node  _alloc_node;
			Alloc       _alloc;
			int         _nbr_node;
			
		public:
			node_type   *_root;

	};

}

#endif