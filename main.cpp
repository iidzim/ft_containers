// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/05 18:06:38 by iidzim            #+#    #+#             */
// /*   Updated: 2021/12/19 23:06:03 by iidzim           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <vector>
// #include <memory>
// #include "vector/vector.hpp"
// #include "tools/iterator.hpp"
// # include "tools/tools.hpp"

// #include <iterator>
// #include <ctime>
// #include <iomanip>
// #include <unistd.h>
// #include <signal.h>
// #include <sys/time.h>

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


// int main()
// {
// 	// ft::vector<int> test(5, 5);
// 	// ft::vector<int>::const_iterator itc = test.begin();

// 	// if (itc != test.end())
// 	//     std::cout<<"ls "<<std::endl;
// 	// std::cout<<*itc<<std::endl;


// // //*********************************************************************************
   
// //     ft::vector<int> d;
// //     d.push_back(1);
// //     d.push_back(2);
// //     d.push_back(3);
// //     d.push_back(4);
// //     d.push_back(5);
// //     d.push_back(6);
// //     d.push_back(7);
// //     d.push_back(8);

// //     std::cout << d.size() << " - " << d.capacity() << std::endl;
// //     d.insert(d.begin()+4, 10, 99);
// //     for (size_t j=0; j<d.size(); j++)
// //         std::cout << d[j] << " ";
// //     std::cout << std::endl;
// //     std::cout << d.size() << " - " << d.capacity() << std::endl;

// // //*********************************************************************************

// //     std::cout << "******************\n";
	
// //     std::vector<int> d1;
// //     d1.push_back(1);
// //     d1.push_back(2);
// //     d1.push_back(3);
// //     d1.push_back(4);
// //     d1.push_back(5);
// //     d1.push_back(6);
// //     d1.push_back(7);
// //     d1.push_back(8);

// //     std::cout << d1.size() << " - " << d1.capacity() << std::endl;
// //     d1.insert(d1.begin()+4, 10, 99);
// //     for (size_t j=0; j<d1.size(); j++)
// //         std::cout << d1[j] << " ";
// //     std::cout << std::endl;
// //     std::cout << d1.size() << " - " << d1.capacity() << std::endl;

// 	// std::cout << d1.size() << " - " << d1.capacity() << std::endl;
// 	// d1.insert(d1.begin()+1, 2);
// 	// for (size_t i=0; i<d1.size(); i++)
// 	//     std::cout << d1[i] << " ";
// 	// std::cout << std::endl;
// 	// std::cout << *be << std::endl;
// 	// std::cout << data.size() << " - " << data.capacity() << std::endl;
// 	// data.insert(be, 999);
// 	// for (size_t i=0; i<data.size(); i++)
// 	//     std::cout << data[i] << " ";
// 	// std::cout << std::endl;
// 	// std::cout << data.size() << " - " << data.capacity() << std::endl;

// 	// std::cout << "*********************\n";
// 	// std::cout << "std insert\n";

// 	// std::vector<int> d2;
// 	// d2.push_back(1);
// 	// d2.push_back(5);
// 	// d2.push_back(6);
// 	// std::cout << d2.size() << " - " << d2.capacity() << std::endl;
// 	// // d2.insert(d2.begin()+1, 2);
// 	// d2.insert(d2.begin()+1, 3, 2);
// 	// for (size_t j=0; j<d2.size(); j++)
// 	//     std::cout << d2[j] << " ";
// 	// std::cout << std::endl;
// 	// std::cout << d2.size() << " - " << d2.capacity() << std::endl;

// 	// std::vector<int> data1(20, 5);
// 	// std::vector<int>::iterator    be1 = data1.begin();
// 	// be1 += 3;
// 	// // std::cout << *be1 << std::endl;
// 	// std::cout << data1.size() << " - " << data1.capacity() << std::endl;
// 	// data1.insert(be1, 999);
// 	// for (size_t i=0; i<data1.size(); i++)
// 	//     std::cout << data1[i] << " ";
// 	// std::cout << std::endl;
// 	// std::cout << data1.size() << " - " << data1.capacity() << std::endl;

// //*********************************************************************************
// 	// ft::vector<std::string> ft_v1(10, "string2");
// 	//         // std::vector<std::string>    v1(1e6, "string2");
// 	// std::vector<std::string> v2(5, "string1");
// 	// // for (int i =0; i<v2.size(); i++)
// 	// //     std::cout << v2[i] << " ";
// 	// // std::cout << std::endl;
// 	// v2.assign(ft_v1.begin(), ft_v1.end());
// 	// // for (int i =0; i<v2.size(); i++)
// 	// //     std::cout << v2[i] << " ";
// 	// // std::cout << std::endl;
// 	// std::vector<int> v;
// 	// for (int i = 0;i < 10;i++)
// 	//     v.push_back(i);
// 	// std::vector<int>::const_iterator it = v.begin();
	
// 	// it += 2;
// 	// std::cout << *it << std::endl;

// 	// ft::vector<int> abc;
// 	// ft::vector<int> data(20);
// 	// ft::vector<int>::const_iterator it;
	
// 	// for (int i = 0; i < 10;i++)
// 	//     abc.push_back(i+1);
// 	// for (int i = 0; i < abc.size(); i++)
// 	//     std::cout << abc[i] << " ";
// 	// std::cout << std::endl;
// 	// it = data.begin();
// 	// it = it + 3;
// 	// data.insert(it,abc.begin(),abc.end());
// 	// for (int i = 0; i < data.size(); i++)
// 	//     std::cout << data[i] << " ";
// 	// std::cout << std::endl;

// 	// std::cout << "***************************\n";
// 	// //*******************************************************
	
// 	// std::vector<int> abc1;
// 	// std::vector<int> data1(20);
// 	// std::vector<int>::const_iterator it1;
	
// 	// for (int i = 0; i < 10;i++)
// 	//     abc1.push_back(i+1);
// 	// for (int i = 0; i < abc1.size(); i++)
// 	//     std::cout << abc1[i] << " ";
// 	// std::cout << std::endl;
// 	// it1 = data1.begin();
// 	// it1 = it1 + 3;
// 	// data1.insert(it1,abc1.begin(),abc1.end());
// 	// for (int i = 0; i < data1.size(); i++)
// 	//     std::cout << data1[i] << " ";
// 	// std::cout << std::endl;

// 	// ft::vector<int> a;
// 	// for (int i = 0; i < 16; i++)
// 	// 	a.push_back(i);
// 	// a.clear();
// 	// std::cout << "size = " << a.size() << "capacity = " << a.capacity() << std::endl;
// 	// for (ft::vector<int>::iterator it = a.begin(); it != a.end(); it++)
// 	// 	std::cout << *it << std::endl;
// 	// // for (int i = 0; i < a.size(); i++)
// 	// 	// std::cout << a[i] << std::endl;
// 	// std::cout << a[5] << std::endl;
// 	// a.push_back(99);
// 	// std::cout << a[0] << std::endl;
// 	// std::cout << "*********************\n";
	
// 	// std::vector<int> aq;
// 	// for (int i = 0; i < 16; i++)
// 	// 	aq.push_back(i);
// 	// aq.clear();
// 	// std::cout << "size = " << aq.size() << "capacity = " << aq.capacity() << std::endl;
// 	// for (std::vector<int>::iterator itt = aq.begin(); itt != aq.end(); itt++)
// 	// 	std::cout << *itt << std::endl;
// 	// std::cout << aq[5] << std::endl;
// 	// aq.push_back(99);
// 	// std::cout << aq[0] << std::endl;
	

// 	return 0;
// }

#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
