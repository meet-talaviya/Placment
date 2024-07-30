#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[101];
    int size;

    Heap(){
         size = 0;
    }

    void insert(int value){
        // value insert karo end me
        size = size + 1;
        int index = size;
        arr[index] = value;

        // iss value place in right(correct) position
        while(index > 1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index] , arr[parentIndex]);
                index = parentIndex;
            }else{
                break;
            }
        }
    }

    int deleteValue(){
        //  replce root node value in last node value
        int ans = arr[1];
        arr[1] = arr[size];
        size--;

        // replce root node data in right place
        int index = 1;

        while(index < size){
            int childLeft = 2*index;
            int childRight = 2*index + 1;

            int largest = index;

            if(childLeft < size && arr[largest] < arr[childLeft]){
                largest = childLeft;
            }

            if(childRight < size && arr[largest] < arr[childRight]){
                largest = childRight;
            }

            if(largest == index){
                // value correct position
                break;
            }else{
                swap(arr[index] , arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

int main(){
    Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;
    // h.size = 5;

    // cout << "printing the heap : " << endl;

    // for(int i = 0; i <= h.size; i++){
    //     cout << h.arr[i] << " ";
    // }cout << endl;

    // h.insert(110);

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);


    cout << "printing the heap : " << endl;

    for(int i = 0; i <= h.size; i++){
        cout << h.arr[i] << " ";
    }cout << endl;


    return 0;
}