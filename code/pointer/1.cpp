// pointer 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 5;
    int *ptr = &a; // always address store in pointer
    // int *ptr = a; not true 

    cout << a << endl;
    cout << &a << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &ptr << endl;

    int *p = ptr;
    cout << p << endl;
    cout << *p << endl;
    cout << &p << endl;
    return 0;
}