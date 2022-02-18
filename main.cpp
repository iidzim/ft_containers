/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:06:38 by iidzim            #+#    #+#             */
/*   Updated: 2022/02/18 14:55:17 by iidzim           ###   ########.fr       */
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

using std::cout;
using std::endl;
using std::string;


// #include <type_traits>

// // 1. the return type (bool) is only valid if T is an integral type:
// template <typename T>
// typename std::enable_if<std::is_integral<T>::value,bool>::type
//   is_odd (T i) {return bool(i%2);}

// // 2. the second template argument is only valid if T is an integral type:
// template < class T,
//            class = typename std::enable_if<std::is_integral<T>::value>::type>
// bool is_even (T i) {return !bool(i%2);}

// int main() {

//   short int i = 1;    // code does not compile if type of i is not integral

//   std::cout << std::boolalpha;
//   std::cout << "i is odd: " << is_odd(i) << std::endl;
//   std::cout << "i is even: " << is_even(i) << std::endl;

//   return 0;
// }

// #include <iostream>
// #include <type_traits>

// int main() {
//   std::cout << std::boolalpha;
//   std::cout << "is_integral:" << std::endl;
//   std::cout << "char: " << ft::is_integral<char>::value << std::endl;
//   std::cout << "int: " << ft::is_integral<int>::value << std::endl;
//   std::cout << "float: " << ft::is_integral<float>::value << std::endl;
//   return 0;
// }


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

// {
// 	std::vector<int> vect(5, 99);
// 	std::vector<int>::iterator it;
// 	vect.push_back(9);
// 	vect.push_back(9);
// 	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
// 	vect.resize(461168);
// 	// for (it = vect.begin(); it < vect.end(); it++)
// 	// 	std::cout << *it << " ";
// 	std::cout << std::endl;
// 	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
// }

// std::cout << "****************\n";

// {
// 	ft::vector<int> vect(5, 99);
// 	ft::vector<int>::iterator it;
// 	vect.push_back(9);
// 	vect.push_back(9);
// 	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
// 	vect.resize(461168);
// 	// for (it = vect.begin(); it < vect.end(); it++)
// 	// 	std::cout << *it << " ";
// 	std::cout << std::endl;
// 	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
// }
	

// {
// 	std::vector<string> v(12, "hello");
// 	std::vector<string> v(12, "bye");
// 	std::vector<string>::iterator it;
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	// v.assign(130, "hola");
// 	v.assign();
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	// for (it = v.begin(); it < v.end(); it++)
// 	// 	cout << *it << " ";
// 	// cout << endl;
// }
// cout << "*****************\n";
// {
// 	ft::vector<string> v(12, "hello");
// 	ft::vector<string> v(12, "bye");
// 	ft::vector<string>::iterator it;
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	v.assign(130, "hola");
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	// for (it = v.begin(); it < v.end(); it++)
// 	// 	cout << *it << " ";
// 	// cout << endl;
// }

// {
// 	std::vector<int> v;
// 	for (int i = 0; i < 10; i++)
// 		v.push_back(i+1);
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	v.resize(100);
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	v.clear();
// 	cout << v.size() << " - " << v.capacity() << endl;
// }
// cout << "*****************\n";
// {
// 	ft::vector<int> v;
// 	for (int i = 0; i < 10; i++)
// 		v.push_back(i+1);
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	v.resize(100);
// 	cout << v.size() << " - " << v.capacity() << endl;
// 	v.clear();
// 	cout << v.size() << " - " << v.capacity() << endl;
// }


// {v.insert(v)
// 	std::vector<int> a(10, 5);
// 	std::vector<int>::iterator it;

