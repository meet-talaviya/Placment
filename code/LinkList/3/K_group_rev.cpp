#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout << "delete" << endl;
    }
};

void print(Node* &head){
   Node* temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   
}

void insertHead(Node* &head , Node* &tail, int data){
 
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // LL is not empty
    Node* newNode = new Node(data);

    newNode->next = head;

    head = newNode;

}

void insertTail(Node* &head, Node* &tail , int data){
    
    // LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);

    tail->next = newNode;
    
    tail = newNode;

}

int findLen(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertMiddal(int position , Node* &head , Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // step-1 : find prev and curr

    if(position == 0){
        insertHead(head , tail , data);
        return;
    }

    int len = findLen(head);
    if(position >= len){
        insertTail(head , tail, data);
        return;
    }

    int i = 1;
    Node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;

    // strp-2
    Node* newNode = new Node(data);

    // step-3;
    newNode->next = curr;

    // step-4
    prev->next = newNode;
}

void deleteNode(int position , Node* &head, Node* tail){
    if(head == NULL){
        cout << "Empty LL" << endl;
        return; 
    }
 
//  first
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

// last
    int len = findLen(head);

    if(position == len){

        int i = 1;
        Node* prev = head;

        while(i <position-1){
            prev = prev->next;
            i++;
        }

        prev->next = NULL;

        Node* temp = tail;

        tail = prev;
        delete temp;
        return;
    }

    // middal
 

    int i = 1;
    Node* prev = head;

    while(i <position-1){
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;

}

Node* K_Group_rev(Node* &head , int k){
    if(head == NULL){
        return NULL;
    }

    int len = findLen(head);
    if(k > len){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = curr->next;

    int count = 0;

    while(count < k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;

    }

    if(nextNode != NULL){
      
        Node* answer = K_Group_rev(nextNode , k);
        head-> next = answer;
    }

    return prev;



}

int main(){
    // Node* head = new Node(10);
    Node* head = NULL;

    Node* tail = NULL;
    insertHead(head, tail, 20);
    insertHead(head, tail ,30);
    insertHead(head, tail, 40);
    insertHead(head, tail ,50);
    insertHead(head, tail, 60);
    insertHead(head, tail ,70);

    print(head);
    cout << endl;

    int k = 3;
    head = K_Group_rev(head , k);

    print(head);

   

    
    return 0;
}