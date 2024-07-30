#include<bits/stdc++.h>
using namespace std;

class CQueue{
    public:
    int * arr;
    int size;
    int front;
    int rear;

    CQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        // Q full

        // single ele

        // circular

        // normal
        // rear = (front - 1)%(size - 1) full mate 
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout << "q is full" << endl;
        }
        else if(front == -1 && rear == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        // empty
        // single
        // circular
        // noramal

        if(front == -1 && rear == -1){
            cout << "queue is empty" << endl;
        }else if(front == rear){
            arr[front] = -1;
            front = rear = -1;
        }else if(front == size-1){
            front = 0;
        }else{
            front++;
        }
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

    CQueue q(10);

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    
    return 0;
}