// 	for (size_t i = 0; i < a.size(); i++)
// 		cout << a[i] << " ";
// 	cout << endl;
// 	a.insert(a.end(), a.begin(), a.end());
// 	for (size_t i = 0; i < a.size(); i++)
// 		cout << a[i] << " ";
// 	cout << endl;	
// }
// cout << "*******************\n";
// {//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! append vector to itself
// 	ft::vector<int> a(10, 5);
// 	ft::vector<int> b;
// 	ft::vector<int>::iterator it;

// 	for (size_t i = 0; i < a.size(); i++)
// 		cout << a[i] << " ";
// 	cout << endl;
// 	b = a;
// 	b.insert(b.end(), a.begin(), a.end());//?????
// 	for (size_t i = 0; i < a.size(); i++)
// 		cout << a[i] << " ";
// 	cout << endl;	
// }

// {//*insert(value)
// 	std::vector<string> s, x;
// 	s.insert(s.end(), "first");
// 	cout << s.front() << endl;
// 	cout << s.back() << endl;
// 	s.insert(s.end() - 1, "second");
// 	cout << s[1] << endl;
// 	cout << s.front() << endl;
// 	// s.insert(s.begin() + 1, "second");
// 	// cout << s[1] << endl;
// 	// x.insert(x.end(), s.begin(), s.end());
// }
// cout << "****************\n";
// {
// 	ft::vector<string> s, x;
// 	s.insert(s.end(), "first");
// 	cout << s.front() << endl;
// 	cout << s.back() << endl;
// 	s.insert(s.end() - 1, "second");
// 	cout << s[1] << endl;
// 	cout << s.front() << endl;
// 	// s.insert(s.begin() + 1, "second");
// 	// cout << s[1] << endl;
// 	// x.insert(x.end(), s.begin(), s.end());
// }

// {
// 	std::vector<int> a;
// 	std::vector<int> b(20);
// 	std::vector<int> c(100000);
// 	// cout << a.size() << " - " << a.capacity() << endl;
// 	// cout << b.size() << " - " << b.capacity() << endl;
// 	a.push_back(1);
// 	a.push_back(2);
// 	a.push_back(3);
// 	std::vector<int> d(a);
// 	b = a;
// 	cout << a.size() << " - " << a.capacity() << endl;
// 	cout << b.size() << " - " << b.capacity() << endl;
// 	// cout << c.size() << " - " << c.capacity() << endl;
// 	cout << d.size() << " - " << d.capacity() << endl;
// }
// cout << "*****************\n";
// {
// 	ft::vector<int> a;
// 	ft::vector<int> b(20);
// 	ft::vector<int> c(100000);
// 	// cout << a.size() << " - " << a.capacity() << endl;
// 	// cout << b.size() << " - " << b.capacity() << endl;
// 	a.push_back(1);
// 	a.push_back(2);
// 	a.push_back(3);
// 	// cout << "d\n";
// 	ft::vector<int> d(a);
// 	// cout << "b\n";
// 	b = a;
// 	cout << a.size() << " - " << a.capacity() << endl;
// 	cout << b.size() << " - " << b.capacity() << endl;
// 	// cout << c.size() << " - " << c.capacity() << endl;
// 	cout << d.size() << " - " << d.capacity() << endl;
// }


// {
// 	std::vector<string> s(10, "hola");
// 	s.push_back("first");
// 	s.push_back("second");
// 	cout << "size = " << s.size() << " - capacity = " << s.capacity() << endl;
// 	s.erase(s.begin()+5);
// 	cout << "size = " << s.size() << " - capacity = " << s.capacity() << endl;
// }
// cout << "****************\n";
// {
// 	ft::vector<string> s(10, "hola");
// 	s.push_back("first");
// 	s.push_back("second");
// 	cout << "size = " << s.size() << " - capacity = " << s.capacity() << endl;
// 	s.erase(s.begin()+5);
// 	cout << "size = " << s.size() << " - capacity = " << s.capacity() << endl;
// }

// {
//  	std::vector<int> vector(10, 5);
//  	std::vector<int> vector2(15, 9);
// 	cout << "size = " << vector2.size() << " - capacity = " << vector2.capacity() << endl;

