#include<bits/stdc++.h>
using namespace std;

int findSqrt(int n){
    int s = 0;
    int e = n;
    int m = s + (e - s)/2;
    int ans= -1;

    while(s <= e){
        if(m*m == n){
            return m;
        }

        if(m*m > n){
            e = m - 1;
        }else{
            ans = m;
            s = m + 1;
        }
        m = s + (e - s)/2;
    }
    return ans;
}

bool findEle(int arr[][4] , int rows , int col , int target){
    int s = 0;
    int e = rows*col - 1;
    int m = s + (e - s)/2;

    while (s <= e)
    {
        int rowele = m / col;
        int colele = m % col;
        int element = arr[rowele][colele];

        if(element == target){
            return true;
        }
        
        if(element > target){
            e = m - 1;
        }else{
            s = m + 1;
        }
        m = s + (e - s)/2;
    }

    return false;
    
}

int main(){
    // int n;
    // cout << "enter the number " << endl;
    // cin >> n;

    // int ans = findSqrt(n);
    // cout << "Answer : " << ans << endl;

    // int precision;
    // cout << "enter the precision" << endl;
    // cin >> precision;

    // double step = 0.1;
    // double finalAns = ans;
    // for(int i = 0; i < precision; i++){
    //     for(double j = finalAns; j *j <= n; j = j +step){
    //         finalAns = j;
    //     }
    //     step = step/10;
    // }

    // cout << "final ans : " << finalAns << endl;

    int arr[5][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};

    int rows =  5;
    int col = 4;

    int target = 19;

    bool ans = findEle(arr , rows , col ,target);

    if(ans){
        cout << "found" << endl;
    }else{
        cout << "not found" << endl;
    }
    return 0;
}