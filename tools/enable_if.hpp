/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:43 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/11 21:00:25 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF
#include <type_traits>

namespace ft{

    template <bool Cond, typename T = void>
    struct enable_if{}; //? or
    
    template<typename T>
    struct enable_if<true, T> { typedef T type; };



    template <class T> struct is_integral;
}

#endif

// vcb
// netnijna
// solidity - blockchain
