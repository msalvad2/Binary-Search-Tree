//The data type

#include <iostream>
#include <cstring>
#include <cctype>

const int SIZE{500};

class product
{
    public:
    product();
    product(
    char * title,
    char * description,
    char * category,
    char * type,
    float price,
    int quantity,
    int ID,
    char * shop_name
    );
    ~product();
    int copy(product & new_product);
    int display();//Displays the members in an object
    int compare(product & new_product);//Compares when sending an obj
    int compare_name(char *name);//Compares when sending a name

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
    product_node *left;
    product_node *right;
};
