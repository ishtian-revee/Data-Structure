#include<iostream>
#include<cstdlib>
#include<stack>

using namespace std;

struct node{        // creating node structure

    int data;
    node *left;
    node *right;
};

node *root;     // globally pointer variable declared

class tree{     // class

    public :

        tree(){      // constructor

            root = NULL;
        }

        node *insert_data( node *root , int value ){        // insert data function

            node *temp;
            temp = new node;
            temp->data = value;

            if( root == NULL ){

                root = temp;
                temp->left = NULL;
                temp->right = NULL;
            }else if( root->data == value ){

                cout << endl << "Data already in the tree " << endl;
            }else if( value < root->data ){

                root->left = insert_data( root->left , value );       // use of recursion
            }else if( value > root->data ){

                root->right = insert_data( root->right , value );      // use of recursion
            }

            return root;
        }

        void inorder( node *root ){     // inorder traverse function

            stack <node*> s;
            node *temp;
            temp = root;

            while( !s.empty() || temp ){

                if( temp ){

                    s.push( temp );
                    temp = temp->left;
                }else{

                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";
                    temp = temp->right;
                }
            }
        }
};

int main()
{
    tree t;     // object declared
    root = NULL;

    int choice;

    while( 1==1 ){

        cout << endl << "1. Insert data " << endl;
        cout << "2. Traverse in inorder (using stack) " << endl;
        cout << "3. Exit " << endl;

        cout << endl << "Enter a number (1-3) : ";
        cin >> choice;

        if( choice == 1 ){

            int num;
            cout << endl << "Enter a value that is to be inserted : ";
            cin >> num;

            root = t.insert_data( root , num );
        }else if( choice == 2 ){

            cout << endl << "Traverse in inorder : ";
            t.inorder( root );
            cout << endl;
        }else if( choice == 3 ){

            exit(1);
        }else{

            cout << endl << "Wrong input...!!! " << endl;
        }
    }
}
