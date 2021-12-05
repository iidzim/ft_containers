/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/05 18:44:11 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include "../tools/iterator.hpp"
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

			//? Constructs an empty container with the given allocator alloc
			explicit vector (const allocator_type& alloc = allocator_type()){

				this->_arr = alloc.allocate(0);
				this->_capacity = 1;
				this->_size = 0;
			}

			//? Constructs the container with count copies of elements with value
			explicit vector (size_t n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()){

					this->_arr = alloc.allocate(n);
					alloc.construct(this->_arr, val);
					this->_size = n;
					this->_capacity = n;
			}

			//? Constructs the container with the contents of the range [first, last)
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
				//!
			}

			//? Copy constructor. Constructs the container with the copy of the contents of other
			vector (const vector& x){
				this = x;
			}

			//* ----------------------- Destructor ----------------------- //
			//? Destroys the container object

			// ~vector(void){
			// 	Alloc.deallocate(this->_arr, this->_capacity);
			// 	for (int i = 0; i < this->_size; i++)
			// 		Alloc.destroy(this->_arr + i);
			// }

			//* --------------------- Assign content --------------------- //
			//? Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
			
			vector& operator= (const vector& x){
				this->_capacity = x._capacity;
				this->_size = x._size;
				for (int i=0; i < this->_size; i++)
					this->_arr[i] = x._arr[i];
				return (*this);
			}

			//* ------------------------- begin -------------------------- //
			//? Returns an iterator pointing to the first element in the vector

			// iterator begin(){
			// 	iterator it;
				
			// }
			
			// const_iterator begin() const{
				
			// }

			//* -------------------------- end --------------------------- //
			//? Returns an iterator referring to the past-the-end element in the vector container

			// iterator end(){
				
			// }

			// const_iterator end() const{
				
			// }

		
		private:
			//? pointer -> begin
			//? pointer -> end
			size_t	_capacity;
			size_t	_size;
			T*		_arr;
			
	};

}

#endif