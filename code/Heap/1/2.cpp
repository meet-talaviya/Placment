#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[] , int size , int i){
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i + 1;
    int largest = index;

    if(leftIndex <= size && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }

    if(rightIndex <= size && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }

    if(index != largest){
        swap(arr[index] , arr[largest]);
        index = largest;
        heapify(arr , size , index);
    }
}

void bulidHeap(int arr[] , int n){
    for(int i = n/2; i > 0; i--){
        heapify(arr , n , i);
    }
}

void HeapSort(int arr[] , int n){

    while (n != 1)
    {
        swap(arr[1] , arr[n]);
        n--;

        heapify(arr , n , 1);
    }
    
}

int main(){
    int arr[] = {-1,12,15,13,11,14};
    int n = 5;

    bulidHeap(arr , n);
    cout << "printing the heap : " << endl;

    for(int i = 0; i <= n ; i++){
        cout << arr[i] << " ";
    }cout << endl;

    HeapSort(arr , n);

    cout << "printing the heapSort : " << endl;

    for(int i = 1; i <= n ; i++){
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}