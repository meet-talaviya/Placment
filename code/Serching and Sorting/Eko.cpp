#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr , int mid , int met){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > mid){
             sum += (arr[i] - mid);
        }
   
    }
    return sum >= met;
}

int findEko(vector<int> arr , int met){
    int start = 0;

    int maxi = INT_MIN;
    
    for(int i = 0; i < arr.size(); i++){
        maxi = max(maxi, arr[i]);
    }

    // cout << maxi << endl;

    int end = maxi;

    // cout << end << endl;

    int mid = start + (end - start)/2;

    int ans = -1;

    while(start <= end){
        if(isPossible(arr , mid, met)){
             ans = mid;
             start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans ;
}

int main(){
    vector<int> arr{20,15,10,17};

    int met = 7;
    
    int ans = findEko(arr , met);

    cout << ans << endl;

    return 0;
}