#include "avltree.hpp"

int main(void){
    ft::pair<int, std::string> p33(33, "ok");
    ft::pair<int, std::string> p13(13, "ok");
    ft::pair<int, std::string> p53(53, "ok");
    ft::pair<int, std::string> p11(11, "ok");
    ft::pair<int, std::string> p61(61, "ok");
    ft::pair<int, std::string> p21(21, "ok");
    ft::pair<int, std::string> p8(8, "ok");
    ft::pair<int, std::string> p9(9, "ok");
    ft::pair<int, std::string> p23(23, "ok");

    ft::avltree<ft::pair<int, std::string> > t;
    t.insert(p33);
    t.insert(p13);
    t.insert(p53);
    t.insert(p11);
    t.insert(p61);
    t.insert(p21);
    t.insert(p8);
    t.insert(p9);
    t.insert(p23);
    t.display(t.get_root());
    // std::cout << "size = " << t.size() << std::endl;
    std::cout << "\n*************\n";
    // std::cout << std::boolalpha;
    // std::cout << t.exist(p61) << std::endl;
    // t.remove(p8);
    // t.remove(p11);
    // t.remove(p21);
    // t.remove(p61);
    // t.remove(p53);
    // t.remove(p23);
    // t.remove(p13);
    // t.remove(p33);
    // t.remove(p9);
    // std::cout << "size = " << t.size() << std::endl << std::endl;
    t.print_parent(t.get_root());
    // t.display(t.get_root());
}

/*
inorder(root->left);
        printf("Node : %d, ", root->key);
        if (root->parent == NULL)
          printf("Parent : NULL \n");
        else
          printf("Parent : %d \n", root->parent->key);
        inorder(root->right);
*/