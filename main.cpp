//Miguel Salvador

#include "bst.h"
using namespace std;

int main()
{
    char choice;
    table bst;

    do
    {
        cout << "a).insert b).display all c).Remove d).Retrieve e). range f).Height q).quit: ";
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
                    break;
             
                }
                case 'd':
                {
                    char name[SIZE];
                    product retrieved_obj;

                    cout << "Name of product you wish to retrieve: ";
                    cin.get(name, SIZE, '\n');
                    cin.ignore(SIZE, '\n');
                    bst.retrieve(name, retrieved_obj);

                    if(retrieved_obj.display() == -1)
                        cout << "No Match" << endl;
                    /*else
                    {
                    cout << "Values Retrieved are: " << endl;
                    retrieved_obj.display();
                    }
                    */
                   break; 
                }
                case 'e':
                {
                    float low{0.0};
                    float high{0.0};
                    
                    cout << "Give products Range you are looking for: " << endl;

                    cout << "Low: ";
                    cin >> low;
                    cin.ignore(SIZE, '\n');

                    cout << "High: ";
                    cin >> high;
                    cin.ignore(SIZE, '\n');


                    bst.display_range(low, high);
                    break;

                }
                case 'f':
                {
                    int height = bst.height();

                    cout << "The height of the tree is: " << height << endl;
                    break;
                }
        }              
    }while(choice != 'q');

    return 0;
}
