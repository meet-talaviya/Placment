#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    cout << "size of queue : " << q.size() << endl;

    q.pop();

    cout << "size of queue : " << q.size() << endl;
  
    if(q.empty()){
        cout << "queue is empty" << endl;
    }else{
        cout << "queue is not empty" << endl;
    }

    cout << "forent element : " << q.front() << endl;


    return 0;
}