#include<bits/stdc++.h>
using namespace std;

void printMiddalEle(stack<int> &s , int totalsize){
    int n = s.size();

    if(n == 0){
        cout << "not ele in stack " << endl;
    }
    if(n == (totalsize/2)+1){
        cout << "middle ele : " << s.top() << endl;
        return;
    }

    int temp = s.top();
    s.pop();

    printMiddalEle(s , totalsize);

    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    printMiddalEle(s , s.size());
    return 0;
}