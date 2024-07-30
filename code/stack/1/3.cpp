#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "meet";

    stack<char> s;
    
    int n = str.size();
    for(int i = 0; i < n; i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}