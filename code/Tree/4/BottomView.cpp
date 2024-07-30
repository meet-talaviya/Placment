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

void printBottomView(Node* root){
    if(root == NULL){
        return;
    }
 
    // create a map stroing HD->TopNode->data
    map<int ,int> topNode;

    // Level Oreder
    queue<pair<Node* ,int>> q;

    q.push(make_pair(root , 0));

    while(!q.empty()){
        pair<Node* ,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
        
       
         // create entry
        topNode[hd] = frontNode->data;
  

        if(frontNode->left){
            q.push(make_pair(frontNode->left , hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right , hd+1));
        }

    }

    // ab ans map me store

    cout << "printing ans : " << endl;

    for(auto i : topNode){
        cout << i.first << "->" << i.second << endl;
    }

}

int main()
{
    Node *root = NULL;

    root = bulidTree();

    // levelOrderTra(root);
    printBottomView(root);

    return 0;
}