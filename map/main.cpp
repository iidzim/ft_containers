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
// 	// 13 - 33 - 39 - 40 - 53
// 	t.remove_(13);
// 	t.remove_(33);
// 	t.remove_(39);
// 	t.remove_(40);
// 	t.remove_(45);
// 	t.remove_(53);
// 	// std::cout << "size = " << t.size() << std::endl << std::endl;
// 	t.print_parent(t._root);
// 	t.display(t._root);
// }

int main(void){

	// std::map<int, int> m;
	// std::pair<int, int> p33(33, 33);
	// std::pair<int, int> p13(13, 13);
	// std::pair<int, int> p53(53, 53);
 	// std::pair<int, int> p11(11, 11);
	// std::pair<int, int> p61(61, 61);
	// std::pair<int, int> p21(21, 21);
	// std::map<int, int>::iterator it = m.begin();

	// m.insert(it, p33);
	// m.insert(p13);
	// m.insert(p53);
	// m.insert(p11);
	// m.insert(p21);

    // std::cout << m[33] << std::endl;
    // std::cout << m[21] << std::endl;
	// std::cout << it << std::endl;

{
	ft::map<int, std::string> m;
	ft::map<int, std::string>::biterator it, ite, eq;
	ft::pair<int, std::string> p33(33, "A");
	ft::pair<int, std::string> p13(13, "B");
	ft::pair<int, std::string> p53(53, "C");
 	ft::pair<int, std::string> p11(11, "D");
 	ft::pair<int, std::string> p64(64, "Z");
 	ft::pair<int, std::string> p40(40, "E");
 	ft::pair<int, std::string> p39(39, "F");
 	ft::pair<int, std::string> p45(45, "G");

	m.insert(p33);
	m.insert(p13);
	m.insert(p53);
	m.insert(p11);
	m.insert(p64);
	m.insert(p40);
	m.insert(p39);
	m.insert(p45);
	m.get_tree().display(m.get_tree()._root);

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
	// // ++it;
	// std::cout << it->first << std::endl;

	// std::cout << "*****************\n";

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

	// ft::map<int, std::string>::biterator cp(ite);
	// eq = ite;
	// std::cout << eq->first << std::endl;
	// std::cout << cp->first << std::endl;

	// ft::map<int, std::string>::reverse_iterator rit = m.rbegin();
	// std::cout << rit->first << std::endl;
	// ft::map<int, std::string>::reverse_iterator rite = m.rend();
	// --rite;
	// std::cout << rite->first << std::endl;
	// --rite;
	// std::cout << rite->first << std::endl;
	// --rite;
	// std::cout << rite->first << std::endl;


	// ft::map<int, std::string>::biterator itlow, itup;
	// itlow = m.lower_bound(13);
	// std::cout << "lower_bound --> " << itlow->first << std::endl;
	// itup = m.upper_bound(53);
	// std::cout << "upper_bound --> " << itup->first << std::endl;

	// std::cout << "size before = " << m.size() << std::endl;
	// m.erase(itlow, itup);
	// std::cout << "size after = " << m.size() << std::endl;

	// m.erase(13);
	// m.erase(64);
	// std::cout << "\n///////////////////////////////////////////////////\n";
	// m.get_tree().display(m.get_tree()._root);
	// m.erase(13);



	// ft::map<int, std::string>::biterator itf = m.find(45);
	// std::cout << "find ->----- " << itf->first << std::endl;
	// std::cout << "count = " << m.count(33) << std::endl;

	// m.get_tree().display(m.get_tree()._root);

	ft::pair<ft::map<int , std::string>::biterator, ft::map<int, std::string>::biterator> p;
	p = m.equal_range(53);
	std::cout << p.first->first << " - " << p.first->second << std::endl;
	std::cout << p.second->first << " - " << p.second->second << std::endl;

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

	// std::map<int, std::string>::iterator itlow, itup;
	// itlow = m.lower_bound(13);
	// std::cout << "lower_bound = " << itlow->first << std::endl;
	// itup = m.upper_bound(53);
	// std::cout << "upper_bound = " << itup->first << std::endl;

	// std::cout << "size before = " << m.size() << std::endl;
	// m.erase(itlow, itup);
	// std::cout << "size after = " << m.size() << std::endl;
	// m.erase(13);

	// m.erase(itlow, itup);
// 	std::cout << m.size() << std::endl;

// 	std::map<int, std::string>::iterator itf = m.find(45);
// 	std::cout << "find ->----- " << itf->first << std::endl;
// 	std::cout << "count = " << m.count(33) << std::endl;


	std::pair<std::map<int , std::string>::iterator, std::map<int, std::string>::iterator> p;
	p = m.equal_range(53);
	std::cout << p.first->first << " - " << p.first->second << std::endl;
	std::cout << p.second->first << " - " << p.second->second << std::endl;

}


	return (0);
}