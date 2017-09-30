#include<iostream>
#include<conio.h>

#define size 5

using namespace std;

class queue{

    private:

        int arr[size];
        int front;
        int rear;

    public:

        queue();
        bool isFull();
        bool isEmpty();
        void enqueue( int a );
        int dequeue();
};

queue :: queue(){

    front = 0;
    rear = 0;
}

bool queue :: isFull(){

    if( rear == size ){

        return true;
    }else{

        return false;
    }
}

bool queue :: isEmpty(){

    if( front == rear ){

        return true;
    }else{

        return false;
    }
}

void queue :: enqueue( int b ){

    if( isFull() ){

        cout << endl << "Queue is full...!!!" <<endl;
    }else{

        arr[rear] = b;
        cout << endl << arr[rear] << " is inserted." << endl;
        rear++;
    }
}

int queue :: dequeue(){

    if( isEmpty() ){

        cout << endl << "Queue is empty...!!!" << endl;
    }else{

        int element = arr[front];
        arr[front] = NULL;
        cout << endl << element << " is deleted." << endl;
        front++;
    }
}

int main()
{
    queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    q.dequeue();
    q.dequeue();

    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    q.dequeue();
}
