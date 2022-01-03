/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2022/01/03 16:00:17 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
# define vector_HPP

#include <memory>
#include <stdexcept>
#include <algorithm>
#include "../tools/reverse_iterator.hpp"
#include "../tools/iterator.hpp"
#include "../tools/tools.hpp"

namespace ft{

	template <typename T, typename Alloc = std::allocator <T> >
	class vector{

		public:

			//* STL container and iterator types are easier to work with if you use some typedefs
			typedef	T																value_type;
			typedef	Alloc															allocator_type;
			typedef size_t															size_type;
			typedef typename Alloc::reference										reference;
			typedef typename Alloc::const_reference									const_reference;
			typedef typename Alloc::pointer											pointer;
			typedef typename Alloc::const_pointer									const_pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>		iterator;
			typedef typename ft::iterator<std::random_access_iterator_tag, const T>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			//? Constructs an empty container with the given allocator alloc
			explicit vector (const allocator_type& alloc = allocator_type()):
				_start(NULL), _end(NULL), _size(0), _capacity(0), _alloc(alloc){}

			// 	this->_start = this->_end = NULL;
			// 	this->_size = this->_capacity = 0;
			// 	this->_alloc = alloc;
			// }

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
				*this = x;
			}

			//? Destroys the container object
			~vector(void){
				for (pointer it = _start; it < _end; it++)
					_alloc.destroy(it);
				_end = _start;
				_size = 0;
				_capacity = 0;
			}

			//? Assigns new contents, replacing its current contents, and modifying its size accordingly.
			vector& operator= (const vector& x){

				// if (_start != _end){
					for (pointer it = _start; it < _end; it++)
						_alloc.destroy(it);
					// _alloc.deallocate(_start, _capacity);
				// }
				_alloc = x._alloc;
				_capacity = x._size;
				_size = x._size;
				_start = _alloc.allocate(_size);
				_end = _start + _size;
				for (int i = 0; i < _size; i++)
					_alloc.construct((_start + i), *(x._start + i));
				return (*this);
			}

			//* iterators ************************************************ //

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

			//* Capacity ************************************************** //

			//? Returns the number of elements in the vector.
			size_type size() const { return (_size); }

			//? Returns the maximum number of elements that the vector can hold.
			size_type max_size() const { return (_alloc.max_size()); }

			//? Resizes the container so that it contains n elements.
			void resize (size_type nn, value_type val = value_type()){

				int n = static_cast<int>(nn);
				if (n > _capacity){
					if (n > _capacity * 2)
						reserve(n);
					else
						reserve(_capacity * 2);
				}
				if (n > _size){
					for (int i = _size; i < n; i++)
						_alloc.construct(_start + i, val);
					_size = n;
					_end = _start + n;
				}
				else if (n < _size){
					for (pointer it = _start + n; it < _end; it++)
						_alloc.destroy(it);
					_end = _start + n;
					_size = n;
				}
			}

			//? Return size of allocated storage capacity
			size_type capacity() const { return (_capacity); }

			//? Test whether vector is empty
			bool empty() const { return (_start == _end); }

			//? Request a change in capacity
			void reserve (size_type n){

				if (n > max_size())
					throw std::length_error("vector");
				if ((int)n < _capacity)
					return ;
				else{
				 	pointer tmp_start, tmp_end;
					tmp_start = _alloc.allocate(n);
					tmp_end = tmp_start + _size;
					for (int i = 0; i < _size; i++)
						_alloc.construct((tmp_start + i), *(_start + i));
					for (pointer it = _start; it < _end; it++)
						_alloc.destroy(it);
					_alloc.deallocate(_start, _capacity);//? _size
					_start = tmp_start;
					_end = tmp_end;
					_capacity = n;
				}
			}

			//* Element access ******************************************** //

			//? Returns a reference to the element at position n
			reference operator[] (size_type n){ return *(_start + n); }
			const_reference operator[] (size_type n) const{ return *(_start + n); }

