#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int * arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout << "queue is full" << endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(rear == front){
            cout << "queue is empty" << endl;
        }else{
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    int getFront(){
        if(front == rear){
            cout << "queue is empty" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }else{
            return false;
        }
    }

    int getSize(){
        return rear - front;
    }
};

// void print(Queue q){
//     while(!q.isEmpty()){
//         cout << q.getFront() << " ";
//         q.pop(); 
//     }
//     cout << endl;
// }

int main(){

    Queue q(10);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    cout << "size : " << q.getSize() << endl;

    // print(q);

    q.pop();

    cout << "size : " << q.getSize() << endl;

    cout << "front : " << q.getFront() << endl;

    if(q.isEmpty()){
        cout << "Q is empty" << endl;
    }else{
        cout << "Q is not empty" << endl;
    }

    return 0;
}