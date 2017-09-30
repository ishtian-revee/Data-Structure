#include<iostream>
#include<cstdlib>
#include<string>
#include<stdio.h>

using namespace std;

struct node{    // creating node structure

    int id;
    string name;
    char grade;
    node *next;
    node *prev;
};

node *head;     // globally declared pointer head variable

class doubly_linkedList{        // class

    public :

        doubly_linkedList(){        // constructor

            head = NULL;
        }

        node *insert_at_head( node *head , int i , string n , char g ){     // inserting at head function

            node *temp , *p;
            temp = new node;
            temp->id = i;
            temp->name = n;
            temp->grade = g;

            if( head == NULL ){

                head = temp;
                head->next = NULL;
                head->prev = NULL;

                return head;
            }else{

                p = head;
                head = temp;
                p->prev = head;
                head->next = p;
                head->prev = NULL;

                return head;
            }
        }

        int insert_at_tail( node *head , int i , string n , char g ){       // inserting at tail function

            node *temp , *p;
            temp = new node;
            temp->id = i;
            temp->name = n;
            temp->grade = g;

            if( head == NULL ){

                cout << endl << "This function can't add new student information at the end of the linked list " << endl;
                return 0;
            }

            p = head;
            while( p->next != NULL ){

                p = p->next;
            }

            p->next = temp;
            temp->prev = p;
            temp->next = NULL;
        }

        node *insert_at_position( node *head , int i , string n , char g ){       // inserting at given position function

            node *temp , *s , *p;
            temp = new node;
            temp->id = i;
            temp->name = n;
            temp->grade = g;

            int pos , counter = 0;
            cout << endl << "Enter the position where all the information is to be inserted : ";
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
                    head->prev = NULL;

                    return head;
                }else{

                    p = head;
                    head = temp;
                    p->prev = head;
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
                temp->prev = p;
                temp->next = s;
                s->prev = temp;

                return head;
            }else{

                cout << endl << "Invalid position... " << endl;
            }
        }

        int delete_info( node *head ){      // deleting function

            if( head == NULL ){

                cout << endl << "List is empty " << endl;
                return 0;
            }

            node *temp , *s;
            int element;

            cout << endl << "Enter student id that is to be deleted : ";
            cin >> element;

            if( head->id == element ){

                temp = head;
                head = head->next;
                head->prev = NULL;
                free(temp);
                return 0;
            }

            s = head;
            while( s->next->next != NULL ){

                if( s->next->id == element ){

                    temp = s->next;
                    s->next = temp->next;
                    temp->next->prev = s;
                    free(temp);

                    return 0;
                }

                s = s->next;
            }

            if( s->next->id == element ){

                temp = s->next;
                free(temp);
                s->next = NULL;

                return 0;
            }

            cout << endl << "Inputed student id is not in the list " << endl;
        }

        int search_info( node *head ){      // searching function

            if( head == NULL ){

                cout << endl << "List is empty " << endl;
                return 0;
            }

            int element , pos = 0;

            cout << endl << "Enter the student id that is to be searched : ";
            cin >> element;

            node *s;
            s = head;
            while( s != NULL ){

                pos++;

                if( s->id == element ){

                    cout << endl << "The student that we are looking for is at the position : " << pos << endl;
                    return 0;
                }

                s = s->next;
            }

            cout << endl << "Inputed student id is not in the list " << endl;
        }

        void display( node *head ){     // displaying function

            if( head == NULL ){

                cout << endl << "List is empty " << endl;
            }else{

                node *s;
                s = head;
                while( s != NULL ){

                    cout << endl << "Student Id : " << s->id << endl;
                    cout << "Student Name : " << s->name << endl;
                    cout << "Student Grade : " << s->grade << endl;

                    s = s->next;
                }
                cout << endl;
            }
        }
};

int main()      // main function
{
    doubly_linkedList dl;       // object declared
    int choice;

    head = NULL;

    while( 1==1 ){      // infinite loop

        cout << endl << "1. Insert at head " << endl;
        cout << "2. Insert at tail " << endl;
        cout << "3. Insert at given position " << endl;
        cout << "4. Delete node based on student Id " << endl;
        cout << "5. Search node based on student Id " << endl;
        cout << "6. Display all nodes " << endl;
        cout << "7. Exit program " << endl;

        cout << endl << "Enter a number (1-7): ";
        cin >> choice;

        if( choice == 1 ){

            int i;
            string n;
            char g;

            cout << endl << "Enter Id : ";
            cin >> i;
            fflush(stdin);
            cout << "Enter Name : ";
            cin >> n;
            cout << "Enter Grade : ";
            cin >> g;

            head = dl.insert_at_head( head , i , n , g );
        }else if( choice == 2 ){

            int i;
            string n;
            char g;

            cout << endl << "Enter Id : ";
            cin >> i;
            fflush(stdin);
            cout << "Enter Name : ";
            cin >> n;
            cout << "Enter Grade : ";
            cin >> g;

            dl.insert_at_tail( head , i , n , g );
        }else if( choice == 3 ){

            int i;
            string n;
            char g;

            cout << endl << "Enter Id : ";
            cin >> i;
            fflush(stdin);
            cout << "Enter Name : ";
            cin >> n;
            cout << "Enter Grade : ";
            cin >> g;

            head = dl.insert_at_position( head , i , n , g );
        }else if( choice == 4 ){

            dl.delete_info( head );
        }else if( choice == 5 ){

            dl.search_info( head );
        }else if( choice == 6){

            dl.display( head );
        }else if( choice == 7 ){

            exit(1);
        }else{

            cout << endl << "Wrong input...!!! " << endl;
        }
    }
}
