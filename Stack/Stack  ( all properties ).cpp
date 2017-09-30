#include<iostream>

#define MAX 5

using namespace std;

class stack{

    private :

        int arr[MAX];
        int top;

    public :

        stack();
        void push( int a );
        void pop();
        int isFull();
        int isEmpty();
        void top_element();
        void display();
};

stack :: stack(){

    top = -1;
}

int stack :: isFull(){

    if( top == MAX-1 ){

        return 1;
    }else{

        return 0;
    }
}

int stack :: isEmpty(){

    if( top == -1 ){

        return 1;
    }else{

        return 0;
    }
}

void stack :: push( int a ){

    if( isFull() == 1 ){

        cout << "Stack is Full...!!!" << endl;
    }else{

        top++;
        arr[top] = a;
        cout << a << " is pushed." << endl;
    }
}

void stack :: pop(){

    if( isEmpty() == 1 ){

        cout << "Stack is Empty...!!!" << endl;
    }else{

        int data = arr[top];
        arr[top] = NULL;
        top--;
        cout << data << " is popped." << endl;
    }
}

void stack :: top_element(){

    if( isEmpty() == 1 ){

        cout << "Top element : 0" << endl;
    }else{

        cout << "Top element : " << arr[top] << endl;
    }
}

void stack :: display(){

    cout << "Stack : ";

    for( int i=0; i<=top; i++ ){

        cout << arr[i] << " ";
    }
}

int main()
{
    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    s.top_element();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.top_element();

    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.push(12);

    s.top_element();

    s.pop();
    s.pop();

    s.top_element();

    s.display();
}
