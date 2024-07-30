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

void printRightView(Node* root , vector<int>& ans, int level){
    if(root == NULL){
        return;
    }

    int n = ans.size();
    if(level == n){
        ans.push_back(root->data);
    }

    printRightView(root->right , ans , level+1);

    printRightView(root->left , ans , level+1);

}

int main()
{
    Node *root = NULL;

    root = bulidTree();

    vector<int> ans;
    int level = 0;
    printRightView(root ,ans ,level);

    cout << "print Left view : " << endl;

    for(auto i : ans){
        cout << i << " ";
    }

    // 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1

    return 0;
}