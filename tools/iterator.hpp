/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:56:30 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/13 18:05:18 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <memory>

namespace ft{

	template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	// template <typename T>
	struct iterator {

		//* Category to which the iterator belongs to (input, output, forward, bidirectionnal, rnadom_access)
		typedef Category  iterator_category;
		//* Type of elements pointed by the iterator.
		typedef T			value_type;
		//* Type to represent the difference between two iterators.
		typedef Distance  difference_type;
		//* Type to represent a pointer to an element pointed by the iterator.
		typedef Pointer   pointer;
		// typedef T*			pointer;
		//* Type to represent a reference to an element pointed by the iterator.
		typedef Reference reference;
		// typedef T&			reference;

		iterator(void) : _ptr(NULL) {}
		iterator(pointer ptr) : _ptr(ptr) {}
		iterator(const iterator& x) { *this = x; }
		iterator& operator= (const iterator& x) {this->_ptr = x._ptr; return (*this); }
		~iterator(void) {}
		reference operator* () const { return *_ptr; }
		pointer operator-> () { return _ptr; }

		iterator& operator++() { ++(_ptr); return (*this); }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return (tmp); }
		iterator& operator--() { --(_ptr); return (*this); }
		iterator operator--(int) { iterator tmp = *this; --(*this); return (tmp); }

		bool operator== (const iterator& a) { return this->_ptr == a._ptr; };
		bool operator!= (const iterator& a) { return this->_ptr != a._ptr; };
		bool operator< (const iterator& a) { return this->_ptr < a._ptr; };
		bool operator> (const iterator& a) { return this->_ptr > a._ptr; };
		bool operator<= (const iterator& a) { return this->_ptr <= a._ptr; };
		bool operator>= (const iterator& a) { return this->_ptr >= a._ptr; };

		iterator operator+ (const int n) { return _ptr + n; };
		iterator operator- (const int n) { return _ptr - n; };
		difference_type operator- (const iterator& a) { return this->_ptr - a._ptr; };
		iterator& operator+= (const int& n) { return (*(this + n)); };
		iterator& operator-= (const int& n) { return (*(this - n)); };
		T& operator[] (difference_type n) { return *(_ptr+n); };
		pointer get_ptr(void) const { return (this->_ptr); }

		private:
			pointer _ptr;
	};

	template<typename iterator>
	iterator operator+ (const int n, const iterator& a) { return (n + a.get_ptr()); }
}

#endif
