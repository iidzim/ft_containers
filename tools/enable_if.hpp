/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:43 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/12 21:49:55 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF
#include <type_traits>

namespace ft{

	template <bool Cond, typename T = void>
	struct enable_if{};

	template<typename T>
	struct enable_if<true, T> { typedef T type; };



	template <class T> 
	struct is_integral{ static const bool value = false; };

	template <>
	struct is_integral<bool>{ static const bool value = true; };

	template <>
	struct is_integral<char>{ static const bool value = true; };

	template <>
	struct is_integral<char16_t>{ static const bool value = true; };

	template <>
	struct is_integral<char32_t>{ static const bool value = true; };

	template <>
	struct is_integral<wchar_t>{ static const bool value = true; };

	template <>
	struct is_integral<short>{ static const bool value = true; };

	template <>
	struct is_integral<int>{ static const bool value = true; };

	template <>
	struct is_integral<long>{ static const bool value = true; };

	template <>
	struct is_integral<long long>{ static const bool value = true; };

	template <>
	struct is_integral<unsigned int>{ static const bool value = true; };

	template <>
	struct is_integral<unsigned long>{ static const bool value = true; };

	
}

//? if T is the type bool, char, char8_t (since C++20), char16_t, char32_t, wchar_t,
//? short, int, long, long long, or any implementation-defined extended integer types,
//? including any signed, unsigned, and cv-qualified variants. Otherwise, value is equal to false.

#endif