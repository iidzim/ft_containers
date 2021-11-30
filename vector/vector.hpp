/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:57:22 by iidzim            #+#    #+#             */
/*   Updated: 2021/11/30 23:14:54 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <memory>

namespace ft{

    template <typename T, typename Alloc = std::allocator <T> >
    class vector{

        public:

            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            
            

            vector(void){}
            ~vector(void){}
            vector& operator= (const vector& v){}
            int size(){}
            int max_size(){}
            int capacity(){}
            
        
    };

}

#endif