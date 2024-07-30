#include<bits/stdc++.h>
using namespace std;

class DQueue{
    public:
    int * arr;
    int size;
    int front;
    int rear;

    DQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_rear(int data){
        // Q full

        // single ele

        // circular

        // normal
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout << "q is full" << endl;
            return;
        }
        else if(front == -1 && rear == -1){
            front = rear = 0;
          
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
       
        }else{
            rear++;
           
        }
        arr[rear] = data;
    }


    
    void push_front(int data){
        // Q full

        // single ele

        // circular

        // normal
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout << "q is full" << endl;
            return;
        }
        else if(front == -1 && rear == -1){
            front = rear = 0;
          
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
       
        }else{
            front--;
           
        }
        arr[front] = data;
    }

    void pop_front(){
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

    void pop_rear(){
        // empty
        // single
        // circular
        // noramal

        if(front == -1 && rear == -1){
            cout << "queue is empty" << endl;
        }else if(front == rear){
            arr[rear] = -1;
            front = rear = -1;
        }else if(rear == 0){
            rear = size-1;
        }else{
            rear--;
        }
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};



int main(){

    DQueue q(10);

    q.push_front(10);
    q.print();


    
    return 0;
}