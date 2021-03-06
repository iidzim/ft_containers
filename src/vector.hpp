/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/25 12:49:43 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
#define vector_HPP

#include <memory>
#include <stdexcept>
#include <algorithm>
#include "./tools/tools.hpp"
#include "./tools/iterator.hpp"
#include "./tools/reverse_iterator.hpp"

namespace ft{

	template <typename T, typename Alloc = std::allocator <T> >
	class vector{

		public:

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
				_alloc(alloc), _capacity(0), _size(0), _start(NULL), _end(NULL){}

			//? Constructs the container with count copies of elements with value
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()):
				_alloc(alloc), _capacity(0), _size(0), _start(NULL), _end(NULL){

				if (n > this->max_size())
					throw std::length_error("vector");
				this->_size = this->_capacity = n;
				if (this->_size > 0)
				{
					this->_start = this->_alloc.allocate(n);
					this->_end = this->_start + n;
					for (int i = 0; i < this->_size; i++)
						this->_alloc.construct((this->_start + i), val);
				}
			}

			//* enable_if -> Yields type T only if bool B is true
			//? Constructs the container with the contents of the range [first, last)
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()):
				_alloc(alloc), _capacity(0), _size(0), _start(NULL), _end(NULL){

				this->_size = this->_capacity = last - first;
				this->_start = this->_alloc.allocate(this->_size);
				this->_end = this->_start + this->_size;
				for (int i = 0; i < this->_size; i++)
					this->_alloc.construct((this->_start + i), *(first + i));
			}

			//? Copy constructor
			vector (const vector& x): _capacity(0), _size(0), _start(NULL), _end(NULL){
				*this = x;
			}

			//? Destroys the container object
			~vector(void){
				for (pointer it = _start; it < _end; it++)
					_alloc.destroy(it);
				_alloc.deallocate(_start, _capacity);
				_end = _start;
				_size = _capacity = 0;
			}

			//? Assigns new contents, replacing its current contents, and modifying its size accordingly.
			vector& operator= (const vector& x){

				for (int i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, _capacity);
				_alloc = x._alloc;
				_capacity = _size = x._size;
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
				}
				else if (n < _size){
					for (pointer it = _start + n; it < _end; it++)
						_alloc.destroy(it);
				}
				_end = _start + n;
				_size = n;
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
				pointer tmp_start, tmp_end;
				tmp_start = _alloc.allocate(n);
				tmp_end = tmp_start + _size;
				for (int i = 0; i < _size; i++)
					_alloc.construct((tmp_start + i), *(_start + i));
				for (pointer it = _start; it < _end; it++)
					_alloc.destroy(it);
				_alloc.deallocate(_start, _capacity);
				_start = tmp_start;
				_end = tmp_end;
				_capacity = n;
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
				for (pointer it = _start; it < _end; it++)
					_alloc.destroy(it);
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

				if (_capacity == 0)
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
				if (_capacity == 0){
					_start = _alloc.allocate(1);
					_end = _start + 1;
					_alloc.construct(_start , val);
					_capacity = _size = 1;
					return (_start);
				}
				if (_size == _capacity)
					reserve(_capacity * 2);
				for (i = 0; i < pos; i++)
					_alloc.construct(_end - i, *(_end - i - 1));
				_alloc.construct(_end - i, val);
				_size += 1;
				_end += 1;
				return (_start + pos);
			}

			void insert (iterator position, size_type nn, const value_type& val){

				int n = static_cast<int>(nn);
				int pos = _end - &(*position);
				if (_capacity == 0){
					if (nn > max_size())
						throw std::length_error("vector");
					_start = _alloc.allocate(n);
					_end = _start + n;
					for (int i = 0; i < n; i++)
						_alloc.construct(_start + i, val);
					_capacity = _size = n;
				}
				else{
					if (_capacity < _size + n && _size > n)
						reserve(_capacity * 2);
					else if (_capacity <= _size + n)
						reserve(_size + n);
					for (int i = 0; i < n; i++)
						_alloc.construct(_end + i, *(_end - pos + i));
					for (int i = 0; i < n; i++)
						_alloc.construct(_end - pos + i, val);
					_end += n;
					_size += n;
				}
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){

				int i;
				int pos = _end - &(*position);
				int n = last - first;
				if (_capacity == 0){
					_start = _alloc.allocate(n);
					_end = _start + n;
					for (int i = 0; i < n; i++)
						_alloc.construct(_start + i, *(first + i));
					_size = _capacity = n;
				}
				else{
					if (_size + n > _capacity && n < _size)
						reserve(_capacity * 2);
					if (_size + n >= _capacity)
						reserve(_size + n);
					pointer h;
					for (i = 0; i <= pos; i++)
						_alloc.construct(_end + n - i - 1, *(_end - i - 1));
					h = _end + n - i;
					for (i = 0; i < n; i++)
						_alloc.construct(h - i, *(last - i - 1));
					_end += n;
					_size += n;
				}
			}

			//? Erase elements
			iterator erase (iterator position){

				pointer pos_ = &(*position);
				if (position + 1 != _end){
					_alloc.destroy(pos_);
					for (int i = 0; i < _end - pos_ - 1; i++)
						_alloc.construct(pos_ + i, *(pos_ + 1 + i));
				}
				pop_back();
				return (iterator(pos_));
			}

			iterator erase (iterator first, iterator last){

				pointer pfirst= &(*first);
				pointer plast= &(*last);
				int len = plast - pfirst;
				for (pointer it = pfirst; it < plast; it++)
					_alloc.destroy(it);
				for (int i = 0; i < _end - plast; i++)
					_alloc.construct(pfirst + i, *(plast + i));
				for (int i = 0; i < _end - plast; i++)
					_alloc.destroy(_start + i);
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
			allocator_type get_allocator() const{ allocator_type al(_alloc); return al; }

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
