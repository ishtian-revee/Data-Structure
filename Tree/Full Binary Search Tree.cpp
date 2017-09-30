#include<iostream>
#include<cstdlib>

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

        node *search_data( node *root , int value ){        // search data function

            if( root != NULL ){

                if( value < root->data ){

                    root = search_data( root->left , value );       // use of recursion
                }else if( value > root->data ){

                    root = search_data( root->right , value );      // use of recursion
                }
            }

            return root;
        }

        void inorder( node *root ){     // inorder function

            if( root != NULL ){

                inorder( root->left );      // use of recursion
                cout << root->data << " ";
                inorder( root->right );     // use of recursion
            }
        }

        void postorder( node *root ){       // postorder function

            if( root != NULL ){

                postorder( root->left );        // use of recursion
                postorder( root->right );       // use of recursion
                cout << root->data << " ";
            }
        }

        void preorder( node *root ){        // preorder unction

            if( root != NULL ){

                cout << root->data << " ";
                preorder( root->left );     // use of recursion
                preorder( root->right );        // use of recursion
            }
        }

        int depth( node *root ){        // finding depth function

            if( root == NULL ){

                return 0;
            }else{

                int left_depth = depth( root->left );       // use of recursion
                int right_depth = depth( root->right );     // use of recursion

                if( left_depth > right_depth ){

                    return ( left_depth + 1 );
                }else{

                    return ( right_depth + 1 );
                }
            }
        }

        node *minimum( node *root ){        // finding minimum value function

            while( root->left != NULL ){

                root = root->left;
            }

            return root;
        }

        node *delete_data( node *root , int value ){        // delete data function

            if( root == NULL ){

                return root;
            }else if( value < root->data ){

                root->left = delete_data( root->left , value );
            }else if( value > root->data ){

                root->right = delete_data( root->right , value );
            }else{

                if( root->left == NULL && root->right == NULL ){

                    delete root;
                    root = NULL;
                }else if( root->left == NULL ){

                    node *temp;
                    temp = root;
                    root = root->right;
                    delete temp;
                }else if( root->right == NULL ){

                    node *temp;
                    temp = root;
                    root = root->left;
                    delete temp;
                }else{

                    node *temp;
                    temp = minimum( root->right );
                    root->data = temp->data;
                    root->right = delete_data( root->right , temp->data );
                }
            }

            return root;
        }
};

int main()      // main function
{
    tree t;     // object declared
    int choice;

    while( 1==1 ){      // infinite loop

        cout << endl << "1. Insert data " << endl;
        cout << "2. Search data " << endl;
        cout << "3. Traverse data in inorder " << endl;
        cout << "4. Traverse data in postorder " << endl;
        cout << "5. Traverse data in preorder " << endl;
        cout << "6. Show depth of the tree " << endl;
        cout << "7. Delete data from the tree " << endl;
        cout << "8. Exit " << endl;

        cout << endl << "Enter a number (1-8) : ";
        cin >> choice;

        if( choice == 1 ){

            int num;
            cout << endl << "Enter a value that is to be inserted : ";
            cin >> num;

            root = t.insert_data( root , num );
        }else if( choice == 2 ){

            int num;
            cout << endl << "Enter a data that is to be searched : ";
            cin >> num;

            node *item;
            item = t.search_data( root , num );

            if( item == NULL ){

                cout << endl << "Data not found " << endl;
            }else{

                cout << endl << "Data found " << endl;
            }
        }else if( choice == 3 ){

            cout << endl << "Traverse in inorder : ";
            t.inorder( root );
            cout << endl;
        }else if( choice == 4 ){

            cout << endl << "Traverse data in postorder : ";
            t.postorder( root );
            cout << endl;
        }else if( choice == 5 ){

            cout << endl << "Traverse data in preorder : ";
            t.preorder( root );
            cout << endl;
        }else if( choice == 6 ){

            cout << endl << "The depth of the tree : " << t.depth( root ) << endl;
        }else if( choice == 7 ){

            int num;

            cout << endl << "Enter a data that is to be deleted : ";
            cin >> num;

            root = t.delete_data( root , num );
        }else if( choice == 8 ){

            exit(1);
        }else{

            cout << endl << "Wrong input...!!! " << endl;

        }
    }
}
