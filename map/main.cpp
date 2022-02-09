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
// 	t.display(t.get_root());
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
// 	t.print_parent(t.get_root());
// 	t.display(t.get_root());
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
	ft::map<int, int> m;
	ft::map<int, int>::biterator it;
	ft::pair<int, int> p33(33, 33);


	m.insert(p33);

}


	return (0);
}