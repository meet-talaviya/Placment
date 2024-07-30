#include<bits/stdc++.h>
using namespace std;

// void reverseQ(queue<int> &q){
//     stack<int> s;

//     while (!q.empty())
//     {
//         int ele = q.front();
//         q.pop();

//         s.push(ele);
//     }

//     while(!s.empty()){
//         int el = s.top();
//         s.pop();

//         q.push(el);
//     }
    
// }

void reverseQ(queue<int> &q){
    if(q.empty()){
        return;
    }

    int t = q.front();
    q.pop();

    reverseQ(q);

    q.push(t);
}

int main(){
    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQ(q);

    cout << "printing : " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
   return 0;
}