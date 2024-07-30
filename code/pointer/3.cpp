#include<iostream>
using namespace std;

void solve(int** ptr){
    // ptr = ptr + 1;
    **ptr = **ptr + 1;
}

void util(int & value){
    value++;
}

void up(int *& p){
    p = p + 1;
}

int main(){
    int a = 5;
    int * p = &a;
    int ** q = &p;

    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;
    cout << q << endl;
    cout << &q << endl;
    cout << *q << endl;
    cout << **q << endl;

    // int a = 5;
    // int *ptr = &a;

    // solve(ptr);

    // int a = 5;
    // int * p = &a;
    // int ** q = &p;

    // cout << p << endl;
    // cout << a << endl;

    // solve(q);

    // cout << p << endl;
    // cout << a << endl;

    // ----------refrence
    // int a = 5;
    // int & b = a;

    // cout << a << endl;
    // cout << b << endl;

    // a++;
    // cout << a << endl;
    // cout << b << endl;

    // int a = 5;

    // util(a);

    // cout << a << endl;
    // int a = 5;
    // int * p = &a;

    // up(p);

    return 0;
}