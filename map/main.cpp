#include "map.hpp"

int main(void){
    ft::avltree<int> t;
    t.insert(40);
    t.insert(20);
    t.insert(30);
    t.insert(60);
    t.insert(50);
    t.insert(10);
    t.display(t._root);
}