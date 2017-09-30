#include<iostream>

using namespace std;

struct node{        // creating node structure

    int data;
    node *left;
    node *right;
};

node *root;     // globally pointer root variable declared

class tree{     // class

    public :

        tree(){       // constructor

            root = NULL;
        }

        node *insert_data( node *root , int data ){     // insert function

            node *temp;
            temp = new node;
            temp->data = data;

            if( root == NULL ){

                root = temp;
                temp->left = NULL;
                temp->right = NULL;
            }else if( root->data == data ){

                cout << endl << "Element already in the tree " << endl;
            }else if( data < root->data ){

                root->left = insert_data( root->left , data );      // use of recursion
            }else if( data > root->data ){

                root->right = insert_data( root->right , data );        // use of recursion
            }

            return root;
        }

        void postorder( node *root ){     // display in postorder function

            if( root != NULL ){

                postorder( root->left );      // use of recursion
                postorder( root->right );     // use of recursion
                cout << root->data << " ";
            }
        }
};

int main()      // main function
{
    tree t;     // object declared
    int n , data;

    root = NULL;

    cout << endl << "Enter number of nodes : ";
    cin >> n;

    cout << endl << "Enter data : " << endl << endl;
    for( int i=0; i<n; i++ ){

        cin >> data;
        root = t.insert_data( root , data );        // call of insertion function
    }

    cout << endl << "Postorderly sorted : ";
    t.postorder( root );      // call of postorder function
    cout << endl;
}
