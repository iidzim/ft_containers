/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:12:19 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/25 12:59:26 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "vector.hpp"
#include "./tools/avltree.hpp"
#include "./tools/tools.hpp"
#include "./tools/biterator.hpp"
#include "./tools/reverse_iterator.hpp"

namespace ft{

	template < typename Key, typename T, typename Compare = std::less<Key>,
		typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map{

		public:

			typedef size_t																										size_type;
			typedef Key																											key_type;
			typedef T																											mapped_type;
			typedef ft::pair<const Key,T>																						value_type;
			typedef Compare																										key_compare;

			typedef class value_compare : public std::binary_function<value_type, value_type, bool>{
				friend class map;
				protected:
					Compare _comp;
					value_compare (Compare c) : _comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const{
						return _comp(x.first, y.first);
					}
			}																													value_compare;
			typedef Alloc																										allocator_type;
			typedef typename allocator_type::reference																			reference;
			typedef typename allocator_type::const_reference																	const_reference;
			typedef typename allocator_type::pointer																			pointer;
			typedef typename allocator_type::const_pointer																		const_pointer;
			typedef typename ft::node<ft::pair<const Key,T> > 																	node_type;
			typedef typename ft::avltree<ft::pair<const Key,T>, Compare, Alloc>													tree_type;
			typedef typename ft::biterator<std::bidirectional_iterator_tag, tree_type, node_type, value_type>					biterator;
			typedef typename ft::biterator<std::bidirectional_iterator_tag, const tree_type, const node_type, const value_type>	const_biterator;
			typedef typename ft::reverse_iterator<biterator>																	reverse_iterator;
			typedef typename ft::reverse_iterator<const_biterator>																const_reverse_iterator;

			//? Constructs a map container object
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
				 _comp(comp), _alloc(alloc), _tree(){ }

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
			~map(void){} //use avl_tree destructor

			//? Copy container content
			map& operator= (const map& x){

				_tree.clear();
				_alloc = x._alloc;
				_comp = x._comp;
				_tree = x._tree;
				return (*this);
			}

			//* iterators ************************************************ //

			// ? Returns an iterator referring to the first element in the map container
			biterator begin(){

				node_type* start = _tree._root;
				while (start != NULL && start->left_node != NULL)
					start = start->left_node;
				return (biterator(start, &_tree));
			}

			const_biterator begin() const {

				node_type* start = _tree._root;
				while (start != NULL && start->left_node != NULL)
					start = start->left_node;
				return (const_biterator(start, &_tree));
			}

			//? Returns an iterator referring to the past-the-end element in the map container
			biterator end() { return (biterator(NULL, &_tree)); }
			const_biterator end() const { return const_biterator(NULL, &_tree); }

			//? Return reverse iterator to reverse beginning
			reverse_iterator rbegin(){ return (reverse_iterator(this->end())); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }

			//? Return reverse iterator to reverse end
			reverse_iterator rend(){ return (reverse_iterator(this->begin())); }
			const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }

			//* Capacity ************************************************** //

			//? Test whether container is empty
			bool empty(void) const{ return _tree.is_empty(); }

			//? Return container size
			size_type size(void) const { return _tree.size(); }

			//? Return maximum size
			size_type max_size(void) const { return _alloc.max_size(); }

			//* Element access ******************************************** //

			//? Access element
			/* 
			** If k matches the key of an element in the container, the function returns a reference to its mapped value.
			** If k does not match the key of any element in the container, the function inserts a new element
			** with that key and returns a reference to its mapped value. Notice that this always increases the container size by one,
			** even if no mapped value is assigned to the element (the element is constructed using its default constructor).
			*/
			mapped_type& operator[] (const key_type& k){

				this->insert(ft::make_pair(k,mapped_type()));
				return (this->find(k).get_ptr())->data.second;
			}

			//* Modifiers ************************************************* //

			//? Insert elements
			pair<biterator,bool> insert (const value_type& val)
			{
				if (_tree.exist(val))
					return ft::make_pair(biterator(_tree.find_node(val), &_tree), false);
				return ft::make_pair(biterator(_tree.insert(val), &_tree), true);
			}

