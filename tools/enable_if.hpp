/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:43 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/15 10:48:22 by iidzim           ###   ########.fr       */
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

	template <class T> struct is_integral{ static const bool value = false; };
	template <> struct is_integral<bool>{ static const bool value = true; };
	template <> struct is_integral<char>{ static const bool value = true; };
	template <> struct is_integral<char16_t>{ static const bool value = true; };
	template <> struct is_integral<char32_t>{ static const bool value = true; };
	template <> struct is_integral<wchar_t>{ static const bool value = true; };
	template <> struct is_integral<signed char>{ static const bool value = true; };
	template <> struct is_integral<short int>{ static const bool value = true; };
	template <> struct is_integral<int>{ static const bool value = true; };
	template <> struct is_integral<long int>{ static const bool value = true; };
	template <> struct is_integral<long long int>{ static const bool value = true; };
	template <> struct is_integral<unsigned char>{ static const bool value = true; };
	template <> struct is_integral<unsigned short int>{ static const bool value = true; };
	template <> struct is_integral<unsigned int>{ static const bool value = true; };
	template <> struct is_integral<unsigned long int>{ static const bool value = true; };
	template <> struct is_integral<unsigned long long int>{ static const bool value = true; };
	
}

//? Note SFINAE at work here. When we make the call do_stuff(<int var>), the compiler selects
//? the first overload: since the condition std::is_integral<int> is true, the specialization
//? of struct enable_if for true is used, and its internal type is set to int.
//? The second overload is omitted because without the true specialization (std::is_class<int> is false)
//? the general form of struct enable_if is selected, and it doesn't have a type,
//? so the type of the argument results in a substitution failure.

#endif