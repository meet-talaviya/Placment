#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> arr , int s , int e , int x){
    int m = s + (e-s)/2;

    while(s <= e){
        if(arr[m] == x){
            return m;
        }else if(arr[m] > x){
            e = m - 1;
        }else{
            s = m  + 1;
        }
        m = s + (e-s)/2;
    }
    return -1;
}

int Exp(vector<int> arr , int x){
    if(arr[0] == x){
        return 0;
    }
    int n = arr.size();
    int i = 1;
    while(i < n && arr[i] <= x){
        i = i*2;
    }
    return bs(arr , i/2, min(i , n-1),x);
}

int main(){
    vector<int> arr{3,4,5,6,11,13,14,15,56,70};
    int x = 70;
    int ans = Exp(arr , x);
    cout << ans << endl;
    return 0;
}