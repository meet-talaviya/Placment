#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        cout << "delete" << endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
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
    head->prev = newNode;
    head = newNode;
}

void insertTail(Node* &head , Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertPosition(int Position , Node* &head, Node* &tail , int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(Position == 1){
        insertHead(head , tail , data);
        return;
    }

    int len = getLength(head);

    if(Position > len){
        insertTail(head , tail , data);
        return;
    }

    int i = 1;
    Node* prevNode = head;

    while(i < Position - 1){
        prevNode = prevNode->next;
        i++;
    }

    Node* curr = prevNode->next;

    Node* newNode = new Node(data);

    prevNode->next = newNode;
    newNode->prev = prevNode;
    curr->prev = newNode;
    newNode->next = curr;
}

void deleteNode(int Position , Node* &head , Node* &tail){
    if(head == NULL){
        cout << "LL is empty" << endl;
        return;
    }

    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(Position == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);

    if(Position > len){
        cout << "not a vailad Position" << endl;
    }

    if(Position == len){
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    int i = 1;
    Node* left = head;

    while(i < Position - 1){
        left = left->next;
        i++;
    }

    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;

     
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertHead(head , tail , 10);
    insertHead(head , tail , 20);

    insertTail(head , tail , 501);

    insertPosition(2 , head , tail , 401);
    print(head);

    deleteNode(2 , head , tail);
    print(head);

    return 0;
}