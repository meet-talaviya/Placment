#include<bits/stdc++.h>
using namespace std;

// void solve(int arr[]){
//     // cout << sizeof(arr) << endl; 
//     cout << arr << endl;
//     cout << &arr << endl; // difernt value for the function 
//     arr[0] = 20;
// }

// function ma je pointer pass kari ye tenu address diffrent hoy

void update(int * p){
    *p = *p + 10;
    cout << p << endl;
    cout << &p << endl;
}

int main(){
    // int arr[4] = {1,2,3,4};

    // cout << arr << endl;
    // cout << &arr << endl;
    // cout << &arr[0] << endl;
    // cout << arr[0] << endl;

    // int *p = arr;
    // cout << p << endl;
    // cout << &p << endl;
    // cout << *p <<endl;

    // // arr = arr + 2;  not possibale
    // p = p + 1;
    // cout << p << endl;

    // cout << *arr << endl;
    // cout << *(arr + 0) << endl;
    // cout << *(arr + 1) << endl;
    // cout << arr[1] << endl;

    // int i = 0;
    // cout << arr[i] << endl;
    // cout << i[arr] << endl;
    // cout << *(arr + i) << endl;
    // cout << *(i +arr) << endl;

    // cout << sizeof(arr) << endl;
    // cout << sizeof(p) << endl;

    // char ch[5] = "meet";

    // char * c = ch;
 
    // cout << ch << endl; //defrent for int arr and char arr
    // cout << &ch << endl;
    // cout << c << endl; // string print thay
    // cout << &c << endl;
    // cout << *c << endl; 

    // char ch = 'k';
    // char *cptr = &ch;

    // cout << cptr << endl; // jab tak null char na made taya sudhi print thay 

    // char *ch = "meet"; // this allow only in ch type pointer
    // cout << ch << endl;

    //-------- pointer with function
    // int arr[10] = {1,2,3,4};
    // // cout << sizeof(arr) << endl;
    // // solve(arr);
    // cout << arr << endl;
    // cout << &arr << endl;

    // for(int i = 0; i < 10; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // solve(arr);

    // for(int i = 0; i < 10; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int a = 5;
    int *ptr = &a;

    cout << ptr << endl;
    cout << &ptr << endl;

    update(ptr);

    cout << a << endl;


    return 0;
}