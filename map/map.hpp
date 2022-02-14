/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:12:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/14 13:49:55 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avltree.hpp"
#include "../tools/tools.hpp"
#include "../tools/biterator.hpp"
#include "../tools/reverse_iterator.hpp"

namespace ft{

	template < typename Key, typename T, typename Compare = std::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{

		public:

			typedef size_t																		size_type;
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef ft::pair<const Key,T>														value_type;
			typedef Compare																		key_compare;
			//* typedef value_compare https://www.cplusplus.com/reference/map/map/value_comp/;
			typedef Alloc																		allocator_type;
			typedef typename allocator_type::reference											reference;
			typedef typename allocator_type::const_reference									const_reference;
			typedef typename allocator_type::pointer											pointer;
			typedef typename allocator_type::const_pointer										const_pointer;
			typedef typename ft::biterator<std::bidirectional_iterator_tag, value_type>			biterator;
			typedef typename ft::biterator<std::bidirectional_iterator_tag, const value_type>	const_biterator;
			typedef typename ft::reverse_iterator<biterator>									reverse_iterator;
			typedef typename ft::reverse_iterator<const_biterator>								const_reverse_iterator;

			typedef typename ft::node<ft::pair<const Key,T> > 									node_type;
			typedef typename ft::avltree<ft::pair<const Key,T> >								tree_type;


			//? Constructs a map container object
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
				 _comp(comp), _alloc(alloc), _tree(){}

			map (const map& x): _tree() { *this = x; }

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc), _tree(){

					while (first != last){
						_tree.insert(*first);
						++first;	
					}
			}

			//? Map destructor
			//? This destroys all container elements, and deallocates all the storage capacity allocated by the map container using its allocator.
			~map(void){}// _tree.clear(_tree._root); }

			//? Copy container content
			map& operator= (const map& x){

				_alloc = x._alloc;
				_comp = x._comp;
				_tree = x._tree;
				return (*this);
			}

			//* iterators ************************************************ //

			// ? Returns an iterator referring to the first element in the map container
			biterator begin(){

				node_type* start = _tree._root;
				while (start->left_node != NULL)
					start = start->left_node;
				return (biterator(start, &_tree));
			}
			const_biterator begin() const{

				node_type* start = _tree._root;
				while (start->left_node != NULL)
					start = start->left_node;
				return (biterator(start, &_tree));

			}

			//? Returns an iterator referring to the past-the-end element in the map container
			biterator end() { return (biterator(NULL, &_tree)); }
			const_biterator end() const { return (biterator(NULL, &_tree)); }

			//? Return reverse iterator to reverse beginning
			reverse_iterator rbegin(){ return (reverse_iterator(this->end())); }
			const_reverse_iterator rbegin() const { return (reverse_iterator(this->end())); }

			//? Return reverse iterator to reverse end
			reverse_iterator rend(){ return (reverse_iterator(this->begin())); }
			const_reverse_iterator rend() const { return (reverse_iterator(this->begin())); }

			//* Capacity ************************************************** //

			//? Test whether container is empty
			bool empty(void) const{ return _tree.is_empty(); }

			//? Return container size
			size_type size(void) const { return _tree.size(); }

			//? Return maximum size
			size_type max_size(void) const { return _alloc.max_size(); }

			//* Element access ******************************************** //

			//? Access element
			// A call to this function is equivalent to: (*((this->insert(make_pair(k,mapped_type()))).first)).second
			mapped_type& operator[] (const key_type& k){
				mapped_type *v = _tree.search(k);
				return (*v);
			}

			//* Modifiers ************************************************* //

			//? Insert elements
			// biterator insert (const value_type& val);
			pair<biterator,bool> insert (const value_type& val)
			{
				node_type* n;
				if (_tree.exist(val)){
					n = _tree.find_(val);
					biterator it (n, &_tree);
					return ft::make_pair(it, false);
				}
				n = _tree.insert(val);
				biterator it (n, &_tree);
				return ft::make_pair(it, true);
			}

			biterator insert (biterator position, const value_type& val){

				(void)position;
				node_type* n;
				n = _tree.insert(val);
				return biterator(n, &_tree);
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last){

				while (first != last){
					insert(*first);
					++first;
				}
			}

			//? Erase elements
			void erase (biterator position){ _tree.remove_(position.get_ptr()->data.first); }

			size_type erase (const key_type& k){ return _tree.remove_(k); }

