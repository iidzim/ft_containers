/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:12:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/17 14:41:07 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "avltree.hpp"
#include "../tools/tools.hpp"
#include "../vector/vector.hpp"
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
			typedef class value_compare : public std::binary_function<value_type, value_type, bool>{
				friend class map;
				protected:
					Compare _comp;
					value_compare (Compare c) : _comp(c) {}	// constructed with map's comparison object
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const{
						return _comp(x.first, y.first);
					}
			} value_compare;
			typedef Alloc																		allocator_type;
			typedef typename allocator_type::reference											reference;
			typedef typename allocator_type::const_reference									const_reference;
			typedef typename allocator_type::pointer											pointer;
			typedef typename allocator_type::const_pointer										const_pointer;
			// typedef typename ft::biterator<std::bidirectional_iterator_tag, value_type>			biterator;
			// typedef typename ft::biterator<std::bidirectional_iterator_tag, const value_type>	const_biterator;
			// typedef typename ft::const_biterator<std::bidirectional_iterator_tag, value_type>	const_biterator;

			typedef typename ft::node<ft::pair<const Key,T> > 									node_type;
			typedef typename ft::avltree<ft::pair<const Key,T> >								tree_type;
			
			typedef typename ft::biterator<std::bidirectional_iterator_tag, tree_type, node_type, value_type>			biterator;
			typedef typename ft::biterator<std::bidirectional_iterator_tag, const tree_type, const node_type, const value_type>	const_biterator;

			typedef typename ft::reverse_iterator<biterator>									reverse_iterator;
			typedef typename ft::reverse_iterator<const_biterator>								const_reverse_iterator;
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
			~map(void){ _tree.clear(); }

			//? Copy container content
			// map& operator= (const map& x){

			// 	_tree.clear();
			// 	_alloc = x._alloc;
			// 	_comp = x._comp;
			// 	_tree = x._tree;
			// 	// insert(x.begin(), x.end()); //? m2 : assign the tree using insert range, but first clear the old tree 
			// 	//! m2 error: non matching constructor biterator()
			// 	return (*this);
			// }

			map& assignment_op(const map& x){

				_tree.clear();
				_alloc = x._alloc;
				_comp = x._comp;
				_tree = x._tree;
				// insert(x.begin(), x.end()); //? m2 : assign the tree using insert range, but first clear the old tree 
				//! m2 error: non matching constructor biterator()
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

				// node_type* start = _tree._root;
				// while (start->left_node != NULL)
				// 	start = start->left_node;
				// return (const_biterator(start, &_tree));
				return const_biterator(begin());
			}

			//? Returns an iterator referring to the past-the-end element in the map container
			biterator end() { return (biterator(NULL, &_tree)); }
			const_biterator end() const { return const_biterator(end()); }

			//? Return reverse iterator to reverse beginning
			reverse_iterator rbegin(){ return (reverse_iterator(this->end())); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(rbegin()); }

			//? Return reverse iterator to reverse end
			reverse_iterator rend(){ return (reverse_iterator(this->begin())); }
			const_reverse_iterator rend() const { return const_reverse_iterator(rend()); }

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

				ft::vector<int> v;
				while (first != last){
					v.push_back(first.get_ptr()->data.first);
					first++;
				}
				for (ft::vector<int>::iterator it = v.begin(); it < v.end(); it++)
					_tree.remove_(*it);
			}

			//? Swap content
			void swap (map& x){

				std::swap(_comp, x._comp);
				std::swap(_alloc, x._alloc);
				map tmp = *this; // shallow copy
				*this = x;
				x = tmp;
			}

			//? Removes all elements from the map container
			//(which are destroyed), leaving the container with a size of 0.
			void clear(){ _tree.clear(); }

			//* Observers ************************************************* //

			//? Return key comparison object
			key_compare key_comp() const { return this->_comp; }

			//? Return value comparison object
			value_compare value_comp() const{ return value_compare(_comp); }

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

			const_biterator lower_bound (const key_type& k) const{ return const_biterator(lower_bound(k)); }

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

			const_biterator upper_bound (const key_type& k) const{ return const_biterator(upper_bound(k)); }

			//? Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
			pair<biterator,biterator> equal_range (const key_type& k){

				node_type* n;
				if (_tree.exist(k)){
					n = _tree.find_(k);
					biterator it(n, &_tree);
					biterator ite = this->end();
					if (it == --ite)
						return ft::make_pair(it, biterator(0, NULL));
					return ft::make_pair(it, ++it);
				}
				return ft::make_pair(upper_bound(k), upper_bound(k));
			}

			pair<const_biterator,const_biterator> equal_range (const key_type& k) const{

				node_type* n;
				if (_tree.exist(k)){
					n = _tree.find_(k);
					const_biterator it(n, &_tree);
					if (it == --(this->end()))
						return ft::make_pair(it, const_biterator(0, NULL));
					return ft::make_pair(it, ++it);
				}
				return ft::make_pair(upper_bound(k), upper_bound(k));
			}

			//* Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the map
			allocator_type get_allocator() const { return _alloc; }

			tree_type& get_tree(void){ return _tree; }

		private:
			key_compare		_comp;
			allocator_type	_alloc;
			tree_type		_tree;
			
			
	};

	//? Relational operators
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return (!(lhs < rhs));
	}

	//? swap
	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y){ x.swap(y); }

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
//* implement map member functions
	//? find & count
	//? lower_bound & upper_bound & equal range
	//! test insert
	//! fix erase(range)
	//? copy constructor
	//! operator= & destructor   - avltree class -
		//? assignment operator for avltree class
		//? implement create node function
		//? clear avltree
//* observers


////TODO > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >

// avltree::clear(){_alloc_node.deallocate(root, 1);} //! leaks -or- assign only the root of the tree 
//! swap
//! relational operators
//! const iterator


//ToDo------ Canonical form		3/5
//ToDo------ Iterators			4/4
//ToDo------ Capacity			3/3
//ToDo------ Element access		1/1
//ToDo------ Modifiers			6/8
//ToDo------ Observers			./2
//ToDo------ Operations			5/5
//ToDo------ Allocator			1/1
