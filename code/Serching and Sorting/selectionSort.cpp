#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{6,7,2,3,4,1};
    int n = arr.size();
    

    for(int i = 0; i < n-1; i++){

        int minele = i;
        for(int j = i+1; j < n; j++){
            
            if(arr[minele] > arr[j]){
                minele = j;
            }
        }
        swap(arr[i] , arr[minele]);
        
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}