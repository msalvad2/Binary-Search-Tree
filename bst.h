//Miguel Salvador, msalvad2@pdx.edu, Program #4, 12/2/2024
//The data structure used will be a binary search tree
//In this file it contains all the functions the bst will have and
//The libraries we will use

#include <iostream>
#include <cctype>
#include <cstring>
#include <algorithm>
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
    int display_range(float low, float high);
    int height();

    private:
    product_node * root;
    int destructor(product_node *& root);
    int insert(product_node * & root, product & new_product);
    int display_all(product_node * root);
    int remove(product_node * & root, char * name, product & new_product);
    int IOS(product_node * & root, char * name, product & new_product); 
    int retrieve(char * name, product & new_product, product_node * root);
    int display_range(product_node * root, float low, float high);
    int height(product_node * root);
};




