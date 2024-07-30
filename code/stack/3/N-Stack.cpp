#include<bits/stdc++.h>
using namespace std;

class NStack{
    int *a;
    int *top;
    int *next;

    int n; // number of stack
    int size; //number of main array
    int freeSpot;//tells free space in main array

    public:
    NStack(int n , int size){
        this->n = n;
        this->size = size;
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for(int i = 0; i < n; i++){
            top[i] = -1;
        }

        for(int i = 0; i < size; i++){
            next[i] = i+1;
        }
        next[size-1] = -1;
    }  

    bool push(int x , int m){
        if(freeSpot == -1){
            return false; // stack overflow
        }

        // 1.find index
        int index = freeSpot;

        // 2.update freespot
        freeSpot = next[index];

        // 3.insert
        a[index] = x;

        // 4.upadate next
        next[index] = top[m-1];

        // 5.update top
        top[m-1] = index;

        return true;
    }

    int pop(int m){
        if(top[m-1] == -1){
            return -1; //stcke underflow
        }

        int index = top[m-1];

        top[m-1] = next[index];

        int popEle = a[index];

        next[index] = freeSpot;
        freeSpot = index;

        return popEle;
    }

    ~NStack(){
        delete[]a;
        delete[] top;
        delete[] next;
    }
};

int main(){
    NStack s(3,6);
    cout << s.push(10,1) << endl;
    cout << s.push(11,1) << endl;
    cout << s.push(12,2) << endl;
    cout << s.push(13,3) << endl;
    cout << s.push(14,1) << endl;
    cout << s.push(15,1) << endl;
    cout << s.pop(1) << endl;

    return 0;
}