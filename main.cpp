/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:06:38 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/23 18:42:25 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "vector/vector.hpp"
#include "tools/iterator.hpp"
# include "tools/tools.hpp"

#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

// // int main(void){

// // 	ft::vector<int> first1;                                // empty vector of ints
// // 	ft::vector<int> second1(3, 100);                       // four ints with value 100
// // 	std::cout << second1.size() << " - " << second1.capacity() << std::endl;
// // 	for (int i = 0; i < second1.size(); i++)
// // 		std::cout << second1[i] << " ";
// // 	std::cout << std::endl;
// // 	ft::vector<int> third(second1);
// // 	std::cout << "copy constructor -> ";
// // 	for (int i = 0; i < third.size(); i++)
// // 		std::cout << third[i] << " ";
// // 	std::cout << std::endl;
// // 	// third.reserve(10);
// // 	// std::cout << "assignment operator -> ";
// // 	// first1 = third;
// // 	// for (int i = 0; i < first1.size(); i++)
// // 	// 	std::cout << first1[i] << " ";
// // 	ft::vector<int> third1(second1.begin(),second1.end());   // iterating through second
// // 	// ft::vector<int> fourth (third);                       // a copy of third
// // 	// the iterator constructor can also be used to construct from arrays:
// // 	// ft::vector<int> fifth1 (myints, myints + sizeof(myints) / sizeof(int) );
// // 	// std::cout << "The contents of fifth are:";
// // 	// for (ft::vector<int>::iterator it = fifth1.begin(); it != fifth1.end(); ++it)
// // 		// std::cout << ' ' << *it;
// // 	// std::cout << '\n';

// // 	return 0;
// // }


// // // ****************************

// // // #include <iostream>
// // // #include <type_traits>

// // // // 1. the return type (bool) is only valid if T is an integral type:
// // // template <typename T>
// // // typename std::enable_if<std::is_integral<T>::value,bool>::type
// // //   is_odd (T i) {return bool(i%2);}

// // // // 2. the second template argument is only valid if T is an integral type:
// // // template < class T,
// // //            class = typename std::enable_if<std::is_integral<T>::value>::type>
// // // bool is_even (T i) {return !bool(i%2);}

// // // int main() {

// // //   short int i = 1;    // code does not compile if type of i is not integral

// // //   std::cout << std::boolalpha;
// // //   std::cout << "i is odd: " << is_odd(i) << std::endl;
// // //   std::cout << "i is even: " << is_even(i) << std::endl;

// // //   return 0;
// // // }

// // // #include <iostream>
// // // #include <type_traits>

// // // int main() {
// // //   std::cout << std::boolalpha;
// // //   std::cout << "is_integral:" << std::endl;
// // //   std::cout << "char: " << ft::is_integral<char>::value << std::endl;
// // //   std::cout << "int: " << ft::is_integral<int>::value << std::endl;
// // //   std::cout << "float: " << ft::is_integral<float>::value << std::endl;
// // //   return 0;
// // // }


