#include<iostream>
#include<stack>
using namespace std;

int main(){
    // // create
    // stack<int> st;

    // // insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // // remove
    // st.pop();

    // // pick element
    // cout << "top element : " << st.top() << endl;

    // // size
    // cout << "size : " << st.size() << endl;

    // // empty cheak
    // if(st.empty()){
    //     cout << "empty" << endl;
    // }else{
    //     cout << "not empty" << endl;
    // }

     // create
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    

    return 0;
}