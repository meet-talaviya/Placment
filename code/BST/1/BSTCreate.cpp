#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class NodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool vaildBST;

    NodeData(){};

    NodeData(int size, int max , int min , bool vaild){
        this->size = size;
        minVal = min;
        maxVal = max;
        vaildBST = vaild;
    }
};

Node* insertIntoBST(Node* root , int data){
    if(root == NULL){
        //  this is the first Node
        root = new Node(data);
        return root;
    }

    // no first node
    if(root->data > data){
        // left insert
        root->left = insertIntoBST(root->left , data);
    }else{
        // right insert
        root->right = insertIntoBST(root->right , data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root , data);
        cin >> data;
    }
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

void preOrder(Node* root){
    // NLR
    if(!root){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(Node* root){
    // LNR
    if(!root){return;}

    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
}


void postOrder(Node* root){
    // LRN
    if(!root){return;}

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

Node* findNode(Node* root, int target){
    if(!root) return NULL;

    if(root->data == target){
        return root;
    }
    
    if(root->data < target){
       return findNode(root->right , target);
    }else{
       return findNode(root->left , target);
    }
}

int minVal(Node* root){
    Node* temp = root;
    if(!root) return -1;

    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node* root){
    Node* temp = root;
    if(!root) return -1;

    while(temp->right){
        temp = temp->right;
    }
    return temp->data;
}

// Node* deleteNodeBST(Node* root , int target){
//     if(!root) return NULL;

//     Node* temp = findNode(root , target);

//     // delete
//     if(temp->left == NULL && temp->right == NULL){
//         delete temp;
//         return NULL;
//     }
//     else if(temp->left == NULL && temp->right != NULL){
//         Node* child = temp->right;
//         delete temp;
//         return child;
//     }
//     else if(temp->left != NULL && temp->right == NULL){
//         Node* chlid = temp->left;
//         delete temp;
//         return chlid;
//     }
//     else{
//         // I.P. 
//         int inPre = maxVal(temp->left);
//         temp->data = inPre;
//         temp->left = deleteNodeBST(temp->left , inPre);
//         return root;
//     }
// }

Node* deleteNodeBST(Node* root , int target){
    if(!root) return NULL;

    if(root->data == target){
         if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
         }
         else if(root->left == NULL && root->right != NULL){
            Node* child = root->right;
            delete root;
            return child;
         }
         else if(root->left != NULL && root->right == NULL){
            Node* child = root->left;
            delete root;
            return child;
         }
         else{
            // both child
            int inOrd = maxVal(root->left);
            root->data = inOrd;
            root->left = deleteNodeBST(root->left , inOrd);
            return root;

         }
    }
    else if(root->data < target){
        // right
        root->right =  deleteNodeBST(root->right , target);
    }else if(root->data > target){
        // left
        root->left = deleteNodeBST(root->left , target);
    }
    return root;
}

Node* bstUsingInorder(int inOrder[] ,int s , int e){
    if(s > e){
        return NULL;
    }

    int m = (s+e)/2;
    int ele = inOrder[m];
    Node* root = new Node(ele);

    root->left = bstUsingInorder(inOrder , s, m-1);
    root->right = bstUsingInorder(inOrder , m+1, e);

    return root;
}

void convertIntoSortedDLL(Node* root , Node* &head){
    if(root == NULL){
        return;
    }

    // right subtree convert
    convertIntoSortedDLL(root->right , head);

    // atach root node
    root->right = head;
    
    if(head != NULL){
        head->left = root;
    }

    // upadte head
    head = root;

    // left subtree 
    convertIntoSortedDLL(root->left , head);

}

void printLL(Node* head){
    Node* temp = head;
    cout << endl;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

Node* sortedLLTOBST(Node* &head , int n){
    // base case
    if(n <= 0 || head == NULL){
        return NULL;
    }

    Node* leftSubTree = sortedLLTOBST(head , n/2);

    Node* root = head;
    root->left = leftSubTree;

    head = head->right;

    root->right = sortedLLTOBST(head ,n-1-n/2);

    return root;
}

NodeData findLargestBST(Node* root, int &ans){
    if(root == NULL){
        NodeData temp(0 , INT_MIN , INT_MAX, true);
        return temp;
    }

    NodeData leftAns = findLargestBST(root->left , ans);
    NodeData rightAns = findLargestBST(root->right , ans);

    // checking 
    NodeData currNodeAns;

    currNodeAns.size = leftAns.size + rightAns.size + 1;
    currNodeAns.maxVal = max(root->data , rightAns.maxVal);
    currNodeAns.minVal = min(root->data , leftAns.minVal);

    if(leftAns.vaildBST && rightAns.vaildBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
        currNodeAns.vaildBST = true;
    }else{
        currNodeAns.vaildBST = false;
    }

    if(currNodeAns.vaildBST){
        ans = max(ans , currNodeAns.size);
    }

    return currNodeAns;
}

int main(){
    // Node* root = NULL;
    // cout << "Enter the data for Node" << endl;
    // takeInput(root);
    // cout << "printing the tree" << endl;

    // levelOrderTraversal(root);

    // cout << "pre" << endl;
    // preOrder(root);

    // cout << "in" << endl;
    // inOrder(root);

    // cout << "post" << endl;
    // postOrder(root);
 
    // int target = 15;
    // bool ans = findNode(root , target);

    // if(ans){
    //     cout << "present" << endl;
    // }else{
    //     cout << "not present" << endl;
    // }

    // int min = minVal(root);
    // cout << "min val : " << min << endl;

    // int max = maxVal(root);
    // cout << "max val : " << max << endl;
    
    // int target = 100;
    // root = deleteNodeBST(root , target);

    // cout << "printing after delete node the tree" << endl;

    // int inOrder[] = {1,2,3,4,5,6,7,8,9};

    // int s = 0;
    // int e = 8;

    // Node* root = bstUsingInorder(inOrder , s , e);

    // levelOrderTraversal(root);
    
    // cout << "printing : " << endl;
    // Node* head = NULL;
    // convertIntoSortedDLL(root , head);

    // printLL(head);

    // Node* root1 = NULL;
    // root1 = sortedLLTOBST(head , 9);

    // cout << "printing : " << endl;

    // levelOrderTraversal(root1);

    // Node* root = NULL;
    // cout << "Enter the data for Node" << endl;
    // takeInput(root);

    Node* root = new Node(50);
    Node* first = new Node(30);
    Node* second = new Node(60);
    Node* third = new Node(5);
    Node* forth = new Node(20);
    Node* fifth = new Node(45);
    Node* six = new Node(70);
    Node* seven = new Node(65);
    Node* eight = new Node(80);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = forth;
    second->left = fifth;
    second->right = six;
    six->left = seven;
    six->right = eight;
    


    cout << "printing the tree" << endl;

    levelOrderTraversal(root);
    cout << endl;

    int ans = 0;
    findLargestBST(root , ans);

    cout << "Largest Bst size : " << ans << endl;



    return 0;
}