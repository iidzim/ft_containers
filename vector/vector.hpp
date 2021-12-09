/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/09 22:32:28 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include "../tools/iterator.hpp"
#include "../tools/reverse_iterator.hpp"
#include <memory>
#include <stdexcept>
#define MAX_SIZE 4611686018427387903

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
			// typedef typename ft::iterator<std::__is_random_access_iterator, T, ptrdiff_t, T*, T&> iterator;
			typedef typename ft::iterator<T>			const_iterator;
			typedef typename ft::reverse_iterator<T>	reverse_iterator;
			typedef typename ft::reverse_iterator<T>	const_reverse_iterator;

			//? Constructs an empty container with the given allocator alloc
			explicit vector (const allocator_type& alloc = allocator_type()){

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
					this->_start = alloc.allocate(n);
					this->_end = this->_start + n;
					for (iterator it = this->_start; it < this->_end; it++)
						this->_alloc.construct(it, val);
				}
				else
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
					this->_alloc.construct(it, *(first + it));
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
			reverse_iterator rbegin(){ return (reverse_iterator(this->_end)); }
			const_reverse_iterator rbegin() const{ return (reverse_iterator(this->_end)); }

			//? Returns a reverse iterator pointing to the theoretical element preceding the first element
			reverse_iterator rend(){ return (reverse_iterator(this->_begin)); }
			const_reverse_iterator rend() const{ return (reverse_iterator(this->_begin)); }

			//! Capacity ************************************************** //

			//? Returns the number of elements in the vector.
			size_type size() const { return (this->_size); }

			//? Returns the maximum number of elements that the vector can hold.
			size_type max_size() const { return (MAX_SIZE); }
			// size_type max_size() const { return (this->get_allocator().max_size()); }//*

			//? Resizes the container so that it contains n elements.
			void resize (size_type n, value_type val = value_type()){

				if (n < this->_size) {
					for (iterator it = this->_start + n; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_end = this->_start + n;
					this->_size = n;
				}
				else if (n > this->_size && n < this->_capacity) {
					//? insert at the end as many elements as needed to reach a size of n
				}
				else {
					iterator tmp_start, tmp_end;
					tmp_start = this->_alloc.allocate(n);
					tmp_end = tmp_start + n;
					for (int i = 0; i < n; i++)
					{
						if (i < this->_size)
							this->_alloc.construct(tmp_start + i, *(this->_start + i));
						else
							this->_alloc.construct(tmp_start + i, val);
					}
					for (iterator it = this->_start; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_start = tmp_start;
					this->_end = tmp_end;
					this->_capacity = n;
					this->_size = n;
				}
			}

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
			void reserve (size_type n){

				if (n > this->_capacity){
					iterator tmp_start, tmp_end;
					tmp_start = this->_alloc.allocate(n);
					tmp_end = tmp_start + this->_size;
					for (int i = 0; i < this->_size; i++)
						*tmp_start = *(this->_start + i);
					for (iterator it = this->_start; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_start = tmp_start;
					this->_end = tmp_end;
					this->_capacity = n;
				}
			}

			//! Element access ******************************************** //

			//? Returns a reference to the element at position n
			reference operator[] (size_type n){ return (*(this->_start + n)); }
			const_reference operator[] (size_type n) const{ return (*(this->_start + n)); }

			reference at (size_type n){
				if (n < 0 || n >= this->_size)
					throw std::out_of_range("vector");
				return (*(this->_start + n));
			}
			const_reference at (size_type n) const{
				if (n < 0 || n >= this->_size)
					throw std::out_of_range("vector");
				return (*(this->_start + n));
			}

			//? Returns a reference to the first element
			reference front(){ return (*(this->_start)); }
			const_reference front() const{ return (*(this->_start)); }

			//? Returns a reference to the last element
			reference back(){ return (*(this->_end)); }
			const_reference back() const{ return (*(this->_end)); }

			//! Modifiers ************************************************* //

			//? Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last){

				size_type len = last - first;
				if (len > this->_size){

					for (iterator it = this->_start; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_start = this->_alloc.allocate(len);
					this->_end = this->_start + len;
					for (int i = 0; i < len; i++)
						this->_alloc.construct((this->_start + i), *(first + i));
					this->_size = this->_capacity = len;
				}
				else{
					for (int i = len; i < this->_size; i++)
						this->_alloc.destroy(this->_start + i);
					this->_size = len;
					for (int i = 0; i < this->_size; i++)
						*(this->_start + i) = *(first + i);
				}
			}

			void assign (size_type n, const value_type& val){

				if (n > this->_size)
				{
					for (iterator it = this->_start; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_start = this->_alloc.allocate(n);
					this->_end = this->_start + n;
					this->_size = this->_capacity = n;
					for (int i = 0; i < n; i++)
						this->_alloc.construct((this->_start + i), val);
				}
				else{
					for (int i = n; i < this->_size; i++)
						this->_alloc.destroy(this->_start + i);
					this->_size = n;
					for (iterator it = this->_start; it < this->_end; it++)
						*it = val;
				}
			}

			//? Add element at the end
			void push_back (const value_type& val){

				// if (this->_size < this->_capacity){
				// 	this->_size += 1;
					
				// }
				// else{
				// 	this->_capacity *= 2;
				// 	this->_size += 1;
				// }
			}

			//? Delete last element
			void pop_back(){

				this->_size -= 1;
				this->_end -= 1;
				iterator it = this->_end;
				this->_end -= 1;
				this->_alloc.destroy(it);
			}

			//? Insert elements
			iterator insert (iterator position, const value_type& val){}

			void insert (iterator position, size_type n, const value_type& val){}

			template <typename InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last){}

			//? Erase elements
			iterator erase (iterator position){

				if (position < this->_size){
					this->_size -= 1;
					for (int i = position; i < this->_size - 1; i++)
						this->_alloc.construct((this->_start + i), *(this->_start + i + 1));
					iterator it = this->_end;
					this->_end -= 1;
					this->_alloc.destroy(it);
					return (this->_start + position);
				}
				return (NULL);
			}

			iterator erase (iterator first, iterator last){

				size_type position = last - first;
				if (position < this->_size)
				{
					size_type len = last - first;
					for (iterator it = first; it + len < this->_end; it++)
						this->_alloc.construct(it, *(it + len));
					for (iterator it = last; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_end = last + 1;
					this->_size -= len;
					return (this->_start + first);
				}
				return (NULL);
			}

			//? Swap content
			void swap (vector& x){

				// iterator a_start ,a_end, b_start, b_end;
				// size_type a_size, a_capacity, b_size, b_capacity;
				// Alloc a_alloc, b_alloc;
				// if (x._size > this->_size){
				// 	a_start = this->_start;
				// 	a_end = this->_end;
				// 	a_size = this->_size;
				// 	a_capacity = this->_capacity;
				// 	a_alloc = this->_alloc;
					
				// 	b_start = x._start;
				// 	b_end = x._end;
				// 	b_size = x._size;
				// 	b_capacity = x._capacity;
				// 	b_alloc = x._alloc;
				// }
				// else{
				// 	b_start = this->_start;
				// 	b_end = this->_end;
				// 	b_size = this->_size;
				// 	b_capacity = this->_capacity;
				// 	b_alloc = this->_alloc;
					
				// 	a_start = x._start;
				// 	a_end = x._end;
				// 	a_size = x._size;
				// 	a_capacity = x._capacity;
				// 	a_alloc = x._alloc;
				// }

				if (x._size > this->_size){
				{
					iterator tmp_start, tmp_end;
					size_type tmp_size = this->_size, tmp_capacity = this->_capacity;
					Alloc tmp_alloc = this->_alloc;
					tmp_start = this->_alloc.allocate(tmp_size);
					tmp_end = tmp_start + tmp_size;
					for (iterator it = this->_start; it < this->_end; it++)
						this->_alloc.allocate((tmp_start + it), *(this->_start + it));
					for (iterator it = this->_start; it < this->_end; it++)
						this->_alloc.destroy(it);

					this->_alloc = x._alloc;
					this->_capacity = x._capacity;
					this->_size = x._size;
					this->_start = this->_alloc.allocate(this->_size);
					this->_end = this->_start + this->_size;
					for (int i = 0; i < this->_size; i++)
						this->_alloc.construct((this->_start + i) , *(x._start + i));

					for (int i = tmp_size; i < this->_size; i++)
						this->_alloc.destroy(x._start + i);
					for (int i = 0; i < tmp_size; i++)
						this->_alloc.construct((x._start + i), *(tmp_start + i));
					x._size = tmp_size;
					x._capacity = tmp_capacity;
					x._alloc = tmp_alloc;
					x._end = x._start + x._size;

					for (iterator it = tmp_start; it < tmp_end; it++)
						this->_alloc.destroy(tmp_start + it);
					for (iterator it = tmp_start; it < tmp_end; it++)
						this->_alloc.deallocate((tmp_start + it), 1);
				}
				else{
					//? 
				}
			}

			//? Clear content
			void clear(void){
				for (iterator it = this->_start; it < this->_end; it++)
					this->_alloc.destroy(it);
				for (iterator it = this->_start; it < this->_end; it++)
					this->_alloc.deallocate(it, 1);
				this->_size = 0;
			}

			//! Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the vector
			allocator_type get_allocator() const{ return (this->_alloc); }

		private:
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