// 	vector2 = vector;
// 	cout << "size = " << vector2.size() << " - capacity = " << vector2.capacity() << endl;

// }
// cout << "****************\n";
// {
//  	ft::vector<int> vector(10, 5);
//  	ft::vector<int> vector2(15, 9);
// 	cout << "size = " << vector2.size() << " - capacity = " << vector2.capacity() << endl;

// 	vector2 = vector;
// 	cout << "size = " << vector2.size() << " - capacity = " << vector2.capacity() << endl;

// }
    // std::cout << "=--=-==--- " <<*(vector.insert(vector.end() - 8000000, 44)) << "=--=-==--- " << std::endl;


// {
// 	std::vector<int> v;
// 	v.assign(10, 2);
// 	cout << *(v.insert(v.end()-5, 99)) << endl;
	
// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// 	std::cout << v.size() << " * " << v.capacity() << std::endl;

// }
// cout << "****************\n";
// {
// 	ft::vector<int> v;
// 	v.assign(10, 2);
// 	cout << *(v.insert(v.end()-5, 99)) << endl;
	
// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// 	std::cout << v.size() << " * " << v.capacity() << std::endl;

// }

// {
// 	std::vector<int> v;
// 	v.assign(10, 2);
// 	v.insert(v.end()-11, 5, 99);
// 	// v.insert(v.end()-11, 5);
	
// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// 	std::cout << v.size() << " * " << v.capacity() << std::endl;

// }
// cout << "****************\n";
// {
// 	ft::vector<int> v;
// 	v.assign(10, 2);
// 	v.insert(v.end()-11, 5, 99);
// 	// v.insert(v.end()-11, 5);
	
// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// 	std::cout << v.size() << " * " << v.capacity() << std::endl;

// }

// {
// 	std::vector<int> v;
// 	v.assign(10, 2);

// 	std::vector<int> b;
// 	b.assign(3, 5);
	
// 	b.swap(v);

// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// 	std::cout << v.size() << " * " << v.capacity() << std::endl;
// 	for (size_t i = 0; i < b.size(); i++)
// 		cout << b[i] << " ";
// 	cout << endl;
// 	std::cout << b.size() << " * " << b.capacity() << std::endl;
// }
// cout << "****************\n";
// {
// 	ft::vector<int> v;
// 	v.assign(10, 2);

// 	ft::vector<int> b;
// 	b.assign(3, 5);

// 	b.swap(v);

// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// 	std::cout << v.size() << " * " << v.capacity() << std::endl;
// 	for (size_t i = 0; i < b.size(); i++)
// 		cout << b[i] << " ";
// 	cout << endl;
// 	std::cout << b.size() << " * " << b.capacity() << std::endl;
// }

// {
// 	std::vector<int> v(10);
// 	v.insert(v.begin()+5, 5);
// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// }
// cout << "**************\n";
// {
// 	ft::vector<int> v(10);
// 	v.insert(v.begin()+5, 5);
// 	for (size_t i = 0; i < v.size(); i++)
// 		cout << v[i] << " ";
// 	cout << endl;
// }

// std::cout << v.size() << " <><><><> " << ft_v.size() << std::endl;
// std::cout << "here!!!!!!!!!!!!!!!!" << std::endl;

// {
// 	std::vector<int> a;
// 	a.insert(a.begin(), 10, 1);
// 	a.insert(a.begin() + a.size(), 2);
// 	a.insert(a.end(), 5, 3);
// 	// a.insert(a.begin(), 4);
// 	// a.insert(a.end() - a.size(), 5);
// 	cout << a.size() << " * " << a.capacity() << endl;
// 	for (size_t i = 0; i < a.size(); i++)
// 		cout << a[i] << " ";
// 	cout << endl;
	
// 	cout << "*****************\n";

