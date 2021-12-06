/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/06 12:51:03 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include "../tools/iterator.hpp"
#include "../tools/reverse_iterator.hpp"
// #include <iterator>
#include <memory>

namespace ft{

	template <typename T, typename Alloc = std::allocator <T> >
	class vector{

		public:

			typedef	T									value_type;
			typedef	Alloc								allocator_type;
			typedef size_t								size_type;
			typedef typename Alloc::reference			reference;
			typedef typename Alloc::const_reference		const_reference;
			typedef typename Alloc::pointer				pointer;
			typedef typename Alloc::const_pointer		const_pointer;
			typedef typename ft::iterator<T>			iterator;
			typedef typename ft::iterator<T>			const_iterator;
			typedef typename ft::reverse_iterator<T>	reverse_iterator;
			typedef typename ft::reverse_iterator<T>	const_reverse_iterator;

			//? Constructs an empty container with the given allocator alloc
			explicit vector (const allocator_type& alloc = allocator_type()){

				// this->_arr = NULL;
				this->_start = this->_end = 0;
				this->_size = 0;
				this->_capacity = 0;
				this->_alloc = alloc;
			}

			//? Constructs the container with count copies of elements with value
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()){

				this->_alloc = alloc;
				this->_size = n;
				this->_capacity = n;
				if (this->_size > 0)
				{
					// this->_arr = alloc.allocate(n);
					// alloc.construct(this->_arr, val);
					this->_start = alloc.allocate(n);
					this->_end = this->_start + n;
					for (iterator it = this->_start; it < this->_end; it++)
						alloc.construct(it, val);
				}
				else
					// this->_arr = NULL;
					this->_start = this->_end = 0;
			}

			//? Constructs the container with the contents of the range [first, last)
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){

				//* The allocator parameter is copied into a private member of the container
				//* This private copy can then be used for all subsequent storage management
				this->_alloc = alloc;
				//* An initial buffer is allocated using the allocator's allocate function
				this->_start = this->_alloc.allocate(last - first);
				this->_end = this->_start + (last - first);
				for (iterator it = this->_start; it < this->_end; it++)
					this->_alloc.allocate(it, *(first + it));
			}

			//? Copy constructor
			vector (const vector& x){
				this = x;
			}

			//? Destroys the container object
			~vector(void){
				for (iterator it = this->_start; it < this->_start + this->_capacity; it++)
					this->_alloc.deallocate(it, 1);
				for (iterator it = this->_start; it < this->_end; it++)
					this->_alloc.destroy(it);
			}

			//? Assigns new contents, replacing its current contents, and modifying its size accordingly.
			vector& operator= (const vector& x){ //! wrong ! use insert !!!!!

				// if (this != x) // self assignment
				// {
				// 	this->_capacity = x._capacity;
				// 	this->_size = x._size;
				// 	for (int i=0; i < this->_size; i++)
				// 		this->_arr[i] = x._arr[i];
				// }
				// return (*this);
			}

			//! iterators ************************************************ //

			//? Returns an iterator pointing to the first element
			iterator begin(){ return (this->_start); }
			
			const_iterator begin() const{ return (this->_start); }

			//? Returns an iterator referring to the past-the-end element in the vector
			iterator end(){ return (this->_end); }

			const_iterator end() const{ return (this->_end); }

			//? Returns a reverse iterator pointing to the last element
			reverse_iterator rbegin(){}
			
			const_reverse_iterator rbegin() const{}

			//? Returns a reverse iterator pointing to the theoretical element preceding the first element			
			reverse_iterator rend(){}
			
			const_reverse_iterator rend() const{}

			//! Capacity ************************************************** //

			//? Returns the number of elements in the vector.
			size_type size() const { return (this->_size); }

			//? Returns the maximum number of elements that the vector can hold.
			size_type max_size() const { return (4611686018427387903); }

			//? Resizes the container so that it contains n elements.
			void resize (size_type n, value_type val = value_type()) {}//************

			//? Return size of allocated storage capacity
			size_type capacity() const { return (this->_capacity); }

			//? Test whether vector is empty
			bool empty() const{
				if (this->_size == 0)
					return (true);
				else
					return (false);
			}

			//? Request a change in capacity
			void reserve (size_type n){}//**************

			//! Element access ******************************************** //

			//? Returns a reference to the element at position n
			reference operator[] (size_type n){}

			const_reference operator[] (size_type n) const{}

			reference at (size_type n){}

			const_reference at (size_type n) const{}

			//? Returns a reference to the first element
			reference front(){}

			const_reference front() const{}

			//? Returns a reference to the last element
			reference back(){}

			const_reference back() const{}

			//! Modifiers ************************************************* //

			//? Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last){}

			void assign (size_type n, const value_type& val){}

			//? Add element at the end
			void push_back (const value_type& val){}

			//? Delete last element
			void pop_back(){}

			//? Insert elements
			iterator insert (iterator position, const value_type& val){}

			void insert (iterator position, size_type n, const value_type& val){}

			template <typename InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last){}

			//? Erase elements
			iterator erase (iterator position){}

			iterator erase (iterator first, iterator last){}

			//? Swap content
			void swap (vector& x){}

			//? Clear content
			void clear(){}

			//! Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the vector
			allocator_type get_allocator() const{}


		private:
			// T*			_arr;
			Alloc		_alloc;
			size_type	_capacity;
			size_type	_size;
			iterator	_start;
			iterator	_end;

	};

	//? Relational operators
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs == rhs); }

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs != rhs); }

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs < rhs); }

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs <= rhs); }

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs > rhs); }

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs >= rhs); }

	//? Exchange contents of vectors
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){}

}

#endif