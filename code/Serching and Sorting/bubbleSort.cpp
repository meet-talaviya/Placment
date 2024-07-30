#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{10,1,7,6,14,9};

    int n = arr.size();

    for(int i = 0; i < n-1; i++){
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                flag = true;
                swap(arr[j] , arr[j+1]);
            }
        }
        if(flag == false){
            break;
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}