#include "map.hpp"

int main(void){
    ft::avltree<int> t;
    // t.insert(40);
    // t.insert(20);
    // t.insert(30);
    // t.insert(60);
    // t.insert(50);
    // t.insert(10);
    t.insert(33);
    t.insert(13);
    t.insert(53);
    t.insert(11);
    t.insert(61);
    t.insert(21);
    t.insert(8);
    t.insert(9);
    t.display(t.get_root());
    std::cout << "\n\n*************\n\n";
    t.remove(11);
    t.display(t.get_root());
}
