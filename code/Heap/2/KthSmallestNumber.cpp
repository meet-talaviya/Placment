#include<bits/stdc++.h>
using namespace std;

int getKthGreatestEle(int arr[] , int n , int k){
      // create a max heap
    priority_queue<int , vector<int> , greater<int> > pq;

    // insert k ele

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    // for remaing ele push only if they are less then top
    for(int i = k; i < n; i++){
        int ele = arr[i];
        if(ele > pq.top()){
            pq.pop();
            pq.push(ele);
        }
    }
    int ans = pq.top();
    return ans;
}

int getKthSmallestEle(int arr[] , int n , int k){
    // create a max heap
    priority_queue<int> pq;

    // insert k ele

    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }

    // for remaing ele push only if they are less then top
    for(int i = k; i < n; i++){
        int ele = arr[i];
        if(ele < pq.top()){
            pq.pop();
            pq.push(ele);
        }
    }
    int ans = pq.top();
    return ans;
}

int main(){
    int arr[] = {10,5,20,4,15};
    int n= 5;
    int k = 2;

    int ans = getKthSmallestEle(arr , n , k);

    cout << "Ans is : " << ans << endl;

    int ans1 = getKthGreatestEle(arr , n, k);

    cout << "Ans is " << ans1 << endl;
    return 0;
}