#include<bits/stdc++.h>
using namespace std;

void solve(int arr[] , int size , int k){
    deque<int> q;

    for(int i = 0 ; i < k; i++){
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    for(int i = k; i < size; i++){
        if(q.empty()){
            cout << 0 << " ";
        }else{
            cout << arr[q.front()] << " ";
        }

        // out of window ele ko remove 
        while(!q.empty() && (i - q.front() >= k)){
            q.pop_front();
        }

        // check current ele for insertion
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    // ans print last window
        if(q.empty()){
            cout << 0 << " ";
        }else{
            cout << arr[q.front()] << " ";
        }

}
int main(){
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int size = 8;
    int k = 3;

    solve(arr , size, k);
    return 0;
}