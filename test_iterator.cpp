/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:40:07 by iidzim            #+#    #+#             */
/*   Updated: 2021/12/13 23:36:11 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "./vector/vector.hpp"

int main(){

    //? Vector iterator tests
    // /*------------ std::vector ---------*/
    // std::vector<int> v(3, 4);
    // std::vector<int>::iterator it, it1;
    // it = v.begin();
    // it1 = v.begin() + 1;
    // /*------------ ft::Vector ---------*/
    // ft::vector<int> my_v(3, 4);
    // ft::vector<int>::iterator my_it, my_it1, tmp;
    // my_it = my_v.begin();
    // my_it1 = my_v.begin() + 1;
    // /*----------------------------------*/
    // ft::vector<int>::iterator ob(my_it);
    // if (ob == my_it)
    //     std::cout << "equal1" << std::endl;
    // else
    //     std::cout << "not equal1" << std::endl;
    // /*----------------------------------*/
    // ft::vector<int>::const_iterator c_it, c_ob(my_it);
    // c_it = my_it;
    // if (c_it == my_it && my_it == c_ob)
    //     std::cout << "equal2" << std::endl;
    // else
    //     std::cout << "not equal2" << std::endl;
    // /*----------------------------------*/
    // std::cout << std::boolalpha;
    // bool test = (it == it1) == (my_it == my_it1); std::cout << " == operator -> " << test << std::endl;
    // bool test2 = (it != it1) == (my_it != my_it1); std::cout << " != operator -> " << test2 << std::endl;
    // bool test3 = (it > it1) == (my_it > my_it1); std::cout << " > operator ->  " << test3 << std::endl;
    // bool test4 = (it >= it1) == (my_it >= my_it1); std::cout << " >= operator -> " << test4 << std::endl;
    // bool test5 = (it < it1) == (my_it < my_it1); std::cout << " < operator ->  " << test5 << std::endl;
    // bool test6 = (it <= it1) == (my_it <= my_it1); std::cout << " <= operator -> " << test6 << std::endl;

    // if (((*my_it = 6) == 6) && (*my_it == *(my_v.begin())))
    //     std::cout << "equal3" << std::endl;
    // else
    //     std::cout << "not equal3" << std::endl;

    // /*--------------- std::vector-------------------- */
    // std::vector<std::string> vv(3, "hello");
    // std::vector<std::string>::iterator itt = vv.begin();
    // /*---------------------------------------------- */
    // /*--------------- ft::vector-------------------- */
    // ft::vector<std::string> my_vv(3, "hello");
    // ft::vector<std::string>::iterator my_itt = my_vv.begin();
    // /*---------------------------------------------- */
    // if (itt->length() == my_itt->length())
    //     std::cout << "equal4" << std::endl;
    // else
    //     std::cout << "not equal4" << std::endl; 
    // /*---------------------------------------------- */
    // bool t = (&(*my_it) == &(*(my_it1 - 1))); std::cout << t << std::endl;
    // my_it += 1;
    // bool t1 = (&(*my_it) != &(*my_it1)); std::cout << t1 << std::endl;
    // my_it -= 1;
    // bool t2 = (&(*my_it) == &(*(my_it1 - 1))); std::cout << t2 << std::endl;
    // /*---------------------------------------------- */
    // if (((my_it[0] = 5) == 5) && (*my_it == 5))
    //     std::cout << "equal5" << std::endl;
    // else
    //     std::cout << "not equal5" << std::endl;
    // /*---------------------------------------------- */
    // ++my_it; // I incremented here to make sure that the object changes
    // if (&(*my_it) == &(*my_it1))
    //     std::cout << "equal6" << std::endl;
    // else
    //     std::cout << "not equal6" << std::endl;
    // /*---------------------------------------------- */
    // --my_it; // I decremented here to make sure that the object changes
    // if (&(*my_it) == &(*(my_it1 - 1)))
    //     std::cout << "equal7" << std::endl;
    // else
    //     std::cout << "not equal7" << std::endl;
    // /*---------------------------------------------- */
    // if (&(*(1 + my_it)) == &(*(my_it1)) && (&(*my_it) == &(*(my_v.begin()))))
    //     std::cout << "equal8" << std::endl;
    // else
    //     std::cout << "not equal8" << std::endl;
    // /*---------------------------------------------- */
    // if (((my_it1 - my_it == 1)) && ((my_it - my_it1) == -1))
    //     std::cout << "equal9" << std::endl;
    // else
    //     std::cout << "not equal9" << std::endl;
    // /*---------------------------------------------- */
    // tmp = my_it++;
    // if (&(*my_it) != &(*tmp) && (&(*my_it) == &(*my_it1)))
    //     std::cout << "equal10" << std::endl;
    // else
    //     std::cout << "not equal10" << std::endl;
    // /*---------------------------------------------- */
    // tmp = my_it--;
    // if (&(*my_it) != &(*tmp) && (&(*my_it) == &(*(my_v.begin()))))
    //     std::cout << "equal11" << std::endl;
    // else
    //     std::cout << "not equal11" << std::endl;

    //? Vector const_iterator tests


    
    //? Reverse_iterator tests
    /*------------ std::reverse_iterator ---------*/
    std::vector<int> v(3, 4);
    std::reverse_iterator<std::vector<int>::iterator> rit(v.end()), rit_1(v.end() - 1);
    /*------------ ft::reverse_iterator ---------*/
    ft::reverse_iterator<std::vector<int>::iterator> my_rit(v.end()), my_rit1(v.end() - 1);
    /*----------------------------------*/
    ft::reverse_iterator<std::vector<int>::iterator> ob(my_rit);
    std::cout << std::boolalpha;
    bool t = (&(*my_rit) == &(*ob)); std::cout << t << std::endl;
    /*----------------------------------*/
    ft::vector<int> vv(4, 5);
    ft::vector<int>::reverse_iterator my_rit2(vv.end());
    ft::vector<int>::const_reverse_iterator c_it, c_ob(vv.end());
    c_it = my_rit2;
    if (&(*my_rit2) == &(*c_it) && (&(*my_rit2) == &(*c_ob)))
        std::cout << "Equal 1" << std::endl;
    else
        std::cout << "Not Equal 1" << std::endl;
    /*----------------------------------*/
    if ((&(*rit) == &(*rit_1.base())) && (&(*my_rit) == &(*my_rit1.base())))
        std::cout << "Equal 2" << std::endl;
    else
        std::cout << "Not Equal 2" << std::endl;
    /*----------------------------------*/
    bool t1 = ((rit == rit_1) == (my_rit == my_rit1)); std::cout << " == operator " << t1 << std::endl;
    bool t2 = ((rit != rit_1) == (my_rit != my_rit1)); std::cout << " != operator " << t2 << std::endl;
    bool t3 = ((rit > rit_1) == (my_rit > my_rit1)); std::cout << " >  operator " << t3 << std::endl;
    bool t4 = ((rit >= rit_1) == (my_rit >= my_rit1)); std::cout << " >= operator " << t4 << std::endl;
    bool t5 = ((rit < rit_1) == (my_rit < my_rit1)); std::cout << " <  operator " << t5 << std::endl;
    bool t6 = ((rit <= rit_1) == (my_rit <= my_rit1)); std::cout << " <= operator " << t6 << std::endl;

    bool tt = (((*my_rit == *(v.end() - 1)) && (&(*my_rit) == &(*(v.end() - 1))))
        && ((*rit == *(v.end() - 1)) && (&(*rit) == &(*(v.end() - 1)))));
    std::cout << "operator * " << tt << std::endl;
    /*----------------------------------*/
    std::vector<std::string> tv(3, "hello");
    std::reverse_iterator<std::vector<std::string>::iterator> ritt(tv.end());
    ft::reverse_iterator<std::vector<std::string>::iterator> my_ritt(tv.end());
    bool ttt = (ritt->length() == my_ritt->length()); std::cout << "operator-> " << ttt << std::endl;
    bool tminus = ((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "operator- " << tminus << std::endl;
    bool tplus = ((&(*(my_rit + 1)) == &(*my_rit1)) && (&(*(rit + 1)) == &(*rit_1)));
    std::cout << "operator+ " << tplus << std::endl;
    /*----------------------------------*/
    my_rit += 1;
    rit += 1;
    bool tm = ((&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1))); //!!!!!!!!!!!!
        std::cout << "operator+= " << tm << std::endl;
    /*----------------------------------*/
    my_rit -= 1;
    rit -= 1;
    bool ts = ((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
        std::cout << "operator-= " << ts << std::endl;
    /*----------------------------------*/
    bool tr = (((my_rit[0] = 5) == 5) && (rit[0] == 5));
        std::cout << "operator[] " << tr << std::endl;
    /*----------------------------------*/
    ++my_rit; // I incremented here to make sure that the object changes
    ++rit;
    bool te = (&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1));
        std::cout << "operator++ " << te << std::endl;
    /*----------------------------------*/
    --my_rit; // I incremented here to make sure that the object changes
    --rit;
    bool tw = ((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
        std::cout << "operator-- " << tw << std::endl;
    /*----------------------------------*/
    bool tq = ((&(*(2 + my_rit)) == &(*(1 + my_rit1))) && (&(*(2 + rit)) == &(*(1 + rit_1))));
        std::cout << "+ operator (n + rit) " << tq << std::endl;
    /*----------------------------------*/
    // bool tf = (((my_rit - my_rit1) == (rit - rit_1)) && ((my_rit1 - my_rit) == (rit_1 - rit)));
    //     std::cout << " - operator (rit1 - rit) " << tf << std::endl;
    /*----------------------------------*/
    // std::reverse_iterator<std::vector<int>::iterator> tmp(rit++);
    // ft::reverse_iterator<std::vector<int>::iterator> my_tmp(my_rit++);
    // bool pl = ((&(*tmp) == &(*(--rit))) && (&(*my_tmp) == &(*(--my_rit))));
    //     std::cout << " rit++ operator " << pl << std::endl;
    /*----------------------------------*/
    // std::reverse_iterator<std::vector<int>::iterator> tmp(rit--);
    // ft::reverse_iterator<std::vector<int>::iterator> my_tmp(my_rit--);
    // bool po = ((&(*tmp) == &(*(++rit))) && (&(*my_tmp) == &(*(++my_rit))));
    //     std::cout << " rit-- operator " << po << std::endl;
    /*----------------------------------*/
    // std::vector<char> v(10);
    // std::string res, my_res;
    // std::reverse_iterator<std::vector<char>::iterator> start(v.end()), end(v.begin());
    // ft::reverse_iterator<std::vector<char>::iterator> my_start(v.end()), my_end(v.begin());
    // for (size_t i = 0; i < 10; ++i)
    //     v[i] = '0' + i;
    // while (start != end)
    //     res.push_back(*start++);
    // while (my_start != my_end)
    //     my_res.push_back(*my_start++);
    // bool pk = (res == my_res); std::cout << " *rit++ test " << pk << std::endl;
    /*----------------------------------*/



    
    /*----------------------------------*/
    /*----------------------------------*/
    //*  the function decreases a copy of its base iterator and returns the result of dereferencing it.

    return 0;
}
