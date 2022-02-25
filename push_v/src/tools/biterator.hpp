/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:57:20 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/24 21:30:41 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITERATOR_HPP
#define BITERATOR_HPP

#include <memory>
#include "tools.hpp"
#include "avltree.hpp"

namespace ft{

	template <typename Category, typename tree, typename node, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct biterator {

		typedef Category 	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef node		node_type;
		typedef tree		tree_type;

		biterator(void): _ptr(), _tree() {}
		biterator(node_type *p, tree_type *t): _ptr(p), _tree(t) {}
		biterator(const biterator& b){ *this = b; }
		~biterator(void){}
		biterator& operator=(const biterator& b){
			_ptr = b._ptr;
			_tree = b._tree;
			return (*this);
		}
		reference operator* () const { return (_ptr->data); }
		pointer operator-> () const { return (&(_ptr->data)); }
		friend bool operator== (const biterator& lhs, const biterator& rhs) { return lhs._ptr == rhs._ptr; }
		friend bool operator!= (const biterator& lhs, const biterator& rhs) { return (!(lhs == rhs)); }

		biterator& operator++ (){
			if (_ptr == NULL){
				_ptr = _tree->_root;
				while (_ptr != NULL && _ptr->left_node != NULL) // min value in the tree
					_ptr = _ptr->left_node;
			}
			else if (_ptr->right_node != NULL){
				// successor = smallest value in the right subtree
				_ptr = _ptr->right_node;
				while (_ptr->left_node != NULL)
					_ptr = _ptr->left_node;
			}
			else{
				node_type* new_parent = _ptr->parent_node;
				while (new_parent != NULL && _ptr == new_parent->right_node){
					_ptr = new_parent;
					new_parent = new_parent->parent_node;
				}
				_ptr = new_parent;
			}
			return (*this);
		}

		biterator operator++ (int){

			biterator tmp = *this;
			++(*this);
			return (tmp);
		}

		biterator  operator-- (){

			if (_ptr == NULL){
				_ptr = _tree->_root;
				while (_ptr != NULL && _ptr->right_node != NULL)
					_ptr = _ptr->right_node;
			}
			else if (_ptr->left_node != NULL){
				_ptr = _ptr->left_node;
				while (_ptr->right_node != NULL) // max value in the right subtree
					_ptr = _ptr->right_node;
			}
			else{
				node_type* new_parent = _ptr->parent_node;
				while (new_parent != NULL && _ptr == new_parent->left_node){
					_ptr = new_parent;
					new_parent = new_parent->parent_node;
				}
				_ptr = new_parent;
			}
			return (*this);
		}

		biterator  operator-- (int){

			biterator tmp = *this;
			--(*this);
			return (tmp);
		}

		node_type* get_ptr(void) { return _ptr; }

		operator biterator<iterator_category, const tree_type, const node_type, const T>(){
			return biterator<iterator_category, const tree_type, const node_type, const T>(_ptr, _tree);
		}

		private:
			node_type *_ptr;	// points to the node denoting our current position within that tree
			tree_type *_tree;	// points to the tree that we are walking through

	};
}

#endif