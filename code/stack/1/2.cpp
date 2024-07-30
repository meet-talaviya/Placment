#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // fuction
    void push(int data){
        if(size-top > 1){
            // space available
            // insert
            top++;
            arr[top] = data;
        }else{
            // space not 
            cout << "stack overflow" << endl;
        }

    }

    void pop(){

        if(top == -1){
            // stack empty
            cout << "stack underflow" << endl;
        }else{
            top--;
        }

    }

    int getTop(){

        if(top == -1){
            cout << "stack is empty" << endl;
            return -1;
        }else{
            return arr[top];
        }

    }

    int getSize(){
         return top + 1;

    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }

    }
};

int main(){

    Stack s(10);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty()){
        cout << s.getTop() << " ";
        s.pop();
    }

    cout << "stack empty or not : " << s.getSize() << endl;

    return 0;
}