#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &s , int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    if(s.top() >= target){
        s.push(target);
        return;
    }

    int topEle = s.top();
    s.pop();
    insertSorted(s , target);

    s.push(topEle);
}

void sortStack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int topEle = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s , topEle);
    
}

int main(){
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}