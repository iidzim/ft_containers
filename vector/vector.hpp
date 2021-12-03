/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/03 17:18:37 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory>

namespace ft{

	template <typename T, typename Alloc = std::allocator <T> >
	class vector{

		public:

			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
    		typedef typename allocator_type::const_pointer		const_pointer;

			//* ---------------------- Constructors ---------------------- //
			//? Constructs a vector, initializing its contents

			explicit vector (const allocator_type& alloc = allocator_type()){}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){}
			vector (const vector& x){}

			//* ----------------------- Destructor ----------------------- //
			//? Destroys the container object

			~vector(void){}

			//* --------------------- Assign content --------------------- //
			//? Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
			
			vector& operator= (const vector& x){}

			//! Iterators ------------------------------------------------ //

			//* ------------------------- begin -------------------------- //
			
			iterator begin(){}
			const_iterator begin() const{}



	};

}

#endif