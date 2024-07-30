#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);

    int n = v.size();
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int curr = v[i];

        while(s.top() >= curr){
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    vector<int> ans = prevSmaller(v);

    for(auto i : ans){
        cout << i << " ";
    }

    
    return 0;
}