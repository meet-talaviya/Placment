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

bool checkPalindrome(Node* &head){

    if(head == NULL){
        cout << "LL is empty" << endl;
        return true;
    }

    if(head -> next == NULL){
        return true;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    Node* rev = reverse(slow->next);

    slow->next = rev;

    Node* temp1 = head;
    Node* temp2 = rev;

    while(temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return true;

}

int main(){
 
    Node* head = NULL;

    Node* tail = NULL;

    insertTail(head, tail, 10);
    insertTail(head, tail, 20);
    insertTail(head, tail ,30);
    insertTail(head , tail , 40);
    insertTail(head, tail, 30);
    insertTail(head, tail ,20);
    insertTail(head , tail , 10);

    print(head);

    bool isPalindrome = checkPalindrome(head);

    cout << endl;

    if(isPalindrome){
        cout << "Palindrome" << endl;
    }else{
        cout << "not Palindrom" << endl;
    }

    return 0;
}