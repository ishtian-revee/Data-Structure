#include<iostream>
#include<cstdlib>

using namespace std;

struct node{        // creating node structure

    int data;
    node *next;
};

node *head;     // globally pointer variable declared

class linkedList{       // class

    public :

        linkedList(){       // constructor

            head = NULL;
        }

        node *insert_beginning( node *head , int n ){       // insert at beginning function

            node *temp , *p;
            temp = new node;
            temp->data = n;

            if( head == NULL ){

                head = temp;
                head->next = NULL;

                return head;
            }else{

                p = head;
                head = temp;
                head->next = p;

                return head;
            }
        }

        int insert_ending( node *head , int n ){        // insert at ending function

            node *temp , *s;
            temp = new node;
            temp->data = n;

            if( head == NULL ){

                cout << endl << "This function can't add new student information at the end of the linked list " << endl;
                return 0;
            }

            s = head;
            while( s->next != NULL ){

                s = s->next;
            }

            s->next = temp;
            temp->next = NULL;
        }

        node *insert_position( node *head , int n ){        // insert at given position function

            node *temp , *s , *p;
            temp = new node;
            temp->data = n;

            int pos , counter = 0;

            cout << endl << "Enter the position where the number is to be inserted : ";
            cin >> pos;

            s = head;
            while( s != NULL ){

                counter++;
                s = s->next;
            }

            if( pos == 1 ){

                if( head == NULL ){

                    head = temp;
                    head->next = NULL;

                    return head;
                }else{

                    p = head;
                    head = temp;
                    head->next = p;

                    return head;
                }
            }else if( pos>1 && pos<=counter ){

                s = head;
                for( int a=1; a<pos; a++ ){

                    p = s;
                    s = s->next;
                }

                p->next = temp;
                temp->next = s;

                return head;
            }else{

                cout << endl << "Invalid position...!!! " << endl;
            }
        }

        node *delete_node( node *head ){      // delete node function

            if( head == NULL ){

                cout  << endl << "List is empty... !!! " << endl;
                return 0;
            }

            node *temp , *s;
            int element;

            cout << endl << "Enter the number that is to be deleted : ";
            cin >> element;

            if( head->data == element ){

                temp = head;
                head = head->next;
                free(temp);

                return head;
            }

            s = head;
            while( s->next->next != NULL ){

                if( s->next->data == element ){

                    temp = s->next;
                    s->next = temp->next;
                    free(temp);

                    return head;
                }

                s = s->next;
            }

            if( s->next->data == element ){

                temp = s->next;
                free(temp);
                s->next = NULL;

                return head;
            }

            cout << endl << "Inputed number doesn't exist in the list... !!! " << endl;
        }

        int search_node( node *head ){      // search node function

            if( head == NULL ){

                cout << endl << "List is empty...!!! " << endl;
                return 0;
            }

            node *s;
            int element , pos = 0;

            cout << endl << "Enter the number that is to be searched : ";
            cin >> element;

            s = head;
            while( s != NULL ){

                pos++;

                if( s->data == element ){

                    cout << endl << "The number is at the position : " << pos << endl;
                    return 0;
                }

                s = s->next;
            }

            cout << endl << "Inputed number doesn't exist in the list... !!! " << endl;
        }

        void display( node *head ){         // display function

            if( head == NULL ){

                cout << endl << "List is empty...!!! " << endl;
            }else{

                node *s;

                cout << endl;

                s = head;
                while( s != NULL ){

                    cout << s->data << " ";

                    s = s->next;
                }
            }

            cout << endl;
        }
};

int main()      // main function
{
    linkedList list;      // object declared
    int choice;

    head = NULL;

    while( 1==1 ){      // infinite loop

        cout << endl << "1. Insert at beginning " << endl;
        cout << "2. Insert at ending " << endl;
        cout << "3. Insert at given position " << endl;
        cout << "4. Delete node " << endl;
        cout << "5. Search node " << endl;
        cout << "6. Display " << endl;
        cout << "7. Exit " << endl;

        cout << endl << "Enter a number (1-7) : ";
        cin >> choice;

        if( choice == 1 ){

            int num;

            cout << endl << "Enter a number that is to be inserted : ";
            cin >> num;

            head = list.insert_beginning( head , num );
        }else if( choice == 2 ){

            int num;

            cout << endl << "Enter a number that is to be inserted : ";
            cin >> num;

            list.insert_ending( head , num );
        }else if( choice == 3 ){

            int num;

            cout << endl << "Enter a number that is to be inserted : ";
            cin >> num;

            head = list.insert_position( head , num );
        }else if( choice == 4 ){

            head = list.delete_node( head );
        }else if( choice == 5 ){

            list.search_node( head );
        }else if( choice == 6 ){

            list.display( head );
        }else if( choice == 7 ){

            exit(1);
        }else{

            cout << endl << "Wrong input...!!! " << endl;
        }
    }
}
