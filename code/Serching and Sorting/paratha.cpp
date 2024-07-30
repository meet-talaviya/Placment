#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> rating , int mid, int paratha){
     int currP = 0;
     int n = rating.size();
     for(int i = 0; i < n; i++){
        int R = rating[i], j = 1;
        int timeTaken = 0;

        while (true)
        {
            if(timeTaken + j * R <= mid){
                currP++;
                timeTaken += j * R;
                j++;
            }else{
                break;
            }
        }
        if(currP >= paratha){
            return true;
        }
        
     }
     return false;
}

int findParatha(vector<int> rating , int paratha){
    int start = 0;
    int n = rating.size();

    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        maxi = max(maxi,rating[i]);
    }

    int sum = 0;
    for(int i = 1; i <= paratha; i++){
         sum += i;
    }

    int end = maxi * sum;
    // cout << end;

    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end){
        if(isPossible(rating , mid , paratha)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    vector<int> rating{1,1,1,1,1,1,1,1};
    int paratha = 8;

    int ans = findParatha(rating , paratha);

    cout << ans << endl;
    return 0;
}