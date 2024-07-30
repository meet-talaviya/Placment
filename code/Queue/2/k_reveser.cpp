#include<bits/stdc++.h>
using namespace std;

void reverseK(queue<int> &q , int k){
   
    stack<int> s;
    int count = 0;
    int n = q.size();

    if(k <= 0 || k > n){
        return; 
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k){
            break;
        }
    }

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    count = 0;
    while(!q.empty() && n-k != 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k){
            break;
        }
    }
    
}

int main(){
    queue<int> q;

    q.push(3);
    q.push(6);
    q.push(12);
    q.push(13);
    q.push(15);

    int k = 6;

    reverseK(q , k);

    cout << "printing" << endl;

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}