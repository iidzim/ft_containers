/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:56:30 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/04 18:52:37 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <memory>
#include <vector>

namespace ft{

	template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct iterator {

		//* Category to which the iterator belongs to (input, output, forward, bidirectionnal, rnadom_access)
		typedef Category  iterator_category;
		//* Type of elements pointed by the iterator.
		typedef T         value_type;
		//* Type to represent the difference between two iterators.
		typedef Distance  difference_type;
		//* Type to represent a pointer to an element pointed by the iterator.
		typedef Pointer   pointer;
		//* Type to represent a reference to an element pointed by the iterator.
		typedef Reference reference;

		iterator(pointer ptr) : _ptr(ptr) {}
		iterator(const iterator& x) {*this = x; }
		iterator& operator= (const iterator& x) {return (*this); }
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
    	iterator operator- (const iterator& a) { return this->_ptr - a._ptr; };
    	iterator& operator+= (const int& n) { this = this + n; return (*this); };
    	iterator& operator-= (const int& n) { this = this - n; return (*this); };
    	const T& operator[] (const int& index) { return this[index]; };

		private:
			pointer _ptr;
	};

	template<typename iterator>
	iterator operator+ (const int n, const iterator& a) { return (n + a._ptr); }
}

#endif
