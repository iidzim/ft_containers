#include "map.hpp"

#include <map>
#include <iterator>

// int main(void){
// 	ft::pair<int, std::string> p33(33, "ok");
// 	ft::pair<int, std::string> p13(13, "ok");
// 	ft::pair<int, std::string> p53(53, "ok");
// 	ft::pair<int, std::string> p11(11, "ok");
// 	ft::pair<int, std::string> p61(61, "ok");
// 	ft::pair<int, std::string> p21(21, "ok");
// 	ft::pair<int, std::string> p8(8, "ok");
// 	ft::pair<int, std::string> p9(9, "ok");
// 	ft::pair<int, std::string> p23(23, "ok");

// 	ft::avltree<ft::pair<int, std::string> > t;
// 	t.insert(p33);
// 	t.insert(p13);
// 	t.insert(p53);
// 	t.insert(p11);
// 	t.insert(p61);
// 	t.insert(p21);
// 	t.insert(p8);
// 	t.insert(p9);
// 	t.insert(p23);
// 	t.display(t._root);
// 	// std::cout << "size = " << t.size() << std::endl;
// 	std::cout << "\n*************\n";
// 	// std::cout << std::boolalpha;
// 	// std::cout << t.exist(p61) << std::endl;
// 	t.remove(8);
// 	t.remove(11);
// 	// t.remove(21);
// 	// t.remove(61);
// 	// t.remove(53);
// 	// t.remove(23);
// 	// t.remove(13);
// 	// t.remove(33);
// 	// t.remove(9);
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

	it = m.begin();
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;


	ite = m.end();
	--ite;
	std::cout << ite->first << std::endl;
	--ite;
	std::cout << ite->first << std::endl;
	--ite;
	std::cout << ite->first << std::endl;
	--ite;
	std::cout << ite->first << std::endl;
	--ite;
	std::cout << ite->first << std::endl;
	--ite;
	std::cout << ite->first << std::endl;
	--ite;
	std::cout << ite->first << std::endl;
	--ite;
	std::cout << ite->first << std::endl;

	ft::map<int, std::string>::biterator cp(ite);
	eq = ite;
	std::cout << eq->first << std::endl;
	std::cout << cp->first << std::endl;

}
// {
// 	ft::map<std::string, std::string> m;
// 	ft::map<std::string, std::string>::biterator it;
// 	ft::pair<std::string, std::string> p33("a", "b");


// 	m.insert(p33);
// 	std::cout << m["a"] << std::endl;

// 	// it = m.begin();
// 	// it = m.end();

// }

// {
// 	std::map<int, int> m;
// 	std::map<int, int>::iterator it;
// 	std::pair<int, int> p33(33, 33);
// 	std::pair<int, int> p13(13, 13);
// 	std::pair<int, int> p53(53, 53);
//  	std::pair<int, int> p11(11, 11);

// 	it = m.begin();
// 	m.insert(p33);
// 	m.insert(p13);
// 	m.insert(p53);
// 	m.insert(p11);
// 	std::cout << m[33] << std::endl;
// 	std::cout << m[13] << std::endl;
// 	std::cout << m[53] << std::endl;

// 	// it = m.end();

// }


	return (0);
}