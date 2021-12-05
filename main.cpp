/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:06:38 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/05 18:46:14 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "vector/vector.hpp"
#include "tools/iterator.hpp"

int main(void){

    // std::vector<int> v;
    // std::cout << "size = " << v.size() << " - capacity = " <<  v.capacity() << std::endl;
    // v.push_back(1);
    // std::cout << "size = " << v.size() << " - capacity = " <<  v.capacity() << std::endl;

    // std::vector<int> v2;
    // std::cout << "size = " << v2.size() << " - capacity = " <<  v2.capacity() << std::endl;
    // for (int i=0; i<9; i++)
    //     v2.push_back(i);
    // std::cout << "size = " << v2.size() << " - capacity = " <<  v2.capacity() << std::endl;

    ft::vector<int, std::allocator<int> > test;
    

    return 0;
}