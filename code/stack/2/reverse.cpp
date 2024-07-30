#include<bits/stdc++.h>
using namespace std;

void insertAtBottem(stack<int> &s , int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int topEle = s.top();
    s.pop();
    insertAtBottem(s , target);

    s.push(topEle);
}

void revStack(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();

    revStack(s);

    insertAtBottem(s , target);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;

    revStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}