// 	ft::vector<int> b;
// 	b.insert(b.begin(), 10, 1);
// 	b.insert(b.begin() + b.size(), 2);
// 	b.insert(b.end(), 5, 3);
// 	// b.insert(b.begin(), 4);
// 	// b.insert(b.end() - b.size(), 5);
// 	cout << b.size() << " * " << b.capacity() << endl;
// 	for (size_t i = 0; i < b.size(); i++)
// 		cout << b[i] << " ";
// 	cout << endl;

// 	// if (a == b)
// 	// 	cout << "ok\n";
// }

// {//? insert fill
	// std::vector<string> s(10, "o");
	// std::vector<string> s;
	// cout << s.capacity() << " - " << s.size() << endl;
	// for (size_t i = 0; i < s.size(); i++)
	// 	cout << s[i] << " ";
	// cout << endl;
	// s.insert(s.begin() + 2, 5, "a");
	// s.insert(s.end()-2, 5, "k");
	// s.insert(s.end(), 5, "k");
	// cout << s.capacity() << " - " << s.size() << endl;
	// for (size_t i = 0; i < s.size(); i++)
		// cout << s[i] << " ";
	// cout << endl;
// }
// cout << "**********\n";
// {
	// ft::vector<string> s(10, "o");
	// ft::vector<string> s;
	// cout << s.capacity() << " - " << s.size() << endl;
	// for (size_t i = 0; i < s.size(); i++)
	// 	cout << s[i] << " ";
	// cout << endl;
	// s.insert(s.begin() + 2, 5, "a");
	// s.insert(s.end()-2, 5, "k");
	// s.insert(s.end(), 5, "k");
	// cout << s.capacity() << " - " << s.size() << endl;
	// for (size_t i = 0; i < s.size(); i++)
		// cout << s[i] << " ";
	// cout << endl;
// }

// {
// 	std::vector<string> v(10, "1");
// 	std::vector<string> s(5, "2");
// 	// std::vector<string> s;
// 	// for (size_t i = 0; i < s.size(); i++)
// 	// 	cout << s[i] << " ";
// 	// cout << endl;
// 	// s.insert(s.begin( j) + s.size(), "33");
// 	s.insert(s.begin()+5, "33");
// 	s.insert(s.begin() , v.begin(), v.end());
// 	for (size_t i = 0; i < s.size(); i++)
// 		cout << s[i] << " ";
// 	cout << endl;
// }
// cout << "*********\n";
// {
// 	ft::vector<string> v(10, "1");
// 	ft::vector<string> s(5, "2");
// 	// ft::vector<string> s;
// 	// for (size_t i = 0; i < s.size(); i++)
// 	// 	cout << s[i] << " ";
// 	// cout << endl;
// 	// s.insert(s.begin() + s.size(), "33");
// 	s.insert(s.begin()+5, "33");
// 	s.insert(s.begin() , v.begin(), v.end());
// 	for (size_t i = 0; i < s.size(); i++)
// 		cout << s[i] << " ";
// 	cout << endl;
// }


	// ft::pair<int, float> p1;
	// ft::pair<int, float> p2(1, 0.2659);
	// ft::pair<int, float> p3(p2);
	// ft::pair<string, int> p4;

	// p1.first = 5;
	// p1.second = 3.1416;

	// cout << " pair | first | second\n";
	// cout << "p1: " << p1.first << ", " << p1.second << endl;
	// cout << "p2: " << p2.first << ", " << p2.second << endl;
	// cout << "p3: " << p3.first << ", " << p3.second << endl;
	// cout << "p4: " << p4.first << ", " << p4.second << endl;

	// p3 = ft::make_pair(123, 456.789);
	// p4.first = "testtest";
	// p4.second = 2147483647;

	// cout << "p3: " << p3.first << ", " << p3.second << endl;
	// cout << "p4: " << p4.first << ", " << p4.second << endl;



	return (0);
}
