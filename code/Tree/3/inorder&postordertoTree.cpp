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

Node* bulidPostIn(int inorder[] , int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd){
    // base case
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    // step A
    int element = postorder[postIndex];
    postIndex--;

    Node* root = new Node(element);

    int pos = findPos(inorder , size , element);

    // step C right
    root->right = bulidPostIn(inorder , postorder , size , postIndex, pos+1 , inorderEnd);

     // step B
    root->left = bulidPostIn(inorder , postorder , size , postIndex, inorderStart, pos-1);


    return root;


}



int main(){
 
    int inorder[] = {40,20,10,50,30,60};
    int postorder[] = {40,20,50,60,30,10};

    int size = 6;
    int postIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    Node* roots = bulidPostIn(inorder , postorder , size , postIndex, inorderStart, inorderEnd);
    levelOrderTraversal(roots);


    return 0;
}