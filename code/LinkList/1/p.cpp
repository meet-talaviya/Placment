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

void insertHead(Node* &head, Node* &tail, int data){

    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;

}

void insertTail(Node* &head, Node* &tail, int data){
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
        len++;
        temp = temp->next;
    }
    return len;
}

void insertMiddal(int position , Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 0){
        insertHead(head , tail , data);
        return;
    }

    int len = findLen(head);

    if(position >= len){
        insertTail(head , tail , data);
        return;
    }

    int i = 1;
    Node* prev = head;

    while(i < position){
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;

    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}

void deleteNode(int position, Node* &head , Node* &tail){
    if(head == NULL){
        cout << "LL is empty" << endl;
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
       
        delete temp;
        return;
    }

    int len = findLen(head);
    if(position == len){
        int i = 1;
        Node* prev = head;

        while (i < position-1)
        {
            prev = prev->next;
            i++;
        }
         
        prev->next = NULL;
        Node* temp = tail;
        tail = prev;
        
        delete temp;
        
    }

    int i = 1;
    Node* prev = head;

    while(i < position-1){
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertHead(head , tail , 10);
    insertHead(head , tail , 20);
    insertHead(head , tail , 30);
    insertHead(head , tail , 40);

    insertTail(head, tail ,101);
    insertTail(head , tail , 500);

    insertMiddal(6,head,tail , 23);

    print(head);

    cout << endl;

    deleteNode(4 , head,tail);

    print(head);

    return 0;
}