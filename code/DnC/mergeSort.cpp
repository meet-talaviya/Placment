#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    // copy values
    int k = s;
    for(int i = 0; i < len1; i++){
        left[i] = arr[k];
        k++;
    }
  
    k = mid+1;
    for(int i = 0; i < len2; i++){
        right[i] = arr[k];
        k++;
    }

    // merge 2 sorted array
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex < len1 && rightIndex < len2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // left copy array
    while(leftIndex < len1){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    } 

    // right copy
    while(rightIndex < len2){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }


}

void mergeSort(int arr[] , int s , int e){
    // base case
    if(s >= e){
        return;
    }

    // left part sort 
    int mid = (s+e)/2;
    mergeSort(arr , s , mid);

    // right part
    mergeSort(arr , mid+1, e);

    // merge 2 sorted array
    merge(arr , s , e);
}

int main(){
    int arr[] = {4 ,5 , 1, 2,12,4,3,4,3,2,1,56};
    int n = 12;

    int s = 0; 
    int e = n-1;

    mergeSort(arr , s , e);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
