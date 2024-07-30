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

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			} 
		}
		
		
	}
}



int findPos(int arr[] , int n , int element){
    for(int i = 0; i < n; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

Node* bulidPreIn(int inorder[] , int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd){
    // base case
    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    // step A
    int element = preorder[preIndex++];

    Node* root = new Node(element);

    int pos = findPos(inorder , size , element);

    // step B
    root->left = bulidPreIn(inorder , preorder , size , preIndex, inorderStart, pos-1);

    // step C right
    root->right = bulidPreIn(inorder , preorder , size , preIndex, pos+1 , inorderEnd);

    return root;


}



int main(){
    // Node* root = NULL;

    // root = bulidTree();

    // levelOrderTra(root);

    int inorder[] = {40,20,50,10,60,30,70};
    int preorder[] = {10,20,40,50,30,60,70};

    int size = 7;
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    Node* roots = bulidPreIn(inorder , preorder , size , preIndex, inorderStart, inorderEnd);
    levelOrderTraversal(roots);


    return 0;
}