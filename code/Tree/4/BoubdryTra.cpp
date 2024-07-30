#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *bulidTree()
{
    int data;
    cout << "Enter the data: " << endl;

    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // step A,B,c
    Node *root = new Node(data);

    cout << "Enter data for left part : " << data << " node " << endl;
    root->left = bulidTree();

    cout << "Enter data for right part : " << data << " node " << endl;

    root->right = bulidTree();

    return root;
}



void printLeftBou(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    cout << root->data << " ";
    if(root->left){
          printLeftBou(root->left);
    }
    else{
        printLeftBou(root->right);
    }
 
}

void printLeafBou(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }

    printLeafBou(root->left);
    printLeafBou(root->right);
}

void printRightBou(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }
 

    if(root->right){
         printRightBou(root->right);
    }else{
         printRightBou(root->left);
    }
   

    cout << root->data << " ";
}

void boundryTra(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    printLeftBou(root->left);
    printLeafBou(root);

    printRightBou(root->right);
}

int main()
{
    Node *root = NULL;

    root = bulidTree();

    boundryTra(root);

    // 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1

    // 10 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1
    return 0;
}