#include<iostream>
#include<cstdlib>

#define max 5       // declaring stack size

using namespace std;

struct node{        // creating node structure

    int data;
    node *next;
};

node *head;     // globally declared variables
int top;
int a = 0;

class stack{        // class

    public:

        stack();
        int add_data();
        int push( int n );
        int pop();
        int display();
};

stack :: stack(){   // constructor

    top = 0;
    head = NULL;
}

int stack :: add_data(){    // Adding data function

    int x;

    cout << endl << "Enter the number that is to be inserted : ";
    cin >> x;

    return x;
}

int stack :: push( int n ){

    if( top >= max ){

        cout << endl << "Stack overflow... !!! " << endl;
        return 0;
    }else if( a == 0 ){

        node *temp;
        temp = new node;
        temp->data = n;
        temp->next = head;
        head = temp;

        top++;
        a++;
    }else{

        node *temp , *s;
        temp = new node;
        temp->data = n;

        s = head;
        while( s->next != NULL ){

            s = s->next;
        }
        s->next = temp;
        temp->next = NULL;

        top++;
    }
}

int stack :: pop(){     // pop function

    if( top <= 0 ){

        cout << endl << "Stack underflow...!!!" << endl;
        return 0;
    }else{

        node *s;
        s = head;
        while( s->next->next != NULL ){

            s = s->next;
        }
        s->next = NULL;

        top--;
    }
}

int stack :: display(){     // display function

    if( head == NULL ){

        cout << endl << "Stack is empty...!!!" << endl;
        return 0;
    }else{

        node *p;
        p = head;

        cout << endl;

        while( p!= NULL ){

            cout << p->data << " ";

            p = p->next;
        }
        cout << endl;
    }
}

int main()      // main function
{
    stack s;
    int choice;

    head = NULL;

    while( 1==1 ){

        cout << endl << "1. Push " << endl;
        cout << "2. Pop " << endl;
        cout << "3. Display " << endl;
        cout << "4. Exit " << endl << endl;

        cout << "Enter a number(1-4) : ";
        cin >> choice;

        if( choice == 1 ){

            s.push( s.add_data() );
        }else if( choice == 2 ){

            s.pop();
        }else if( choice == 3 ){

            s.display();
        }else if( choice == 4 ){

            exit(1);
        }else{

            cout << endl << "WRONG INPUT...!!! " << endl;
        }
    }
}
