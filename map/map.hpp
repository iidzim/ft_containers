/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:12:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/08 18:56:43 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avltree.hpp"
#include "../tools/biterator.hpp"
#include "../tools/reverse_iterator.hpp"


namespace ft{

	template < typename Key, typename T, typename Compare = std::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{

		typedef size_t															size_type;
		typedef Key																key_type;
		typedef T																mapped_type;
		typedef ft::pair<const Key,T>											value_type;
		typedef Compare															key_compare;
		// * typedef value_compare; https://www.cplusplus.com/reference/map/map/value_comp/
		typedef Alloc															allocator_type;
		typedef typename allocator_type::reference								reference;
		typedef typename allocator_type::const_reference						const_reference;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename ft::biterator<std::bidirectional_iterator_tag, T>		biterator;
		typedef typename ft::biterator<std::bidirectional_iterator_tag, const T>	const_biterator;
		typedef typename ft::reverse_iterator<biterator>							reverse_iterator;
		typedef typename ft::reverse_iterator<const_biterator>					const_reverse_iterator;

		typedef typename ft::node<T> 											node_type;
		typedef typename ft::avltree<ft::node<T> > 								tree_type;



		public:

			//? Constructs a map container object
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _comp(comp), _tree(NULL){}

			map (const map& x):_tree(NULL) { *this = x; }

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), _tree(NULL){}

			//? Map destructor
			//? This destroys all container elements, and deallocates all the storage capacity allocated by the map container using its allocator.
			~map(void){}

			//? Copy container content
			map& operator= (const map& x){

				_alloc = x._alloc;
				_comp = x._comp;
				//! memory allocation for tree
				return (*this);
			}

			//* iterators ************************************************ //

			//? Returns an iterator referring to the first element in the map container
			biterator begin(){

				node_type* start = _tree->_root;
				while (start->left_node != NULL)
					start = start->_left;
				return biterator<std::bidirectional_iterator_tag, value_type>(start, _tree);
			}
			const_biterator begin() const{

				node_type* start = _tree->_root;
				while (start->left_node != NULL)
					start = start->_left;
				return biterator<std::bidirectional_iterator_tag, value_type>(start, _tree);
			}

			//? Returns an iterator referring to the past-the-end element in the map container
			biterator end()
			{
				node_type* end = _tree->_root;
				while (end->right_node != NULL)
					end = end->right_node;
				
				return ++(biterator<std::bidirectional_iterator_tag, value_type>(n, _tree));
			}

			const_biterator end() const
			{
				node_type* end = _tree->_root;
				while (end->right_node != NULL)
					end = end->right_node;
				
				return ++(biterator<std::bidirectional_iterator_tag, value_type>(n, _tree));
			}

			//? Return reverse iterator to reverse beginning
			reverse_iterator rbegin(){ return reverse_biterator(this->end()); };
			const_reverse_iterator rbegin() const { return reverse_biterator(this->end()); }

			//? Return reverse iterator to reverse end
			reverse_iterator rend(){ return reverse_biterator(this->begin()); }
			const_reverse_iterator rend() const { return reverse_biterator(this->begin()); }

			//* Capacity ************************************************** //

			//? Test whether container is empty
			bool empty() const{ return _tree->is_empty(); }

			//? Return container size
			size_type size() const { return _tree->size(); }

			//? Return maximum size
			size_type max_size() const { return _alloc.max_size(); }

			//* Element access ******************************************** //

			//? Access element
			// A call to this function is equivalent to: (*((this->insert(make_pair(k,mapped_type()))).first)).second
			mapped_type& operator[] (const key_type& k){
				return _tree->search(k);
			}

			//* Modifiers ************************************************* //

			//? Insert elements
			// biterator insert (const value_type& val);
			pair<biterator,bool> insert (const value_type& val)
			{
				node_type* n;
				if (_tree->exist(val)){
					n = find(val);
					return make_pair(biterator(n, _tree), false);
				}
				n = insert(val);
				return make_pair(biterator(n, _tree), true);
			}

			biterator insert (biterator position, const value_type& val){

				node_type* n;
				n = insert(val);
				return biterator(n, _tree);
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last);

			//? Erase elements
			void erase (biterator position){ remove(position._ptr); }

			size_type erase (const key_type& k){ return remove(k); }

			void erase (biterator first, biterator last);

			//? Swap content
			void swap (map& x);

			//? Removes all elements from the map container
			//(which are destroyed), leaving the container with a size of 0.
			void clear();

			//* Observers ************************************************* //

			//? Return key comparison object
			key_compare key_comp() const;

			//? Return value comparison object
			//! value_compare value_comp() const; line29

			//* Operations ************************************************* //

			//? Get iterator to element
			// Searches the container for an element with a key equivalent to k
			// and returns an iterator to it if found, otherwise it returns an iterator to map::end.
			biterator find (const key_type& k);
			const_biterator find (const key_type& k) const;

			//? Searches the container for elements with a key equivalent to k and returns the number of matches
			size_type count (const key_type& k) const;

			//? Return iterator to lower bound
			biterator lower_bound (const key_type& k);
			const_biterator lower_bound (const key_type& k) const;

			//? Return iterator to upper bound
			biterator upper_bound (const key_type& k);
			const_biterator upper_bound (const key_type& k) const;

			//? Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
			pair<const_biterator,const_biterator> equal_range (const key_type& k) const;
			pair<biterator,biterator>             equal_range (const key_type& k);

			//* Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the map
			allocator_type get_allocator() const;

		private:
			key_compare		_comp;
			allocator_type	_alloc;
			tree_type		*_tree;
			
			
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
//* update parent_node for each node after insert and remove
//* overload operator= node
//* bidirectionnal iterator
	//? iterate over tree -> inorder traversal (ascending order)
	//? save current_pos (or node) and avl_tree
	//? implement post || pre & increment || decrement
	//? equality/inequality operators - friend 

////TODO > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >

//* implement map member functions
//* test bidirectional iterator
//* allocator::rebind
