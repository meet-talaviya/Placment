#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    stack<int> s;
    s.push(-1);
    int n = v.size();

    vector<int> ans(n);
    
    for(int i = n-1; i >= 0; i--){
         int currEle = v[i];

         while(s.top() >= currEle){
            s.pop();
         }
         ans[i] = s.top();
         s.push(currEle);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}