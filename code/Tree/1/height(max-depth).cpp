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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
 
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight , rightHeight) + 1;
    return ans;
}

int main()
{
    Node *root = NULL;

    root = bulidTree();

    // levelOrderTra(root);
    int h = height(root);

    cout << "height : " << h << endl;

    return 0;
}