#include "map.hpp"

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
// 	// t.print_parent(t._root);
// 	// t.display(t._root);

// 	ft::avltree<ft::pair<int, std::string> > test(t);
// 	test.display(test._root);

// }

int main(void){

{
	ft::map<int, std::string> m;
	std::cout << std::boolalpha;
	// std::cout << "map is empty ? " << m.empty() << " | size = " << m.size() << std::endl;
	ft::map<int, std::string>::biterator it, ite, eq;
	ft::pair<int, std::string> p33(33, "A");
	ft::pair<int, std::string> p13(13, "B");
	ft::pair<int, std::string> p53(53, "C");
 	ft::pair<int, std::string> p11(11, "D");
 	ft::pair<int, std::string> p40(40, "E");
 	ft::pair<int, std::string> p39(39, "F");
 	ft::pair<int, std::string> p45(45, "G");
 	ft::pair<int, std::string> p64(64, "Z");

 	ft::pair<int, std::string> p14(14, "X");

	m.insert(p33);
	m.insert(p13);
	m.insert(p53);
	m.insert(p11);
	m.insert(p64);
	m.insert(p40);
	m.insert(p39);
	m.insert(p45);
	std::cout << "m----------------------------\n";
	m.get_tree().display(m.get_tree()._root);


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
	// ft::map<int, std::string> test1(m);
	// // ft::map<int, std::string> test1(test);
	// test1.get_tree().display(test1.get_tree()._root);

	//* insert with hint
	// m.insert(ote, p14);
	// m.get_tree().display(m.get_tree()._root);

	//* swap
	ft::map<int, std::string> n;
	ft::pair<int, std::string> p3(3, "A");
	ft::pair<int, std::string> p1(1, "B");
	ft::pair<int, std::string> p5(5, "C");
 	ft::pair<int, std::string> p7(7, "D");
	n.insert(p3);
	n.insert(p1);
	n.insert(p5);
	n.insert(p7);
	std::cout << "n----------------------------\n";
	n.get_tree().display(n.get_tree()._root);
	m.swap(n);
	// swap(m, n);
	std::cout << "swap\nm*************************\n";
	m.get_tree().display(m.get_tree()._root);
	std::cout << "test*************************\n";
	n.get_tree().display(n.get_tree()._root);

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
}

std::cout << "-------------------------------------------------------\n";

{
	std::map<int, std::string> m;
	std::map<int, std::string>::iterator it, ite, eq;
	std::pair<int, std::string> p33(33, "A");
	std::pair<int, std::string> p13(13, "B");
	std::pair<int, std::string> p53(53, "C");
 	std::pair<int, std::string> p11(11, "D");
 	std::pair<int, std::string> p64(64, "Z");
 	std::pair<int, std::string> p40(40, "E");
 	std::pair<int, std::string> p39(39, "F");
 	std::pair<int, std::string> p45(45, "G");

	m.insert(p33);
	m.insert(p13);
	m.insert(p53);
	m.insert(p11);
	m.insert(p64);
	m.insert(p40);
	m.insert(p39);
	m.insert(p45);

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

}


	return (0);
}