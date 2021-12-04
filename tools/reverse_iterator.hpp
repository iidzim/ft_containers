/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:09:39 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/04 19:00:35 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft{

	template <typename iterator>
	class reverse_iterator{
	
		typedef iterator                    iterator_type;
		typedef iterator::iterator_category iterator_category;
		typedef iterator::value_type        value_type;
		typedef iterator::difference_type   difference_type;
		typedef iterator::pointer           pointer;
		typedef iterator::reference         reference;

		reverse_iterator(): it(NULL) {}
		explicit reverse_iterator (iterator_type it) {this->_it = it; }
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it) {return rev_it.base(); }
		iterator_type base() const {return _it; }//?
		reference operator* () const { return *(--_it); }
		reverse_iterator operator+ (difference_type n) const {return (reverse_iterator(_it - n)); }
		reverse_iterator operator- (difference_type n) const {return (reverse_iterator(_it + n)); }
		reverse_iterator& operator++() { --(_it); return (*this); }
		reverse_iterator  operator++(int) { reverse_iterator temp = *this; ++(*this); return temp;}
		reverse_iterator& operator--() { ++(_it); return (*this); }
		reverse_iterator  operator--(int) { reverse_iterator temp = *this; --(*this); return temp; }
		reverse_iterator& operator+= (difference_type n) { this = this - n; return (*this); }
		reverse_iterator& operator-= (difference_type n) { this = this + n; return (*this); }
		pointer operator->() const { return &(operator*()); }
		reference operator[] (difference_type n) const { return it.base()[-n-1]; }


		private:
			iterator_type _it;

	};
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it) { return (rev_it - n); }

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) { return (rev_it + n); }

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs == rhs; }

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs != rhs; }

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs < rhs; }
	
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs <= rhs; }

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs > rhs; }

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return lhs >= rhs; }
}

#endif