/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:06:38 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/15 18:15:31 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "vector/vector.hpp"
#include "tools/iterator.hpp"
# include "tools/enable_if.hpp"

#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

// int main(void){

// 	ft::vector<int> first1;                                // empty vector of ints
// 	ft::vector<int> second1(3, 100);                       // four ints with value 100
// 	std::cout << second1.size() << " - " << second1.capacity() << std::endl;
// 	for (int i = 0; i < second1.size(); i++)
// 		std::cout << second1[i] << " ";
// 	std::cout << std::endl;
// 	ft::vector<int> third(second1);
// 	std::cout << "copy constructor -> ";
// 	for (int i = 0; i < third.size(); i++)
// 		std::cout << third[i] << " ";
// 	std::cout << std::endl;
// 	// third.reserve(10);
// 	// std::cout << "assignment operator -> ";
// 	// first1 = third;
// 	// for (int i = 0; i < first1.size(); i++)
// 	// 	std::cout << first1[i] << " ";
// 	ft::vector<int> third1(second1.begin(),second1.end());   // iterating through second
// 	// ft::vector<int> fourth (third);                       // a copy of third
// 	// the iterator constructor can also be used to construct from arrays:
// 	// ft::vector<int> fifth1 (myints, myints + sizeof(myints) / sizeof(int) );
// 	// std::cout << "The contents of fifth are:";
// 	// for (ft::vector<int>::iterator it = fifth1.begin(); it != fifth1.end(); ++it)
// 		// std::cout << ' ' << *it;
// 	// std::cout << '\n';

// 	return 0;
// }


// // ****************************

// // #include <iostream>
// // #include <type_traits>

// // // 1. the return type (bool) is only valid if T is an integral type:
// // template <typename T>
// // typename std::enable_if<std::is_integral<T>::value,bool>::type
// //   is_odd (T i) {return bool(i%2);}

// // // 2. the second template argument is only valid if T is an integral type:
// // template < class T,
// //            class = typename std::enable_if<std::is_integral<T>::value>::type>
// // bool is_even (T i) {return !bool(i%2);}

// // int main() {

// //   short int i = 1;    // code does not compile if type of i is not integral

// //   std::cout << std::boolalpha;
// //   std::cout << "i is odd: " << is_odd(i) << std::endl;
// //   std::cout << "i is even: " << is_even(i) << std::endl;

// //   return 0;
// // }

// // #include <iostream>
// // #include <type_traits>

// // int main() {
// //   std::cout << std::boolalpha;
// //   std::cout << "is_integral:" << std::endl;
// //   std::cout << "char: " << ft::is_integral<char>::value << std::endl;
// //   std::cout << "int: " << ft::is_integral<int>::value << std::endl;
// //   std::cout << "float: " << ft::is_integral<float>::value << std::endl;
// //   return 0;
// // }


// int main()
// {
// 	// ft::vector<int> test(5, 5);
// 	// ft::vector<int>::const_iterator itc = test.begin();

// 	// if (itc != test.end())
// 	//     std::cout<<"ls "<<std::endl;
// 	// //std::cout<<*itc<<std::endl;
// 	ft::vector<int> first;                                
// 	ft::vector<int> second (4,100);                       
// 	ft::vector<int> third (second.begin(),second.end());
// 	ft::vector<int> fourth (third);                      
// 	int myints[] = {16,2,77,29};
// 	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );	
// 	std::cout << "The contents of fifth are:";
// 	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)		std::cout << ' ' << *it;
// 	std::cout << '\n';	
// 	return 0;
// }