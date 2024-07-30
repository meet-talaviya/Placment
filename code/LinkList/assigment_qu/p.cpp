#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = data;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertTail(Node* &head , Node* &tail , int data){
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

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int getLen(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void getEle(Node* &head , int &pos , int &ans){
    head = reverse(head);
    int l = getLen(head);

    int len = 0;
 

    Node* temp = head;
    while(temp != NULL && l >= len){
        len++;
        if((pos+1) == len){
            ans = temp->data;
            return;
        }
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertTail(head , tail , 10);
    insertTail(head , tail , 20);
    insertTail(head , tail , 30);
    insertTail(head , tail , 40);
    insertTail(head , tail , 50);

    print(head);
    cout << endl;

    
    // print(head);
    
    // cout << endl;
    // int len = getLen(head);
    // cout << len << endl;

    int pos = 3;
    int ans = -1;
    getEle(head , pos , ans);

    cout << ans << endl;


    return 0;
}