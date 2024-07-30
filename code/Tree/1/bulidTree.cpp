#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* bulidTree(){
    int data;
    cout << "Enter the data: " << endl;

    cin >> data;

    if(data == -1){
        return NULL;
    }

    // step A,B,c
    Node* root = new Node(data);

    cout << "Enter data for left part : " << data << " node " << endl;
    root->left = bulidTree();

    cout << "Enter data for right part : " << data << " node " << endl;

    root->right = bulidTree();

    return root;
}



int main(){
    Node* root = NULL;

    root = bulidTree();

    // levelOrderTra(root);

    return 0;
}