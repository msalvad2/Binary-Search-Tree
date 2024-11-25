//Hello
#include "product.h"
using namespace std;

product::product()//The normal constructor initializes everything to 0
{
    title = nullptr;
    description = nullptr;
    category = nullptr;
    type = nullptr;
    price = 0.0;
    quantity = 0;
    ID = 0;
    shop_name = nullptr;
}
//The constructor below sets the object filled with data provided already
product::product(char * new_title, char* new_description, char *new_category, char * new_type,
                 float new_price, int new_quantity, int new_ID, char* new_shop_name)
{
   title = new char[strlen(new_title) + 1]; //title is the class member, new_title is the title the user provided
                                            //We dynamically allocated the exact size
   strcpy(title, new_title);//We then copy the contents the user provided to the data member
                            //We will do the same for the rest of the members
   description = new char[strlen(new_description) + 1];
   strcpy(description, new_description);

   category = new char[strlen(new_category) + 1];
   strcpy(category, new_category);

   type = new char[strlen(new_type) + 1];
   strcpy(type, new_type);

   price = new_price;//Since the 3 members below are floats/ints we just set them equal to each other

   quantity = new_quantity;

   ID = new_ID;

   shop_name = new char[strlen(new_shop_name) + 1];
   strcpy(shop_name, new_shop_name);


}
product::~product()
{
    if(title) delete[] title;
    if(description) delete[] description;
    if(category) delete[] category;
    if(type) delete[] type;
    price = 0;
    quantity = 0;
    ID = 0;
    if(shop_name) delete[] shop_name;
}
//This function will display the contents in the obj
int product::display()
{
    if(!title) return -1;

   cout <<"Title: " << title << endl;
   cout <<"Description: " << description << endl;
   cout <<"Category: " << category << endl;
   cout <<"Type " << type << endl;
   cout <<"Price: " << price << endl;
   cout <<"Quantity: " << quantity << endl;
   cout <<"ID: " << ID << endl;
   cout <<"Shop Name: " << shop_name << endl;

   return 1;

}
//This function will copy info from user product to product destination
int product::copy(product & new_product)
{
    //When copying information it's important to clear the data
    if(title) delete[] title;
    if(description) delete[] description;
    if(category) delete[] category;
    if(type) delete[] type;
    if(shop_name) delete[] shop_name;


    title = new char[strlen(new_product.title) + 1];
    strcpy(title, new_product.title);

    description = new char[strlen(new_product.description) + 1];
    strcpy(description, new_product.description);

    category = new char[strlen(new_product.category) + 1];
    strcpy(category, new_product.category);

    type = new char[strlen(new_product.type) + 1];
    strcpy(type, new_product.type);

    price = new_product.price;

    quantity = new_product.quantity;

    ID = new_product.ID;

    shop_name = new char[strlen(new_product.shop_name) + 1];
    strcpy(shop_name, new_product.shop_name);

    return 1;
}

int product::compare(product & new_product)
{
    int num = strcmp(title, new_product.title);//Strcmp will return a value

    if(num > 0) return -1;//means member function is greater than argument(We must go left)
    if(num < 0) return 1;//means argument(new_product.title) is greater (We must go right)

    return 0;
}
int product::compare_name(char *name)//Compares when sending a name
{
    int num = strcmp(title, name);
    if(num > 0) return -1;//Means go left
    if(num < 0) return 1;//Means go right

    return 0;//This means they are the same
}
bool product::range_compare(float low, float high)
{
  if( price > low && price < high)
      return true;
    return false;

}
