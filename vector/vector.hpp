/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/16 18:42:40 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <stdexcept>
#include "../tools/reverse_iterator.hpp"
#include "../tools/iterator.hpp"
#include "../tools/tools.hpp"

namespace ft{

	template <typename T, typename Alloc = std::allocator <T> >
	class vector{

		public:

			//* STL container and iterator types are easier to work with if you use some typedefs
			typedef	T																		value_type;
			typedef	Alloc																	allocator_type;
			typedef size_t																	size_type;
			typedef typename Alloc::reference												reference;
			typedef typename Alloc::const_reference											const_reference;
			typedef typename Alloc::pointer													pointer;
			typedef typename Alloc::const_pointer											const_pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T, ptrdiff_t, T*, T&>	iterator;
			typedef typename ft::iterator<random_access_iterator_tag, T, ptrdiff_t, T*, T&>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>									reverse_iterator;
			typedef typename ft::reverse_iterator<iterator>									const_reverse_iterator;

			//? Constructs an empty container with the given allocator alloc
			explicit vector (const allocator_type& alloc = allocator_type()){

				this->_start = this->_end = 0;
				this->_size = this->_capacity = 0;
				this->_alloc = alloc;
			}

			//? Constructs the container with count copies of elements with value
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()){

				this->_alloc = alloc;
				this->_size = this->_capacity = n;
				if (this->_size > 0)
				{
					this->_start = this->_alloc.allocate(n);
					this->_end = this->_start + n;
					for (int i = 0; i < this->_size; i++)
						this->_alloc.construct((this->_start + i), val);
				}
				else
					this->_start = this->_end = 0;
			}

