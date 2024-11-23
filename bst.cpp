//Hello

#include "bst.h"
using namespace std;
table::table()
{
    root = nullptr;
}

table::~table()
{

}

int table::insert(product & new_product)
{
    return insert(root, new_product); 
}

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
int table::display_all()
{
    if(!root) return 0;

    return display_all(root);
}

int table::display_all(product_node* root)
{
    if(!root) return 0;
    display_all(root->left);
    cout << root->a_product.display();
    return display_all(root->right);
}

int table::remove(char * name, product & new_product)
{
    if(!root) return 0;


    return remove(root, name, new_product);
}


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

int table::retrieve(char * name, product & new_product)
{
    return 1;
}

int table::retrieve(char * name, product & new_product, product_node * root)
{
    return 1;
}
