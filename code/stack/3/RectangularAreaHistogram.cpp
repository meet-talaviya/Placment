#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);
    int n = v.size();

    vector<int> ans(n);
    
    for(int i = n-1; i >= 0; i--){
         int currEle = v[i];

         while(s.top() != -1 && v[s.top()] >= currEle){
            s.pop();
         }
         ans[i] = s.top();
         s.push(i);
    }

    return ans;

}

vector<int> prevSmaller(vector<int> &v){
    stack<int> s;
    s.push(-1);

    int n = v.size();
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        int curr = v[i];

        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int getrectangularAreaHistogram(vector<int> &height){
    // step 1 : prevSmaller output

    vector<int> prev = prevSmaller(height);

    // step2: nextSmaller

    vector<int> next = nextSmaller(height);
    int size = height.size();

    int maxArea = INT_MIN;

    for(int i = 0; i < size; i++){
        int length = height[i];

        if(next[i] == -1){
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;

        int area = length*width; 
        maxArea = max(maxArea , area);
    }
    return maxArea;
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout << "Ans : " << getrectangularAreaHistogram(v) << endl;

    // vector<int> ans1 = nextSmaller(v);

    // cout << "printing next smaller index:" << endl;
    // for(auto i : ans1){
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<int> ans2 = prevSmaller(v);

    // cout << "printing prev smaller index: " << endl;
    // for(auto j : ans2){
    //     cout << j << " ";
    // }
    // cout << endl;

    return 0;
}