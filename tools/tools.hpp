/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:23:43 by iidzim            #+#    #+#             */
/*   Updated: 2022/01/31 18:36:19 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP
#include <type_traits>
#include "./iterator.hpp"
#include "./reverse_iterator.hpp"


namespace ft{

	//? Note SFINAE at work here. When we make the call do_stuff(<int var>), the compiler selects
	//? the first overload: since the condition std::is_integral<int> is true, the specialization
	//? of struct enable_if for true is used, and its internal type is set to int.
	//? The second overload is omitted because without the true specialization (std::is_class<int> is false)
	//? the general form of struct enable_if is selected, and it doesn't have a type,
	//? so the type of the argument results in a substitution failure.

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

	//************

	template <typename InputIterator1, typename InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){

		while (first1 != last1) {
  			if (!(*first1 == *first2))   
  				return (false);
  			++first1;
			++first2;
  		}
  		return (true);
	}


	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <typename iterator>
	struct iterator_traits{
	
		typedef typename iterator::iterator_category	iterator_category;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
	};

	template <typename T>
	struct iterator_traits<T*>{

		typedef std::random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

}


#endif