//Miguel Salvador, msalvad2@pdx.edu, Program #4, 12/2/2024
//This file contains the implemenations of the bst so it contains
//functions that'll help us add, remove, insert, display, etc.
#include "bst.h"
using namespace std;
//constructor initializes the data to 0
table::table()
{
    root = nullptr;
}
//Deallocates all of the dynamic memory
table::~table()
{
    destructor(root);    
}
//This is a recursive function called in deconstructor
int table::destructor(product_node *& root)
{
    if(!root) return 1;

    destructor(root->left);
    destructor(root->right);

    delete root;
    root = nullptr;

    return 1;
    
}
//wrapper created to insert a node in the bst
int table::insert(product & new_product)
{
    return insert(root, new_product); 
}
//Recursive function checks to see where to insert in bst
int table::insert(product_node *& root, product & new_product)
{
    if(!root)
    {
        root = new product_node;
        root->a_product.copy(new_product);
        root->left = nullptr;
        root->right = nullptr;
        return 1;
    }
    if(root->a_product.compare(new_product) == -1)
        return insert(root->left, new_product);
    else
        return insert(root->right, new_product);

    return 1;

}
//wrapper created to display the data in the bst
int table::display_all()
{
    if(!root) return 0;

    return display_all(root);
}
//Recursive call to display all the contents in the bst
int table::display_all(product_node* root)
{
    if(!root) return 0;
    display_all(root->left);
    cout << root->a_product.display();
    return display_all(root->right);
}
//Wrapper function called to remove a node in the bst
int table::remove(char * name, product & new_product)
{
    if(!root) return 0;


    return remove(root, name, new_product);
}

//This function will test all cases when removing a node in the bst
int table::remove(product_node * & root, char * name, product & new_product)
{

    if(!root) return -1; //No match was found

    if(root->a_product.compare_name(name) == 0)
    {

        if(!root->left && !root->right)//Removing at a leaf
        {
            delete root;
            root = nullptr;
            return 1;
        }
        else if(root->left && !root->right)//Removing when node being removed has a left child only
        {
            product_node *hold = root->left;
            delete root;
            root = hold;
            return 1;
        }
        else if(!root->left && root->right)//Removing when node being removed has a right child only
        {
            product_node * hold = root->right;
            delete root;
            root = hold;
            return 1;
        }
        else//Remove a node that has two children
        {
            IOS(root->right, name, new_product);
            root->a_product.copy(new_product);
            return 1;

        }


    }

    if(root->a_product.compare_name(name) == -1)
        return remove(root->left, name, new_product);
    else
        return remove(root->right, name, new_product);


}
//This function will return the in order succer being the next highest node
int table::IOS(product_node * & root, char * name, product & new_product)
{
    if(!root->left)
    {
        //num = root->data;
        //root->a_product.copy(new_product);
        new_product.copy(root->a_product);//copies into an empty product
        //new_product;
        product_node * hold = root->right;
        delete root;
        root = hold;
        return 1;

    }
    return IOS(root->left, name, new_product);
}
//wrapper called to retrieve data
int table::retrieve(char * name, product & new_product)
{
    if(!root) return 0;
    
    return retrieve(name, new_product, root);
}
//recursive call in orde to retrieve the correct data
int table::retrieve(char * name, product & new_product, product_node * root)
{
    if(!root) return -1;//No match was found

    if(root->a_product.compare_name(name) == 0)
    {
        new_product.copy(root->a_product);
        return 1;
    }

    else if(root->a_product.compare_name(name) == -1)
        return retrieve(name, new_product, root->left);
    else
        return retrieve(name, new_product, root->right);
}
//will return the height of the tree (wrapper function)
int table::height()
{
    if(!root) return 0;

    return height(root) - 1;//I subract 1 bc the height starts at 0
                            //It is the edges to the longest path
}
//The recursive call to check the height of every path return the biggest one
int table::height(product_node * root)
{
    if(!root) return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    return max(left, right) + 1;
}
//wrapper to display a range
int table::display_range(float low, float high)
{
    if(!root) return 0;
    
    return display_range(root, low, high);
}
//this function will check every node and see if it is in the desired range and dislplay it
int table::display_range(product_node * root, float low, float high)
{
    if(!root) return 0;
    
    if(root->a_product.range_compare(low, high))
        root->a_product.display();
    display_range(root->left, low, high);
    return display_range(root->right, low, high);
    
}
