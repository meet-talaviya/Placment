#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{3,1,4,1,5};
    int k = 2;

    int n = arr.size();

    set<pair<int , int>>ans;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(abs(arr[i] - arr[j]) == k){
                ans.insert(make_pair(arr[i] , arr[j]));
            }
        }
    }

    cout << "size of : " << ans.size() << endl;

    for(auto i : ans){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}