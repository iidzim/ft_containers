/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:09:39 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/14 00:43:56 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include <iostream>
#include "./iterator_traits.hpp"
#include "./iterator.hpp"

namespace ft{

	template <typename iterator>
	class reverse_iterator{

		public:
			typedef iterator												iterator_type;
			typedef typename iterator_traits<iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<iterator>::value_type			value_type;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			typedef typename iterator_traits<iterator>::pointer				pointer;
			typedef typename iterator_traits<iterator>::reference			reference;

			//? Constructs a reverse iterator that points to no object.
			reverse_iterator(): _it(NULL) {}

			//? Constructs a reverse iterator from some original iterator it
			explicit reverse_iterator (iterator_type it) { this->_it = it; }

			//? Constructs a reverse iterator from some other reverse iterator
			template <typename Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) { this->_it = rev_it.base(); }

			//? Returns a copy of the base iterator.
			iterator_type base() const {return (_it + 1); }

			//? Operator overloading
			reference operator* () const { iterator_type tmp = _it; return *(--tmp); }
			reverse_iterator operator+ (difference_type n) const {return (reverse_iterator(_it - n)); }
			reverse_iterator operator- (difference_type n) const {return (reverse_iterator(_it + n)); }
			reverse_iterator& operator++() { --(_it); return (*this); }
			reverse_iterator  operator++(int) { reverse_iterator temp = *this; ++(*this); return (temp);}
			reverse_iterator& operator--() { ++(_it); return (*this); }
			reverse_iterator  operator--(int) { reverse_iterator temp = *this; --(*this); return (temp); }
			reverse_iterator& operator+= (difference_type n) { return *(this - n); }
			reverse_iterator& operator-= (difference_type n) { return *(this + n); }
			pointer operator->() const { return &(operator*()); }
			reference operator[] (difference_type n) const { return (_it.base()[-n-1]); }

		private:
			iterator_type _it;

	};

	template <typename Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it) { return (rev_it - n); }

	template <typename Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (lhs.base() - rhs.base()); }

	template <typename Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); }

	template <typename Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() != rhs.base()); }

	template <typename Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs.base() < lhs.base()); }

	template <typename Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs.base() < rhs.base()); }

	template <typename Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs.base() > lhs.base()); }

	template <typename Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return !(lhs.base() > rhs.base()); }
}

#endif