			biterator insert (biterator position, const value_type& val){

				(void)position;
				return biterator(_tree.insert(val), &_tree);
			}

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last){

				for(; first != last; first++)
					insert(*first);
			}

			//? Erase elements
			void erase (biterator position){ _tree.remove_(position.get_ptr()->data.first); }

			size_type erase (const key_type& k){ return _tree.remove_(k); }

			void erase (biterator first, biterator last){

				ft::vector<int> v;
				for (; first != last; first++)
					v.push_back(first.get_ptr()->data.first);
				for (ft::vector<int>::iterator it = v.begin(); it < v.end(); it++)
					_tree.remove_(*it);
			}

			//? Swap content
			void swap (map& x){

				std::swap(_comp, x._comp);
				std::swap(_alloc, x._alloc);
				std::swap(_tree._root, x._tree._root);
				std::swap(_tree._nbr_node, x._tree._nbr_node);
			}

			//? Removes all elements from the map container
			//(which are destroyed), leaving the container with a size of 0.
			void clear(){ _tree.clear(); }

			//* Observers ************************************************* //

			//? Return key comparison object
			key_compare key_comp() const { key_compare k(_comp); return k; }

			//? Return value comparison object
			value_compare value_comp() const{ return value_compare(_comp); }

			//* Operations ************************************************* //

			//? Get iterator to element
			// Searches the container for an element with a key equivalent to k
			// and returns an iterator to it if found, otherwise it returns an iterator to map::end.
			biterator find (const key_type& k){

				if (_tree.exist(k))
					return biterator(_tree.find_node(k), &_tree);
				return this->end();
			}

			const_biterator find (const key_type& k) const{ return const_biterator(find(k)); }

			//? Searches the container for elements with a key equivalent to k and returns the number of matches
			size_type count (const key_type& k) const{ return (_tree.exist(k)); }

			//? Return iterator to lower bound
			biterator lower_bound (const key_type& k){

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(k, this->rbegin()->first) > 0){
					if (_tree.exist(k))
						return biterator(_tree.find_node(k), &_tree);
					biterator it = this->begin(), ite = this->end();
					while (it != ite){
						if (_comp(k, it->first) || it->first == k)
							return (it);
						it++;
					}
				}
				return this->end();
			}

			const_biterator lower_bound (const key_type& k) const {

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(k, this->rbegin()->first) > 0){
					if (_tree.exist(k))
						return const_biterator(_tree.find_node(k), &_tree);
					const_biterator it = this->begin(), ite = this->end();
					while (it != ite){
						if (_comp(k, it->first) || it->first == k)
							return const_biterator(it);
						it++;
					}
				}
				return this->end();
			}

			//? Return iterator to upper bound
			biterator upper_bound (const key_type& k){

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(k, this->rbegin()->first) > 0){
					if (_tree.exist(k))
						return ++(biterator(_tree.find_node(k), &_tree));
					biterator it = this->begin(), ite = this->end();
					while (it != ite){
						if (_comp(k, it->first) > 0)
							return (it);
						it++;
					}
				}
				return this->end();
			}

			const_biterator upper_bound (const key_type& k) const {

				if (_comp(k, this->begin()->first) > 0)
					return this->begin();
				else if (_comp(k, this->rbegin()->first) > 0){
					if (_tree.exist(k))
						return ++(const_biterator(_tree.find_node(k), &_tree));
					const_biterator it = this->begin(), ite = this->end();
					while (it != ite){
						if (_comp(k, it->first) > 0)
							return (it);
						it++;
					}
				}
				return this->end();
				}

			//? Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k
			pair<biterator,biterator> equal_range (const key_type& k){ return ft::make_pair(lower_bound(k), upper_bound(k)); }

			pair<const_biterator,const_biterator> equal_range (const key_type& k) const{ return ft::make_pair(lower_bound(k), upper_bound(k)); }

			//* Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the map
			allocator_type get_allocator() const { allocator_type al(_alloc); return al; }

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
