#include<bits/stdc++.h>
using namespace std;

int main(){

    // max-heap
    priority_queue<int> pq;

    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "top ele : " << pq.top() << endl;
 
    pq.pop();

    cout << "top ele : " << pq.top() << endl;

    cout << "size : " << pq.size() << endl;

    if(pq.empty()){
        cout << "empty" << endl;
    }else{
        cout << "not empty" << endl;
    }


    return 0;
}