int main()
{
	// ft::vector<int> test(5, 5);
	// ft::vector<int>::const_iterator itc = test.begin();

	// if (itc != test.end())
	//     std::cout<<"ls "<<std::endl;
	// std::cout<<*itc<<std::endl;


// //*********************************************************************************
   
//     ft::vector<int> d;
//     d.push_back(1);
//     d.push_back(2);
//     d.push_back(3);
//     d.push_back(4);
//     d.push_back(5);
//     d.push_back(6);
//     d.push_back(7);
//     d.push_back(8);

//     std::cout << d.size() << " - " << d.capacity() << std::endl;
//     d.insert(d.begin()+4, 10, 99);
//     for (size_t j=0; j<d.size(); j++)
//         std::cout << d[j] << " ";
//     std::cout << std::endl;
//     std::cout << d.size() << " - " << d.capacity() << std::endl;

// //*********************************************************************************

//     std::cout << "******************\n";
	
//     std::vector<int> d1;
//     d1.push_back(1);
//     d1.push_back(2);
//     d1.push_back(3);
//     d1.push_back(4);
//     d1.push_back(5);
//     d1.push_back(6);
//     d1.push_back(7);
//     d1.push_back(8);

//     std::cout << d1.size() << " - " << d1.capacity() << std::endl;
//     d1.insert(d1.begin()+4, 10, 99);
//     for (size_t j=0; j<d1.size(); j++)
//         std::cout << d1[j] << " ";
//     std::cout << std::endl;
//     std::cout << d1.size() << " - " << d1.capacity() << std::endl;

	// std::cout << d1.size() << " - " << d1.capacity() << std::endl;
	// d1.insert(d1.begin()+1, 2);
	// for (size_t i=0; i<d1.size(); i++)
	//     std::cout << d1[i] << " ";
	// std::cout << std::endl;
	// std::cout << *be << std::endl;
	// std::cout << data.size() << " - " << data.capacity() << std::endl;
	// data.insert(be, 999);
	// for (size_t i=0; i<data.size(); i++)
	//     std::cout << data[i] << " ";
	// std::cout << std::endl;
	// std::cout << data.size() << " - " << data.capacity() << std::endl;

	// std::cout << "*********************\n";
	// std::cout << "std insert\n";

	// std::vector<int> d2;
	// d2.push_back(1);
	// d2.push_back(5);
	// d2.push_back(6);
	// std::cout << d2.size() << " - " << d2.capacity() << std::endl;
	// // d2.insert(d2.begin()+1, 2);
	// d2.insert(d2.begin()+1, 3, 2);
	// for (size_t j=0; j<d2.size(); j++)
	//     std::cout << d2[j] << " ";
	// std::cout << std::endl;
	// std::cout << d2.size() << " - " << d2.capacity() << std::endl;

	// std::vector<int> data1(20, 5);
	// std::vector<int>::iterator    be1 = data1.begin();
	// be1 += 3;
	// // std::cout << *be1 << std::endl;
	// std::cout << data1.size() << " - " << data1.capacity() << std::endl;
	// data1.insert(be1, 999);
	// for (size_t i=0; i<data1.size(); i++)
	//     std::cout << data1[i] << " ";
	// std::cout << std::endl;
	// std::cout << data1.size() << " - " << data1.capacity() << std::endl;

//*********************************************************************************
	// ft::vector<std::string> ft_v1(10, "string2");
	//         // std::vector<std::string>    v1(1e6, "string2");
	// std::vector<std::string> v2(5, "string1");
	// // for (int i =0; i<v2.size(); i++)
	// //     std::cout << v2[i] << " ";
	// // std::cout << std::endl;
	// v2.assign(ft_v1.begin(), ft_v1.end());
	// // for (int i =0; i<v2.size(); i++)
	// //     std::cout << v2[i] << " ";
	// // std::cout << std::endl;
	// std::vector<int> v;
	// for (int i = 0;i < 10;i++)
	//     v.push_back(i);
	// std::vector<int>::const_iterator it = v.begin();
	
	// it += 2;
	// std::cout << *it << std::endl;

	// ft::vector<int> abc;
	// ft::vector<int> data(20);
	// ft::vector<int>::const_iterator it;
	
	// for (int i = 0; i < 10;i++)
	//     abc.push_back(i+1);
	// for (int i = 0; i < abc.size(); i++)
	//     std::cout << abc[i] << " ";
	// std::cout << std::endl;
	// it = data.begin();
	// it = it + 3;
	// data.insert(it,abc.begin(),abc.end());
	// for (int i = 0; i < data.size(); i++)
	//     std::cout << data[i] << " ";
	// std::cout << std::endl;

	// std::cout << "***************************\n";
	// //*******************************************************
	
	// ft::vector<int> abc1;
	// ft::vector<int> data1(20);
	// ft::vector<int>::const_iterator it1;
	// // ft::vector<int>::iterator it1;

	// for (int i = 0; i < 10;i++)
	//     abc1.push_back(i+1);
	// for (size_t i = 0; i < abc1.size(); i++)
	//     std::cout << abc1[i] << " ";
	// std::cout << std::endl;
	// // it1 = data1.begin();
	// // it1 = it1 + 3;
	// // it1 = abc1.begin();
	// data1.assign(it1, abc1.end());
	// // data1.insert(it1,abc1.begin(),abc1.end());
	// // data1.insert(it1, 99);
	// for (size_t i = 0; i < data1.size(); i++)
	//     std::cout << data1[i] << " ";
	// std::cout << std::endl;

	// ft::vector<int> a;
	// for (int i = 0; i < 16; i++)
	// 	a.push_back(i);
	// a.clear();
	// std::cout << "size = " << a.size() << "capacity = " << a.capacity() << std::endl;
	// for (ft::vector<int>::iterator it = a.begin(); it != a.end(); it++)
	// 	std::cout << *it << std::endl;
	// // for (int i = 0; i < a.size(); i++)
	// 	// std::cout << a[i] << std::endl;
	// std::cout << a[5] << std::endl;
	// a.push_back(99);
	// std::cout << a[0] << std::endl;
	// std::cout << "*********************\n";
	
	// std::vector<int> aq;
	// for (int i = 0; i < 16; i++)
	// 	aq.push_back(i);
	// aq.clear();
	// std::cout << "size = " << aq.size() << "capacity = " << aq.capacity() << std::endl;
	// for (std::vector<int>::iterator itt = aq.begin(); itt != aq.end(); itt++)
	// 	std::cout << *itt << std::endl;
	// std::cout << aq[5] << std::endl;
	// aq.push_back(99);
	// std::cout << aq[0] << std::endl;
	

	// std::vector<int> v(10);
	// std::vector<int>::iterator it;
	// std::vector<int>::const_iterator cit;

	// it = v.begin() + 3;
	// cit = v.begin();
	// int diff = it - cit;
	// std::cout << diff << std::endl;
	// if (cit == it)
	// 	std::cout << "true" << std::endl;

	// ft::vector<int> data(10,3);
	// ft::vector<int> abc(3,88);
	// ft::vector<int>::const_iterator it;
	// std::vector<int> a;

	// it = data.begin();
	// abc.insert(it +2,data.begin(),data.end());
	// a.insert(a.begin(), data.begin(), data.end());
	// a.insert(a.begin(), it, it + data.size());


	// std::vector<int> myvector;
	// for (int i=1; i<=10; i++)
	// 	myvector.push_back(i);
	// myvector.erase (myvector.begin()+6);
	// myvector.erase (myvector.begin(),myvector.begin()+3);
	// std::cout << "myve contains:";
	// for (unsigned i=0; i<myvector.size(); ++i)
	// 	std::cout << ' ' << myvector[i];
	// std::cout << '\n';

	// std::cout << "**********************\n";

	// ft::vector<int> vect;
	// for (int i=1; i<=10; i++)
	// 	vect.push_back(i);
	// vect.erase (vect.begin()+6);
	// vect.erase (vect.begin(),vect.begin()+3);
	// std::cout << "vect contains:";
	// for (unsigned i=0; i<vect.size(); ++i)
	// 	std::cout << ' ' << vect[i];
	// std::cout << '\n';

{
	std::vector<int> vect(5, 99);
	std::vector<int>::iterator it;
	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
	vect.resize(461168);
	// for (it = vect.begin(); it < vect.end(); it++)
	// 	std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
}

std::cout << "****************\n";

{
	ft::vector<int> vect(5, 99);
	ft::vector<int>::iterator it;
	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
	vect.resize(461168);
	// for (it = vect.begin(); it < vect.end(); it++)
	// 	std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
}
	
	return 0;
}
