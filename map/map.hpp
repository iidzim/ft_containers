/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:12:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/06 18:50:56 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avltree.hpp"

namespace ft{

	template < typename Key, typename T, typename Compare = std::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{

		typedef Key																ket_type;
		typedef T																mapped_value;
		typedef ft::pair<const Key,T>											value_type;
		typedef Compare															key_compare;
		// * typedef value_compare; https://www.cplusplus.com/reference/map/map/value_comp/
		typedef Alloc															allocator_type;
		typedef typename allocator_type::reference								reference;
		typedef typename allocator_type::const_reference						const_reference;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, T>		iterator;
		typedef typename ft::iterator<std::bidirectional_iterator_tag, const T>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;


		public:

			//? Constructs a map container object
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			
			map (const map& x);
			
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());

			//? Map destructor
			//? This destroys all container elements, and deallocates all the storage capacity allocated by the map container using its allocator.
			~map();

			//? Copy container content
			map& operator= (const map& x);

			//* iterators ************************************************ //

			//? Returns an iterator referring to the first element in the map container
			iterator begin();
			const_iterator begin() const;

			//? Returns an iterator referring to the past-the-end element in the map container
			iterator end();
			const_iterator end() const;

			//? Return reverse iterator to reverse beginning
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;

			//? Return reverse iterator to reverse end
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			//* Capacity ************************************************** //

			//? Test whether container is empty
			bool empty() const{
				if (_nbr_node == 0)
					return (true);
				return (false);
			}

			//? Return container size
			size_type size() const { return _nbr_node; }

			//? Return maximum size
			size_type max_size() const { return (_alloc.max_size()); }

			//* Element access ******************************************** //

			//? Access element
			// A call to this function is equivalent to: (*((this->insert(make_pair(k,mapped_type()))).first)).second
			mapped_type& operator[] (const key_type& k);

			//* Modifiers ************************************************* //

			//? Insert elements
			pair<iterator,bool> insert (const value_type& val);

			iterator insert (iterator position, const value_type& val);

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last);

			//? Erase elements
			void erase (iterator position);

			size_type erase (const key_type& k);

			void erase (iterator first, iterator last);

			//? Swap content
			void swap (map& x);

			//? Removes all elements from the map container
			//(which are destroyed), leaving the container with a size of 0.
			void clear();

			//* Observers ************************************************* //

			//? Return key comparison object
			key_compare key_comp() const;

			//? Return value comparison object
			value_compare value_comp() const;

			//* Operations ************************************************* //

			//? Get iterator to element
			// Searches the container for an element with a key equivalent to k
			// and returns an iterator to it if found, otherwise it returns an iterator to map::end.
			iterator find (const key_type& k);
			const_iterator find (const key_type& k) const;

			//? Searches the container for elements with a key equivalent to k and returns the number of matches
			size_type count (const key_type& k) const;

			//? Return iterator to lower bound
			iterator lower_bound (const key_type& k);
			const_iterator lower_bound (const key_type& k) const;

			//? Return iterator to upper bound
			iterator upper_bound (const key_type& k);
			const_iterator upper_bound (const key_type& k) const;

			//? Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			pair<iterator,iterator>             equal_range (const key_type& k);

			//* Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the map
			allocator_type get_allocator() const;

		private:
			key_compare		_comp;
			allocator_type	_alloc;
			int				_nbr_node;
			
			
	};

}


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
// * update _nbr_node value after each insertion +=1 
//* update height and bf
//* rebalance the tree if |bf| == 2
	//! leftLeft rotation
	//! rightright rotation
	//! leftright rotation  *update height and bf child node first then the parent node*
	//! rightLeft rotation  *update height and bf child node first then the parent node*
//* display the tree
	//? level order traversal
//* remove node..
//* 3 cases
	//! case1: the node is a leaf
	//! case2: the node have at most 1 child
	//! case3: the node have left and right child
		//? choose the successor and swap its value into the node
			// The successor is either the smallest value in the right subtree
			// or the largest value in the left subtree.
		//? remove the successor's node
		//? rebalance the tree
//* update nbr_node value after each insertion
// use min max functions instead
//* update height and bf
//* replace node->data with pair

////TODO > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >

//* update parent_node for each node after insert and remove
//* allocator::rebind
//* bidirectionnal iterator
//* implemetation of 3 types of traversal : preorder, inorder, postorder

