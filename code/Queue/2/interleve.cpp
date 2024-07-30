#include<bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int> &q){
    int n = q.size();
    int k = n/2;
    int count = 0;

    if(n == 0){
        return;
    }

    queue<int> q2;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(k == count){
            break;
        }

    }

    while(!q.empty() && !q2.empty()){
         int temp1 = q2.front();
         q2.pop();
         q.push(temp1);
         int temp2 = q.front();
         q.pop();
         q.push(temp2);
    }

    // odd length case
    if(n & 1){
        int temp1 = q.front();
        q.pop();

        q.push(temp1);
    }

}

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    interleaveQueue(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}