#include "map_v2.hpp"

#include <map>
#include <iterator>

// int main(void){
// 	// ft::pair<int, std::string> p33(33, "ok");
// 	// ft::pair<int, std::string> p13(13, "ok");
// 	// ft::pair<int, std::string> p53(53, "ok");
// 	// ft::pair<int, std::string> p11(11, "ok");
// 	// ft::pair<int, std::string> p61(61, "ok");
// 	// ft::pair<int, std::string> p21(21, "ok");
// 	// ft::pair<int, std::string> p8(8, "ok");
// 	// ft::pair<int, std::string> p9(9, "ok");
// 	// ft::pair<int, std::string> p23(23, "ok");
// 	ft::pair<int, std::string> p33(33, "A");
// 	ft::pair<int, std::string> p13(13, "B");
// 	ft::pair<int, std::string> p53(53, "C");
//  	ft::pair<int, std::string> p11(11, "D");
//  	ft::pair<int, std::string> p64(64, "Z");
//  	ft::pair<int, std::string> p40(40, "E");
//  	ft::pair<int, std::string> p39(39, "F");
//  	ft::pair<int, std::string> p45(45, "G");
// 	ft::avltree<ft::pair<int, std::string> > t;
// 	// t.insert(p33);
// 	// t.insert(p13);
// 	// t.insert(p53);
// 	// t.insert(p11);
// 	// t.insert(p61);
// 	// t.insert(p21);
// 	// t.insert(p8);
// 	// t.insert(p9);
// 	// t.insert(p23);
// 	// 	m.insert(p33);
// 	t.insert(p33);
// 	t.insert(p13);
// 	t.insert(p53);
// 	t.insert(p11);
// 	t.insert(p64);
// 	t.insert(p40);
// 	t.insert(p39);
// 	t.insert(p45);
// 	t.display(t._root);
// 	// std::cout << "size = " << t.size() << std::endl;
// 	std::cout << "\n*************\n";
// 	// std::cout << std::boolalpha;
// 	// std::cout << t.exist(p61) << std::endl;
// 	// t.remove_(13);
// 	// t.remove_(33);
// 	// t.remove_(39);
// 	// t.remove_(40);
// 	// t.remove_(45);
// 	// t.remove_(53);
// 	// std::cout << "size = " << t.size() << std::endl << std::endl;
	// t.print_parent(t._root);
// 	// t.display(t._root);

// 	ft::avltree<ft::pair<int, std::string> > test(t);
// 	test.display(test._root);

// }

