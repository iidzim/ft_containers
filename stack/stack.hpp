/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:13:20 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/21 18:13:34 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <stdexcept>
#include <algorithm>
#include "../tools/reverse_iterator.hpp"
#include "../tools/iterator.hpp"
#include "../tools/tools.hpp"
#include "../vector/vector.hpp"

namespace ft{
	
	template <typename T, typename Container = ft::vector<T> >
	class stack{

		public:

			typedef T           value_type;
			typedef Container   container_type;
			typedef size_t      size_type;

			explicit stack (const container_type& ctnr = container_type()): _c(ctnr){}
			~stack (void){}
			bool empty() const { return (_c.empty()); }
			size_type size() const { return (_c.size()); }
			value_type& top() { return (_c.back()); }
			const value_type& top() const { return (_c.back()); }
			void push (const value_type& val) { _c.push_back(val); }
			void pop() { _c.pop_back(); }

			friend bool operator== (const stack& lhs, const stack& rhs){ return (lhs._c == rhs._c); }
			friend bool operator!= (const stack& lhs, const stack& rhs){ return (lhs._c != rhs._c); }
			friend bool operator<  (const stack& lhs, const stack& rhs){ return (lhs._c < rhs._c); }
			friend bool operator<= (const stack& lhs, const stack& rhs){ return (lhs._c <= rhs._c); }
			friend bool operator>  (const stack& lhs, const stack& rhs){ return (lhs._c > rhs._c); }
			friend bool operator>= (const stack& lhs, const stack& rhs){ return (lhs._c >= rhs._c); }

		private:
			value_type _c;
	};

}

#endif