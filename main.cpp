/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:06:38 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/10 15:47:49 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "vector/vector.hpp"
#include "tools/iterator.hpp"

int main(void){

	// constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	// std::vector<int> third (second.begin(),second.end());  // iterating through second
	// std::vector<int> fourth (third);                       // a copy of third	
	// the iterator constructor can also be used to construct from arrays:
	// int myints[] = {16,2,77,29};
	// std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );	
	// std::cout << "The contents of fifth are:";
	// for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	ft::vector<int> first1;                                // empty vector of ints
	ft::vector<int> second1 (4,100);                       // four ints with value 100
	// ft::vector<int> third1 (second1.begin(),second1.end());  // iterating through second
	// ft::vector<int> fourth (third);                       // a copy of third	
	// the iterator constructor can also be used to construct from arrays:
	// int myints[] = {16,2,77,29};
	// ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );	
	// std::cout << "The contents of fifth are:";
	// for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	return 0;
}