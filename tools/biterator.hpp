/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:57:20 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/07 18:55:20 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITERATOR_HPP
# define BITERATOR_HPP

#include <memory>
#include "tools.hpp"
#include "../map/avltree.hpp"

namespace ft{

	template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct biterator {

		typedef Category  iterator_category;
		typedef T			value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef typename ft::node<T> node_type;
		typedef typename ft::avltree<ft::node<T> > tree_type;

		biterator(void): _ptr(), _tree() {}
		biterator(node_type *p, tree_type *t): _ptr(p), _tree(t) {} //? parametrized constructor
		biterator(const biterator& b){ *this = b; }
		~biterator();
		biterator& operator=(const biterator& b){
			_ptr = b._ptr;
			_tree = b._tree;
			return (*this);
		}
		reference operator* () const { return (*_ptr); }
		pointer operator-> () { return (_ptr); }
		bool operator== (const biterator& rhs) const;
		bool operator!= (const biterator& rhs) const;
		biterator& operator++ (){

			
		}

		biterator operator++ (int);
		biterator  operator-- ();
		biterator  operator-- (int);





		private:
			node_type *_ptr;	// points to the node denoting our current position within that tree
			tree_type *_tree;	// points to the tree that we are walking through

	};
}

#endif