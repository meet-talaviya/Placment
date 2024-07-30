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

bool kthAnctor(Node *root , int &k , int p){
    if(root == NULL){
        return false;
    }

    if(root->data == p){
        return true;
    }

    if(k == 0){
        return false;
    }

    bool lefta = kthAnctor(root->left , k , p);
    bool righta = kthAnctor(root->right , k ,p);

    if(lefta == true || righta == true){
        k--;
    }

    if(k == 0){
        cout << "Answer : " << root->data << endl;
        k = -1;
    }

    return lefta || righta;
}



int main(){
    Node* root = NULL;

    root = bulidTree();
    int k = 1;
    int p = 4;
    if(kthAnctor(root , k , p)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}