			void erase (biterator first, biterator last){

				while (first != last){
					// erase(first);
					_tree.remove_(first.get_ptr()->data.first);
					++first;
				}
			}

			//? Swap content
			void swap (map& x);

			//? Removes all elements from the map container
			//(which are destroyed), leaving the container with a size of 0.
			void clear();

			//* Observers ************************************************* //

			//? Return key comparison object
			key_compare key_comp() const;

			//? Return value comparison object
			// value_compare value_comp() const; // typedef value compare

			//* Operations ************************************************* //

			//? Get iterator to element
			// Searches the container for an element with a key equivalent to k
			// and returns an iterator to it if found, otherwise it returns an iterator to map::end.
			biterator find (const key_type& k){

				node_type* n;
				if (_tree.exist(k)){
					n = _tree.find_(k);
					return biterator(n, &_tree);
				}
				else
					return biterator(NULL, NULL);
			}

			const_biterator find (const key_type& k) const{

				node_type* n;
				if (_tree.exist(k)){
					n = _tree.find_(k);
					return biterator(n, &_tree);
				}
				else
					return biterator(NULL, NULL);
			}

			//* Two keys are considered equivalent if the container's comparison object returns false reflexively
			//* (i.e., no matter the order in which the elements are passed as arguments).

			//? Searches the container for elements with a key equivalent to k and returns the number of matches
			size_type count (const key_type& k) const{

				if (_tree.exist(k))
					return (1);
				return (0);
			}

			//? Return iterator to lower bound
			biterator lower_bound (const key_type& k){

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(this->rbegin()->first, k) > 0){
					std::cout << "undefined behaviour 9223372036854775807" << std::endl;
					return biterator(NULL, NULL);
				}
				else{
					biterator it = this->begin(), ite = this->end();
					while (--ite != it){
						if (_comp(k, ite->first) <= 0){
							if (_comp(ite->first, k) > 0)
								++ite;
							return (ite);
						}
					}
				}
				return biterator(NULL, NULL);
			}

			const_biterator lower_bound (const key_type& k) const{

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(this->rbegin()->first, k) > 0){
					std::cout << "undefined behaviour 9223372036854775807" << std::endl;
					return biterator(NULL, NULL);
				}
				else{
					biterator it = this->begin(), ite = this->end();
					while (--ite != it){
						if (_comp(k, ite->first) <= 0){
							if (_comp(ite->first, k) > 0)
								++ite;
							return (ite);
						}
					}
				}
				return biterator(NULL, NULL);
			}

			//? Return iterator to upper bound
			biterator upper_bound (const key_type& k){

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(k, this->rbegin()->first) > 0){
					biterator it = this->begin(), ite = this->end();
					while (it != ite){
						if (_comp(k, it->first) > 0)
							return (it);
						it++;
					}
				}
				std::cout << "undefined behaviour 9223372036854775807" << std::endl;
				return biterator(NULL, NULL);
			}

			const_biterator upper_bound (const key_type& k) const{

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(k, this->rbegin()->first) > 0){
					biterator it = this->begin(), ite = this->end();
					while (it != ite){
						if (_comp(k, it->first) > 0)
							return (it);
						it++;
					}
				}
				std::cout << "undefined behaviour 9223372036854775807" << std::endl;
				return biterator(NULL, NULL);
			}

			//? Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
			pair<const_biterator,const_biterator> equal_range (const key_type& k) const{

				const_biterator b1, b2;
				
			}

			pair<biterator,biterator>             equal_range (const key_type& k);

			//* Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the map
			allocator_type get_allocator() const { return _alloc; }

			tree_type& get_tree(void){ return _tree; }

		private:
			key_compare		_comp;
			allocator_type	_alloc;
			tree_type		_tree;
			
			
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
//* allocator::rebind
//* test bidirectional iterator
//* reverse iterator

////TODO > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >

//* implement map member functions
	//! operator= & destructor   - avltree class -
		//? assignment operator for avltree class 
		//? implement create node function
		//? clear avltree
	//! swap
	//! observers

//* value compare
//* enable_if


//ToDo------ Canonical form		./5
//ToDo------ Iterators			4/4
//ToDo------ Capacity			3/3
//ToDo------ Element access		1/1
//ToDo------ Modifiers			3/8
//ToDo------ Observers			./2
//ToDo------ Operations			4/5
//ToDo------ Allocator			./1
