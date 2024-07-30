// permutations 
#include<bits/stdc++.h>
using namespace std;

void printPer(string &str , int i){
    int n = str.size();
    if(i >= n){
        cout << str << " ";
        return;
    }

    for(int j = i; j < n; j++){
        swap(str[i] , str[j]);
        printPer(str, i+1);
        swap(str[i] , str[j]);
    }
}

int main(){
    string str = "abc";
    int i = 0;
    printPer(str , i);
    return 0;
}