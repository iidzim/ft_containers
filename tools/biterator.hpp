/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:57:20 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/20 12:27:45 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITERATOR_HPP
# define BITERATOR_HPP

#include <memory>
#include "tools.hpp"
#include "../map/avltree.hpp"

namespace ft{

	// template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	template <typename Category, typename tree, typename node, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct biterator {

		typedef Category  iterator_category;
		typedef T			value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		// typedef typename ft::node<T> node_type;
		// typedef typename ft::avltree<T> tree_type;
		typedef node node_type;
		typedef tree tree_type;

		biterator(void): _ptr(), _tree() {}
		biterator(node_type *p, tree_type *t): _ptr(p), _tree(t) {}
		biterator(const biterator& b){ 
			// std::cout << "CHECK FOR A" << std::endl;
			*this = b; 
			// std::cout << "CHECK FOR END" << std::endl;
		}
		~biterator(void){}
		biterator& operator=(const biterator& b){
			// std::cout << "CHECK FOR B" << std::endl;
			// std::cout << "CHECK FOR " << std::endl;
			_ptr = b._ptr;
			_tree = b._tree;
			// std::cout << "CHECK FOR __ "<< std::endl;
			return (*this);
		}
		reference operator* () const { std::cout << "before return \n\n" << std::endl ; return (_ptr->data); }
		pointer operator-> () const { return (&(_ptr->data)); }
		friend bool operator== (const biterator& lhs, const biterator& rhs) { return lhs._ptr == rhs._ptr; }
		friend bool operator!= (const biterator& lhs, const biterator& rhs) { return (!(lhs == rhs)); }

		biterator& operator++ (){
			// std::cout << "CHECK 00" << std::endl;
			if (_ptr == NULL){
				// std::cout << "CHECK 01" << std::endl;
				_ptr = _tree->_root;
				if (_ptr == NULL) // empty tree
					throw std::underflow_error("iterator");
				while (_ptr->left_node != NULL) // min value in the tree
					_ptr = _ptr->left_node;
			}
			else if (_ptr->right_node != NULL){
				std::cout << "CHECK 02" << std::endl;
				// successor = smallest value in the right subtree
				_ptr = _ptr->right_node;
				while (_ptr->left_node != NULL)
					_ptr = _ptr->left_node;
			}
			else{
				// std::cout << "CHECK 03" << _ptr->data.first << std::endl;
				node_type* new_parent = _ptr->parent_node;
				// std::cout << "CHECK 05 " << _ptr->data.first << std::endl;
				while (new_parent != NULL && _ptr == new_parent->right_node){
					_ptr = new_parent;
					new_parent = new_parent->parent_node;
					std::cout << "CHECK LOOP " << _ptr->data.first <<  std::endl;
					// std::cout << "CHECK LOOP** " << new_parent->data.first <<  std::endl;
				}
				_ptr = new_parent;
			}
			std::cout << "CHECK 05 " << std::endl;
			// std::cout << "CHECK 05 " << _ptr->data.first << std::endl;
			return (*this);
		}

		biterator operator++ (int){

			biterator tmp = *this;
			++(*this);
			return (tmp);
		}

		biterator  operator-- (){ //!!!!!!! segfault

			if (_ptr == NULL){
				_ptr = _tree->_root;
				if (_ptr == NULL)
					throw std::underflow_error("iterator");
				while (_ptr->right_node != NULL)
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
			// if (_ptr)
			std::cout << "cST   "   << this << std::endl;
			return biterator<iterator_category, const tree_type, const node_type, const T>(_ptr, _tree);
		}

		private:
			node_type *_ptr;	// points to the node denoting our current position within that tree
			tree_type *_tree;	// points to the tree that we are walking through

	};
}

#endif