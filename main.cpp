/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:06:38 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/09 17:21:40 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
// #include "vector/vector.hpp"
// #include "tools/iterator.hpp"

int main(void){

    // std::vector<int> v;
    // std::cout << "size = " << v.size() << " - capacity = " <<  v.capacity() << std::endl;
    // v.push_back(1);
    // std::cout << "size = " << v.size() << " - capacity = " <<  v.capacity() << std::endl;

    std::vector<int> v1, v2;
    // std::cout << v2.max_size() << std::endl;
    // std::cout << "size = " << v2.size() << " - capacity = " <<  v2.capacity() << std::endl;
    for (int i=0; i<10; i++){
        v2.push_back(i);
        v1.push_back(i*2);
    }
    std::cout << v2.size() << std::endl;
    v2.assign(5, 0);
    // v2.assign(v1.begin(), (v1.end() - v1.size()/2));
    // v2.assign(v1.begin(), v1.end());
    for (int i=0; i<v2.size(); i++){
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << v2.size() << std::endl;
    // std::cout << "size = " << v2.size() << " - capacity = " <<  v2.capacity() << std::endl;

    // ft::vector<int, std::allocator<int> > test;
    

    return 0;
}