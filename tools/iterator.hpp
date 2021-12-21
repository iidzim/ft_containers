/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:56:30 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/21 11:12:21 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include "./iterator_traits.hpp"
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
		//* Type to represent a reference to an element pointed by the iterator.
		typedef Reference reference;

		iterator(void) : _ptr(NULL) {}
		iterator(pointer ptr) : _ptr(ptr) {}
		iterator(const iterator& x) { *this = x; }
		iterator& operator= (const iterator& x) {this->_ptr = x._ptr; return (*this); }
		~iterator(void) {}
		reference operator* () const { return (*_ptr); }
		pointer operator-> () { return (_ptr); }

		iterator& operator++() { ++(_ptr); return (*this); }
		iterator operator++(int) { iterator tmp = *this; ++(*this); return (tmp); }
		iterator& operator--() { --(_ptr); return (*this); }
		iterator operator--(int) { iterator tmp = *this; --(*this); return (tmp); }
		iterator operator+ (const int n) { return (_ptr + n); };
		iterator operator- (const int n) { return (_ptr - n); };
		difference_type operator- (const iterator& a) { return (this->_ptr - a._ptr); };
		iterator& operator+= (const int& n) { _ptr += n; return (*this); };
		iterator& operator-= (const int& n) { _ptr -= n; return (*this); };
		T& operator[] (difference_type n) { return *(_ptr+n); };

		operator iterator<iterator_category, const T>(){
			return iterator<iterator_category, const T>(_ptr);
		}

		friend iterator operator+ (int n, iterator a) { return iterator(a._ptr + n); }
		friend bool operator== (const iterator& lhs, const iterator& rhs) { return lhs._ptr == rhs._ptr; };
		friend bool operator!= (const iterator& lhs, const iterator& rhs) { return lhs._ptr != rhs._ptr; };
		friend bool operator< (const iterator& lhs, const iterator& rhs) { return lhs._ptr < rhs._ptr; };
		friend bool operator> (const iterator& lhs, const iterator& rhs) { return lhs._ptr > rhs._ptr; };
		friend bool operator<= (const iterator& lhs, const iterator& rhs) { return lhs._ptr <= rhs._ptr; };
		friend bool operator>= (const iterator& lhs, const iterator& rhs) { return lhs._ptr >= rhs._ptr; };

		private:
			pointer _ptr;
	};
}

#endif
