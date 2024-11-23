//Miguel Salvador

#include "bst.h"
using namespace std;

int main()
{
    char choice;
    table bst;

    do
    {
        cout << "a).insert b).display all q).quit: ";
        cin >> choice;
        cin.ignore(SIZE, '\n');
        switch(choice)
        {
            case 'a':
                {
                    char title[SIZE];
                    char description[SIZE];
                    char category[SIZE];
                    char type[SIZE];
                    float price{0};
                    int quantity{0};
                    int ID{0};
                    char shop_name[SIZE];

                    cout << "Title: ";
                    cin.get(title, SIZE, '\n');
                    cin.ignore(SIZE, '\n');

                    cout << "Description: ";
                    cin.get(description, SIZE, '\n');
                    cin.ignore(SIZE, '\n');

                    cout << "Category: ";
                    cin.get(category, SIZE, '\n');
                    cin.ignore(SIZE, '\n');


                    cout << "Type: ";
                    cin.get(type, SIZE, '\n');
                    cin.ignore(SIZE, '\n');

                    cout << "Price: ";
                    cin >> price;
                    cin.ignore(SIZE, '\n');

                    cout << "Quantity: ";
                    cin >> quantity;
                    cin.ignore(SIZE, '\n');

                    cout << "ID : ";
                    cin >> ID;
                    cin.ignore(SIZE, '\n');

                    cout << "Shop Name: ";
                    cin.get(shop_name, SIZE, '\n');
                    cin.ignore(SIZE, '\n');

                    product full_obj(title, description, category, type, price, quantity, ID, shop_name);
                    //This will create product that is full
                    //full_obj.display(); I used to see if obj had client info

                    bst.insert(full_obj);
                    break;
                }

                case 'b':
                {
                    bst.display_all();
                    break;
                }
                case 'c':
                {
                    char name[SIZE];
                    cout << "Name of product you wish to remove: ";
                    cin.get(name, SIZE, '\n');
                    cin.ignore(100, '\n');
                    product empty_product;

                    bst.remove(name, empty_product);

             
                }
        }              
    }while(choice != 'q');

    return 0;
}