			reference at (size_type n){
				if ((int)n >= _size)
					throw std::out_of_range("vector");
				return (*(_start + n));
			}
			const_reference at (size_type n) const{
				if ((int)n >= _size)
					throw std::out_of_range("vector");
				return (*(_start + n));
			}

			//? Returns a reference to the first element
			reference front(){ return *(_start); }
			const_reference front() const{ return *(_start); }

			//? Returns a reference to the last element
			reference back(){ return *(_end - 1); }
			const_reference back() const{ return *(_end - 1); }


			//* Modifiers ************************************************* //

			//? Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){

				int len = last - first;
				pointer pfirst = &(*first);
				for (pointer it = _start; it < _end; it++)
					_alloc.destroy(it);
				if (len > _capacity){
					_alloc.deallocate(_start, _capacity);
					_start = _alloc.allocate(len);
					_end = _start + len;
					_size = _capacity = len;
					for (int i = 0; i < len; i++)
						_alloc.construct(_start + i, *(pfirst + i));
				}
				else{
					_size = len;
					_end = _start + _size;
					for (int i = 0; i < _size; i++)
						_alloc.construct(_start + i, *(pfirst + i));
				}
			}

			void assign (size_type nn, const value_type& val){

				int n = static_cast<int>(nn);
				// if (_size != 0){
					for (pointer it = _start; it < _end; it++)
						_alloc.destroy(it);
				// }
				if (n > _capacity){
					_alloc.deallocate(_start, _capacity);
					_start = _alloc.allocate(n);
					_end = _start + n;
					_size = _capacity = n;
					for (int i = 0; i < n; i++)
						_alloc.construct((_start + i), val);
				}
				else{
					_size = n;
					_end = _start + _size;
					for (pointer it = _start; it < _end; it++)
						_alloc.construct(it ,val);
				}
			}

			//? Add element at the end
			void push_back (const value_type& val){

				if (_capacity == _size && _size == 0)
					reserve(_size + 1);
				else if (_capacity == _size)
					reserve(_size * 2);
				_alloc.construct(_start + _size, val);
				_end += 1;
				_size += 1;
			}

			//? Delete last element
			void pop_back(){

				pointer it = _end;
				_end -= 1;
				_alloc.destroy(it);
				_size -= 1;
			}

			//? Insert elements
			iterator insert (iterator position, const value_type& val){

				int i;
				int pos = _end - &(*position);
				if (_size == _capacity && _size == 0)
					reserve(1);
				else if (_size == _capacity)
					reserve(_size * 2);
				for (i = 0; i < pos; i++)
					_alloc.construct(_end - i, *(_end - i - 1));
				_alloc.construct(_end - i, val);
				_size += 1;
				_end += 1;
				return (iterator(_start + pos));
			}

			void insert (iterator position, size_type nn, const value_type& val){

				int i;
				int n = static_cast<int>(nn);
				int pos = _end - &(*position);
				if (_size == _capacity && _size == 0)
					reserve(n);
				else if (_size + n >= _capacity){
					if (_size + n > _capacity && n < _size)
						reserve(_capacity * 2);
					else
						reserve(_size + n);
				}
				if (_size == 0){
					for (i = 0; i < n; i++)
						_alloc.construct(_start + i, val);
				}
				else{
					pointer h;
					for (i = 0; i <= pos; i++)
						_alloc.construct(_end + n - i, *(_end - i));
					h = _end + n - i;
					for (i = 0; i < n; i++)
						_alloc.construct(h - i, val);
				}
				_end += n;
				_size += n;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){

				int i;
				int pos = _end - &(*position);
				int n = last - first;
				if (_size == _capacity && _size == 0)
					reserve(n);
				else if (_size + (int)n >= _capacity){
					if (_size + (int)n > _capacity && (int)n < _size)
						reserve(_capacity * 2);
					else
						reserve(_size + n);
				}
				if (_size == 0){
					for (i = 0; i < n; i++)
						_alloc.construct(_start + i, *(first + i));
				}
				else{
					pointer h;
					for (i = 0; i <= pos; i++)
						_alloc.construct(_end + n - i, *(_end - i));
					h = _end + n - i;
					for (i = 0; i < n; i++)
						_alloc.construct(h - i, *(last - i - 1));
				}
				// else{
				// 	ft::vector<T> tmp(first, last);
				// 	pointer h;
				// 	for (i = 0; i <= pos; i++)
				// 		_alloc.construct(_end + n - i, *(_end - i));
				// 	h = tmp.end() + n - i;
				// 	for (i = 0; i < n; i++)
				// 		_alloc.construct(h - i, *(last - i - 1));
				// }
				_end += n;
				_size += n;
			}

			//? Erase elements
			// iterator erase (iterator position){//!TLE
					// check if position = end is true then no need to construct
			// 	pointer pos_ = &(*position);
			// 	int pos = position - _start;
			// 	_size -= 1;
			// 	for (int i = pos; i < _size; i++)
			// 		_alloc.construct((_start + i), *(_start + i + 1));
			// 	_end -= 1;
			// 	return (iterator(pos_));
			// }
			iterator erase (iterator position){

				pointer pos_ = &(*position);
				if (position + 1 != _end)
					std::copy(pos_ + 1, _end, pos_);
				_end -= 1;
				_size -= 1;
				_alloc.destroy(_end);
				return (iterator(pos_));
			}

			iterator erase (iterator first, iterator last){

				pointer pfirst= &(*first);
				pointer plast= &(*last);
				int len = plast - pfirst;
				for (int i = 0; i < _end - plast; i++)
					_alloc.construct(pfirst + i, *(plast + i));
				for (int i = _size - len; i < _size; i++)
					_alloc.destroy(_start + i - 1);
				_size -= len;
				_end -= len;
				return (iterator(pfirst));
			}

			//? Swap content
			void swap (vector& x){

				std::swap(x._start, _start);
				std::swap(x._end, _end);
				std::swap(x._size, _size);
				std::swap(x._capacity, _capacity);
				std::swap(x._alloc, _alloc);

				// pointer tmp_start, tmp_end;
				// int tmp_capacity, tmp_size;
				// Alloc tmp_alloc;
				// tmp_start = x._start;
				// tmp_end = x._end;
				// tmp_size = x._size;
				// tmp_capacity = x._capacity;
				// tmp_alloc = x._alloc;
				// x._start = this->_start;
				// x._end = this->_end;
				// x._size = this->_size;
				// x._capacity = this->_capacity;
				// x._alloc = this->_alloc;
				// this->_start = tmp_start;
				// this->_end = tmp_end;
				// this->_capacity = tmp_capacity;
				// this->_size = tmp_size;
				// this->_alloc = tmp_alloc;
			}

			//? Clear content
			void clear(void){
				for (pointer it = _start; it < _end; it++)
					_alloc.destroy(it);
				_end = _start;
				_size = 0;
			}

			//* Allocator ************************************************* //

			//? Returns a copy of the allocator object associated with the vector
			allocator_type get_allocator() const{ return (this->_alloc); }

		private:
			Alloc		_alloc;
			int			_capacity;
			int			_size;
			pointer		_start;
			pointer		_end;

	};

	//? Exchange contents of vectors
	template <typename T, typename Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){ x.swap(y); }

	//? Relational operators
	template <typename T, typename Alloc>
	bool operator== (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (false);
		return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <typename T, typename Alloc>
	bool operator!= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		return (!(lhs == rhs));
	}

	template <typename T, typename Alloc>
	bool operator<  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <typename T, typename Alloc>
	bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		return (!(rhs<lhs));
	}

	template <typename T, typename Alloc>
	bool operator>  (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		return (rhs<lhs);
	}

	template <typename T, typename Alloc>
	bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
		return (!(lhs<rhs));
	}	
}

#endif