int main(void){

{
	// ft::map<int, std::string> m;
	// // // std::cout << std::boolalpha;
	// // // // std::cout << "map is empty ? " << m.empty() << " | size = " << m.size() << std::endl;
	// ft::map<int, std::string>::biterator it, ite, eq;
	// ft::pair<int, std::string> p33(33, "A");
	// ft::pair<int, std::string> p13(13, "B");
	// ft::pair<int, std::string> p53(53, "C");
 	// ft::pair<int, std::string> p11(11, "D");
 	// ft::pair<int, std::string> p40(40, "E");
 	// ft::pair<int, std::string> p39(39, "F");
 	// ft::pair<int, std::string> p45(45, "G");
 	// ft::pair<int, std::string> p64(64, "Z");
 	// ft::pair<int, std::string> p14(14, "X");

	// m.insert(p33);
	// m.insert(p13);
	// m.insert(p53);
	// m.insert(p11);
	// m.insert(p64);
	// m.insert(p40);
	// m.insert(p39);
	// m.insert(p45);
	// // std::cout << "m----------------------------\n";
	// m.get_tree().display(m.get_tree()._root);
	// m.get_tree().print_parent(m.get_tree()._root);


	//* opertaor[]
	// std::cout << m[13] << " - " << m[39] << " - " << m[64] << std::endl;

	//* max_size & empty & size
	// std::cout << m .max_size() << std::endl;
	// std::cout << std::boolalpha;
	// std::cout << "map is empty ? " << m.empty() << " | size = " << m.size() << std::endl;


	// ft::map<int, std::string>::const_biterator cit = m.begin();
	// std::cout << cit->first << std::endl;


	// //* insert(range)
	// ft::map<int, std::string>::biterator ot = m.begin(), ote = m.end();
	// ++ot;
	// ++ot;
	// --ote;
	// --ote;
	// --ote;
	// std::cout << ot->first << std::endl;
	// std::cout << ote->first << std::endl;
	// ft::map<int, std::string> test(ot, ote);
	// std::cout << "test----------------------------\n";
	// test.get_tree().display(test.get_tree()._root);

	// if (test == m)
	// 	std::cout << "equal" << std::endl;
	// else
	// 	std::cout << "not equal" << std::endl;

	//! assignment operator
	// ft::map<int, std::string> test2 = m;
	// test2.get_tree().display(test2.get_tree()._root);

	//! copy constructor
	// std::cout << "---------copy constructor-------------\n";
	// ft::map<int, std::string> test1(m);
	// // ft::map<int, std::string> test1(test);
	// test1.get_tree().display(test1.get_tree()._root);
	// test1.get_tree().print_parent(test1.get_tree()._root);

	
	// std::cout << " ** " << it->first << std::endl;
	// ++it;
	// std::cout << " ** " << it->first << std::endl;

	// for (it = test1.begin() ;it != test1.end() ; it++)
	// 	std::cout << it->first << " - ";
	// std::cout << std::endl;

	//* insert with hint
	// m.insert(ote, p14);
	// m.get_tree().display(m.get_tree()._root);

	//* swap
	// ft::map<int, std::string> n;
	// ft::pair<int, std::string> p3(3, "A");
	// ft::pair<int, std::string> p1(1, "B");
	// ft::pair<int, std::string> p5(5, "C");
 	// ft::pair<int, std::string> p7(7, "D");
	// n.insert(p3);
	// n.insert(p1);
	// n.insert(p5);
	// n.insert(p7);
	// std::cout << "n----------------------------\n";
	// n.get_tree().display(n.get_tree()._root);
	// m.swap(n);
	// // swap(m, n);
	// std::cout << "swap\nm*************************\n";
	// m.get_tree().display(m.get_tree()._root);
	// std::cout << "test*************************\n";
	// n.get_tree().display(n.get_tree()._root);

	//* begin()
	// it = m.begin();
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// std::cout << it->first << std::endl;
	// ++it;
	// ++it;
	// std::cout << it->first << std::endl;

	// std::cout << "*****************\n";

	//* end()
	// ite = m.end();
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// std::cout << ite->first << std::endl;
	// --ite;
	// --ite;
	// std::cout << ite->first << std::endl;

	//* iterator copy constructor - assignment operator
	// ft::map<int, std::string>::biterator cp(ite);
	// eq = ite;
	// std::cout << eq->first << std::endl;
	// std::cout << cp->first << std::endl;

	///* rbegin() & rend()
	// ft::map<int, std::string>::reverse_iterator rit = m.rbegin();
	// std::cout << rit->first << std::endl;
	// ft::map<int, std::string>::reverse_iterator rite = m.rend();
	// --rite;
	// std::cout << rite->first << std::endl;
	// --rite;
	// std::cout << rite->first << std::endl;
	// --rite;
	// std::cout << rite->first << std::endl;

	//* lower_bound & upper bound
	// ft::map<int, std::string>::biterator itlow, itup;
	// itlow = m.lower_bound(13);
	// std::cout << "lower_bound --> " << itlow->first << std::endl;
	// itup = m.upper_bound(53);
	// std::cout << "upper_bound --> " << itup->first << std::endl;

	//* erase
	// std::cout << "size before = " << m.size() << std::endl;
	// m.erase(itlow, itup);
	// std::cout << "size after = " << m.size() << std::endl;
	// m.erase(13);
	// m.erase(64);
	// m.erase(itlow);
	// m.erase(itup);

	//* find
	// ft::map<int, std::string>::biterator itf = m.find(45);
	// std::cout << "find ->----- " << itf->first << std::endl;
	// std::cout << "count = " << m.count(33) << std::endl;

	//* equal range
	// ft::pair<ft::map<int , std::string>::biterator, ft::map<int, std::string>::biterator> p;
	// p = m.equal_range(53);
	// std::cout << p.first->first << " - " << p.first->second << std::endl;
	// std::cout << p.second->first << " - " << p.second->second << std::endl;

	// m.get_tree().display(m.get_tree()._root);

	//* reverse iterator
	// ft::map<int, std::string> k;
	// ft::pair<int, std::string> p1(23, "A");
	// ft::pair<int, std::string> p2(31, "A");
	// ft::pair<int, std::string> p3(13, "A");

	// k.insert(ft::make_pair(23, "a"));
	// k.insert(p2);
	// k.insert(p3);

	// ft::map<int, std::string>::reverse_iterator kite(k.end());
    // ft::map<int, std::string>::const_reverse_iterator cit, cri(k.end());
	// cit = kite;
	// if (kite->first == cit->first && kite->first == cri->first)
	// 	std::cout << "ok\n";

	//* --it operator TLE - segfault
	// ft::map<int, std::string> ft_m;
    // for (size_t i = 0; i < 10; ++i)
    //     ft_m.insert(ft::make_pair(i, "value"));
	// ft_m.get_tree().display(ft_m.get_tree()._root);
	// ft_m.get_tree().print_parent(ft_m.get_tree()._root);
	// ft::map<int, std::string>::biterator ft_it = --ft_m.end();
    // for (; ft_it != ft_m.begin(); --ft_it)
    //     std::cout << ft_it->first << " - ";
	// std::cout << std::endl;

	//!!! base function
	// std::map<int, std::string> m;
    // for (size_t i = 0; i < 10; ++i)
    //     m.insert(std::make_pair(i, "value"));
    // std::reverse_iterator<std::map<int, std::string>::iterator> rit(m.end()), rit_1(--m.end());
    // ft::reverse_iterator<std::map<int, std::string>::iterator> my_rit(m.end()), my_rit1(--m.end());
	// // (rit->first == (rit_1.base()->first)) && (my_rit->first == my_rit1.base()->first);
	// std::cout << "\n" << my_rit->first << " - " << my_rit1.base()->first << std::endl;
    // std::cout << "\n" << rit->first << " - " << rit_1.base()->first << std::endl;

	//* empty constructor
	// ft::map<int, std::string> my_m;
    // for (int i = 0; i < 1e6; ++i)
    //     my_m.insert(ft::make_pair(i, "fill constructor test"));
	// std::cout << my_m[1] << " - " << my_m[4] << std::endl;
	// std::cout << "done1\n";
	// ft::map<int, std::string> my_mm;
    // std::map<int, std::string> mm;
    // for (int i = 0; i < 10; i++){
    //     my_mm.insert(ft::make_pair(i, "Hello"));
    //     mm.insert(std::make_pair(i, "Hello"));
	// }
	// // std::cout << my_mm[1] << " - " << my_mm[4] << std::endl;
	// std::string res, my_res;
    // /*---------------------------------------------------------*/
    // for (std::map<int, std::string>::iterator it = mm.begin(); it != mm.end(); ++it) // fill res from std::map
    //     res += it->second;
    // for (ft::map<int, std::string>::biterator it = my_mm.begin(); it != my_mm.end(); ++it) // fill res from std::map
    //     my_res += it->second;
	// std::cout << my_res << std::endl;
	// if (res == my_res)
	// 	std::cout << "ok\n";

	//! Constructors with costum compare
    // ft::map<char, int> m;
    // for (size_t i = 97; i < 110; i++){
    //     m[i - 97] = i;
	// 	std::cout << m[i - 97] << " - ";
	// }
	// std::cout << std::endl;
	// // std::cout << m[100] << std::endl;
	// // // m.get_tree().display(m.get_tree()._root);
    // // ft::map<char, int> c(m);
    // ft::map<char, int>::biterator it = m.begin(), ite = m.end();
	// // std::cout << "|" << it->first << "|" << std::endl;
	// // for (size_t i = 97; i < 110; i++)
	// // 	std::cout << m[i - 97] << " - ";
	// // std::cout << std::endl;

	// // std::cout << "|" << it->first << "|" << std::endl;


	// for (; it != ite; it++)
	// 	std::cout << it->second << " - ";
	// std::cout << std::endl;


	//! operator []
	// ft::map<int, std::string> o;
	// int i = 0;
	// for (; i < 10; i++)
	// 	o.insert(ft::make_pair(i, "ok"));
	// for (; it != ite; it++)
		// std::cout << it->first << " - " << it->second << std::endl;
	// std::cout << "*****\n";
	// for (int i = 0; i < 15; i++)
	// o[101] = "ko";
	// std::cout <<"|" << o[101] << "|" << std::endl;
	// std::cout << "|" << o[12] << "|" << std::endl;
	// std::cout << o.size() << std::endl;
	// ft::map<int, std::string>::biterator it = o.begin(), ite = o.end();
	// for (it = o.begin(); it != ite; it++)
	// 	std::cout << it->first << " - " << it->second << std::endl;


	std::map<int, std::string> m1;
    std::map<int, std::string> m2;
    ft::map<int, std::string> ft_m1;
    ft::map<int, std::string> ft_m2;
    // for (int i = 0; i < 1e6; ++i)
    for (int i = 0; i < 10; ++i)
    {
        m1.insert(std::make_pair(i, "string1"));
        m2.insert(std::make_pair(i, "string2"));
        ft_m1.insert(ft::make_pair(i, "string1"));
        ft_m2.insert(ft::make_pair(i, "string2"));
    }

    std::cout << m1.size() << " - " << m2.size() << std::endl;
    std::cout << ft_m1.size() << " - " << ft_m2.size() << std::endl;    
	std::cout << "START--------------\n";

	ft_m1.get_tree().display(ft_m1.get_tree()._root);
	ft_m2.get_tree().display(ft_m2.get_tree()._root);

    ft_m1 = ft_m2;
    std::cout << "-> " << m1.size() << " - " << m2.size() << std::endl;
    std::cout << "-> " << ft_m1.size() << " - " << ft_m2.size() << std::endl;
	std::cout << ft_m1.empty() << std::endl;



}

// std::cout << "-------------------------------------------------------\n";

// {
	// std::map<int, std::string> m;
	// std::map<int, std::string>::iterator it, ite, eq;
	// std::pair<int, std::string> p33(33, "A");
	// std::pair<int, std::string> p13(13, "B");
	// std::pair<int, std::string> p53(53, "C");
 	// std::pair<int, std::string> p11(11, "D");
 	// std::pair<int, std::string> p64(64, "Z");
 	// std::pair<int, std::string> p40(40, "E");
 	// std::pair<int, std::string> p39(39, "F");
 	// std::pair<int, std::string> p45(45, "G");

	// m.insert(p33);
	// m.insert(p13);
	// m.insert(p53);
	// m.insert(p11);
	// m.insert(p64);
	// m.insert(p40);
	// m.insert(p39);
	// m.insert(p45);

	// std::map<int, std::string>::reverse_iterator rit = m.rbegin();
	// std::cout << "--> " << rit->first << std::endl;
	// std::map<int, std::string>::reverse_iterator rite = m.rend();
	// --rite;
	// std::cout << "--> " << rite->first << std::endl;

	//* lower_bound and upper_bound
	// std::map<int, std::string>::iterator itlow, itup;
	// itlow = m.lower_bound(13);
	// std::cout << "lower_bound = " << itlow->first << std::endl;
	// itup = m.upper_bound(53);
	// std::cout << "upper_bound = " << itup->first << std::endl;

	//* erase
	// std::cout << "size before = " << m.size() << std::endl;
	// m.erase(itlow, itup);
	// std::cout << "size after = " << m.size() << std::endl;
	// m.erase(13);
	// m.erase(64);
	// m.erase(itlow);
	// m.erase(itup);
	// std::cout << m.size() << std::endl;

	//* find
	// std::map<int, std::string>::iterator itf = m.find(45);
	// std::cout << "find ->----- " << itf->first << std::endl;
	// std::cout << "count = " << m.count(33) << std::endl;

	//* equal range
	// std::pair<std::map<int , std::string>::iterator, std::map<int, std::string>::iterator> p;
	// p = m.equal_range(53);
	// std::cout << p.first->first << " - " << p.first->second << std::endl;
	// std::cout << p.second->first << " - " << p.second->second << std::endl;


	//* reverse iterator
	// std::map<int, std::string> k;
	// std::pair<int, std::string> p1(23, "A");
	// std::pair<int, std::string> p2(31, "A");
	// std::pair<int, std::string> p3(13, "A");

	// k.insert(std::make_pair(23, "a"));
	// k.insert(p2);
	// k.insert(p3);

	// std::map<int, std::string>::reverse_iterator kite(k.end());
    // std::map<int, std::string>::const_reverse_iterator cit, cri(k.end());
	// cit = kite;
	// if (kite->first == cit->first && kite->first == cri->first)
	// 	std::cout << "ok\n";

	// //! operator []
	// std::map<int, std::string> o;
	// for (int i = 0; i < 10; i++)
	// 	o.insert(std::make_pair(i, "ok"));
	// std::map<int, std::string>::iterator it = o.begin(), ite = o.end();
	// // for (; it != ite; it++)
	// 	// std::cout << it->first << " - " << it->second << std::endl;
	// // std::cout << "*****\n";
	// // for (int i = 0; i < 15; i++)
	// 	o[12] = "ko";
	// std::cout << "|" << o[12] << "|" << std::endl;
	// // std::cout << o.size() << std::endl;
	// for (it = o.begin(); it != ite; it++)
	// 	std::cout << it->first << " - " << it->second << std::endl;

// }


	return (0);
}