#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s , int target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int topEle = s.top();
    s.pop();
    solve(s , target);

    s.push(topEle);
}

void inserAtBottam(stack<int> &s){
    if(s.empty()){
        cout << "empty" << endl;
        return;
    }
    int target = s.top();
    s.pop();

    solve(s,target);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    inserAtBottam(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}