#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "size :" << dq.size() << endl;

    cout << "front : " << dq.front() << endl;
    cout << "back : " << dq.back() << endl;

    return 0;
}