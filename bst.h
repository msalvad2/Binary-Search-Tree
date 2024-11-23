//Miguel Salvador
//The data structure used will be a binary search tree

#include <iostream>
#include <cctype>
#include <cstring>

#include "product.h"


class table
{
    public:
    table();
    ~table();
    int insert(product & new_product);
    int remove(char * name, product & new_product);
    int retrieve(char * name, product & new_product);
    int display_all();
    int display_range(int low, int high);
    int height();

    private:
    product_node * root;
    int insert(product_node * & root, product & new_product);
    int display_all(product_node * root);
    int remove(product_node * & root, char * name, product & new_product);
    int IOS(product_node * & root, char * name, product & new_product); 
    int retrieve(char * name, product & new_product, product_node * root);
    int display_range(int low, int high, product_node * root);
    int height(product_node * root);
};




