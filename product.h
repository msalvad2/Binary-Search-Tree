//The data type

#include <iostream>
#include <cstring>
#include <cctype>

class product
{
    public:
    product();
    ~product();
    int copy(product & new_product);
    int display();

    private:

    char * title;
    char * description;
    char * category;
    char * type;
    float price;
    int quantity;
    int ID;
    char * shop_name;

    
};

struct product_node
{
    product a_product;
    product_node *next;
};