			//* enable_if -> Yields type T only if bool B is true
			//? Constructs the container with the contents of the range [first, last)
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){

				//* The allocator parameter is copied into a private member of the container
				//* This private copy can then be used for all subsequent storage management
				this->_alloc = alloc;
				this->_size = this->_capacity = last - first;
				//* An initial buffer is allocated using the allocator's allocate function
				this->_start = this->_alloc.allocate(this->_size);
				this->_end = this->_start + this->_size;
				for (int i = 0; i < this->_size; i++)
					this->_alloc.construct((this->_start + i), *(first + i));
			}

			//? Copy constructor
			vector (const vector& x){
				*this = x; //! expression is not assignable
			}

			//? Destroys the container object
			~vector(void){
				for (pointer it = this->_start; it < this->_end; it++)
					this->_alloc.destroy(it);
				//! attempting free on address which was not malloc()-ed
				// for (pointer it = this->_start; it < this->_start + this->_capacity; it++)
					// this->_alloc.deallocate(it, 1);
				this->_size = 0;
				this->_capacity = 0;
			}

			//? Assigns new contents, replacing its current contents, and modifying its size accordingly.
			vector& operator= (const vector& x){ //! segfault

				// if (*this == x)
					// return(*this);
				// for (int i = 0; i < this->_size; i++) //! capacity
				// 	_alloc.destroy(this->_start + i);
				// for (int i = 0; i < this->_capacity; i++) //!! range constructor
				// 	this->_alloc.deallocate(this->_start + i, 1);
				this->_alloc = x._alloc;
				this->_capacity = x._capacity;
				this->_size = x._size;
				this->_start = this->_alloc.allocate(this->_size);
				this->_end = this->_start + this->_size;
				for (int i = 0; i < this->_size; i++)
					this->_alloc.construct((this->_start + i), *(x._start + i));
				return (*this);
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
			reverse_iterator rend(){ return (reverse_iterator(this->_start)); }
			const_reverse_iterator rend() const{ return (reverse_iterator(this->_start)); }

			//! Capacity ************************************************** //

			//? Returns the number of elements in the vector.
			size_type size() const { return (this->_size); }

			//? Returns the maximum number of elements that the vector can hold.
			size_type max_size() const { return (this->_alloc.max_size()); }

			//? Resizes the container so that it contains n elements.
			void resize (size_type n, value_type val = value_type()){

				if (n < this->_size){
					for (pointer it = this->_start + n; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_end = this->_start + n;
					this->_size = n;
				}
				else{
					pointer tmp_start, tmp_end;
					if (n > this->_size && n < this->_capacity){
						tmp_start = this->_alloc.allocate(this->_capacity);
						tmp_end = tmp_start + this->_size + n;
					}
					else{
						tmp_start = this->_alloc.allocate(n);
						tmp_end = tmp_start + n;
						this->_capacity = n;
					}
					for (int i = 0; i < this->_size; i++)
						this->_alloc.construct(tmp_start + i, *(this->_start + i));
					for (int i = this->_size; i < n; i++)
						this->_alloc.construct(tmp_start + i, val);
					for (pointer it = this->_start; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_start = tmp_start;
					this->_end = tmp_end;
					this->_size = n;
				}
			}

			//? Return size of allocated storage capacity
			size_type capacity() const { return (this->_capacity); }

			//? Test whether vector is empty
			bool empty() const { return (this->_start == this->_end); }

			//? Request a change in capacity
			void reserve (size_type n){

				if (n > this->max_size() || n < 0)
					throw std::length_error("vector");
				if (n < this->_capacity)
					return ;
				else{
					pointer tmp_start, tmp_end;
					tmp_start = _alloc.allocate(n);
					tmp_end = tmp_start + this->_size;
					for (int i = 0; i < this->_size; i++)
						_alloc.construct((tmp_start + i), *(this->_start + i));
					for (pointer it = this->_start; it < this->_end; it++)
						_alloc.destroy(it);
					// for (pointer it = this->_start; it < this->_start + this->_capacity; it++)
					// 	_alloc.deallocate(it, 1); //! attempting free on address which was not malloc()-ed
					this->_start = tmp_start;
					this->_end = tmp_end;
					this->_capacity = n;
				}
			}

			// //! Element access ******************************************** //

			//? Returns a reference to the element at position n
			reference operator[] (size_type n){ return *(this->_start + n); }
			const_reference operator[] (size_type n) const{ return *(this->_start + n); }

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
			reference front(){ return *(this->_start); }
			const_reference front() const{ return *(this->_start); }

			//? Returns a reference to the last element
			reference back(){ return *(this->_end - 1); }
			const_reference back() const{ return *(this->_end - 1); }


			// //! Modifiers ************************************************* //

			// //? Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,//!!!!!!!!!!!!!!!!!!!!!!!!! doesn't compile
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){

				size_type len = last - first;
				if (len > this->_size){
					for (int i = 0; i < this->_size; i++)
						_alloc.destroy(this->_start + i);
					this->_start = this->_alloc.allocate(len);
					this->_end = this->_start + len;
					for (int i = 0; i < len; i++)
						_alloc.construct(this->_start + i, *(first + i));
					this->_size = this->_capacity = len;
				}
				else{
					for (int i = len; i < this->_size; i++)
						this->_alloc.destroy(this->_start + i);
					this->_size = len;
					for (int i = 0; i < this->_size; i++)
						_alloc.construct(this->_start + i, *(first + i));
				}
			}

			void assign (size_type n, const value_type& val){

				if (n > this->_size)
				{
					for (int i = 0; i < this->_size; i++)
						_alloc.destroy(this->_start + i);
					this->_start = this->_alloc.allocate(n);
					this->_end = this->_start + n;
					this->_size = this->_capacity = n;
					for (int i = 0; i < n; i++)
						this->_alloc.construct((this->_start + i), val);
				}
				else{
					for (int i = n; i < this->_size; i++)
						_alloc.destroy(this->_start + i);
					this->_size = n;
					for (pointer it = this->_start; it < this->_end; it++)
						this->_alloc.construct(it ,val);
				}
			}

			//? Add element at the end
			void push_back (const value_type& val){

				bool flag = 0;
				if (this->_size == this->_capacity)
					flag = 1;
				insert(iterator(--(this->_end)), val);
				if (flag == 1)
					this->_capacity *= 2;
			}

			//? Delete last element
			void pop_back(){

				this->_size -= 1;
				pointer it = this->_end;
				this->_end -= 1;
				this->_alloc.destroy(it);
			}

			//? Insert elements
			iterator insert (iterator position, const value_type& val){

				int i;
				this->_size += 1;
				pointer start, end;
				start = this->_alloc.allocate(this->_size);
				end = this->_start + this->_size;
				size_type pos = position - this->_start;
				for (i = 0; i < pos; i++)
					this->_alloc.construct((start + i), *(this->_start + i));
				this->_alloc.construct((start + i), val);
				for (i = pos; i < this->_size; i++)
					this->_alloc.construct((start + i + 1), *(this->_start + i));
				for (pointer it = this->_start; it < this->_end; it++)
					_alloc.destroy(it);
				// for (pointer it = this->_start; it < this->_start + this->_capacity; it++)
					// _alloc.deallocate(it, 1);
				this->_start = start;
				this->_end = end;
				this->_capacity = this->_size;
				return (this->_start + pos);
			}

			void insert (iterator position, size_type n, const value_type& val){

				iterator start, end;
				size_type new_size = this->_size + n;
				start = this->_alloc.allocate(new_size);
				end = start + new_size;
				for (int i = 0; i < position; i++)
					this->_alloc.construct((start + i), *(this->_start + i));
				for (int i = 0; i < n; i++)
					this->_alloc.construct((start + position + i), val);
				for (int i = position; i < this->_size; i++)
					this->_alloc.construct((start + position + n + i), *(this->_start + i));
				for (iterator it = this->_start; it < this->_end; it++)
					this->_alloc.destroy(it);
				for (iterator it = this->_start; it < this->_end; it++)
					this->_alloc.deallocate(it, 1);
				this->_start = start;
				this->_end = end;
				this->_capacity = this->_size = new_size;
			}

			template <typename InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last){

				iterator start, end;
				size_type new_size = this->_size + (last - first);
				start = this->_alloc.allocate(new_size);
				end = start + new_size;
				for (int i = 0; i < position; i++)
					this->_alloc.construct((start + i), *(this->_start + i));
				for (int i = 0; i < (last - first); i++)
					this->_alloc.constrcut((start + position + i), *(first + i));
				for (int i = position; i < this->_size; i++)
					this->_alloc.construct((start + position + (last - first) + i), *(this->_start + i));
				for (iterator it = this->_start; it < this->_end; it++)
					this->destroy(it);
				for (iterator it = this->_start; it < this->_start + this->_capacity; it++)
					this->deallocate(it, 1);
				this->_start = start;
				this->_end = end;
				this->_capacity = this->_size = new_size;
			}

			//? Erase elements
			iterator erase (iterator position){

				// if (position < this->_size){
					this->_size -= 1;
					this->_alloc.destroy(this->_start + position);
					for (pointer it = position; it < this->_end - 1; it++)
						this->_alloc.construct((this->_start + it), *(this->_start + it + 1));
					pointer ite = this->_end;
					this->_end -= 1;
					this->_alloc.destroy(ite);
					return (this->_start + position);
				// }
				return (0);
			}

			iterator erase (iterator first, iterator last){

				size_type len = last - first;
				if (this->_size > len)
				{
					for (pointer it = first; it + len < this->_end; it++){
						this->_alloc.destroy(it);
						this->_alloc.construct(it, *(it + len)); //!indirection requires pointer operand ('unsigned long' invalid)
					}
					for (pointer it = last; it < this->_end; it++)
						this->_alloc.destroy(it);
					this->_size -= len;
					this->_end = last + 1;
					for (int i = this->_size; i < this->_capacity; i++)
						this->_alloc.deallocate(this->_start + i, 1);
					this->_capacity = this->_size;
					return (this->_start + first);
				}
				return (0);
			}

			//? Swap content
			void swap (vector& x){

				vector tmp;
				tmp = x;
				x = this;
				this = tmp;
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

			//? Relational operators
			friend bool operator== (const vector& lhs, const vector& rhs){

				if (lhs._size != rhs._size)
					return (false);
				return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			friend bool operator!= (const vector& lhs, const vector& rhs){
				return (!(lhs == rhs));
			}

			friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

			friend bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				return (!ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
			}

			friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
			}

			friend bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
				return (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

		private:
			Alloc		_alloc;
			int			_capacity;
			int			_size;
			// iterator	_start;
			// iterator	_end;
			pointer		_start;
			pointer		_end;

	};

	//? Exchange contents of vectors
	template <typename T, typename Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){

		vector<T, Alloc> tmp;
		tmp = x;
		x = y;
		y = tmp;
	}

}

#endif