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



Node* solve(Node* &head , Node* &head1){

    if(head == NULL){
        return head1;
    }

    if(head1 == NULL){
        return head;
    }
    // reverse both LL
    head = reverse(head);
    // print(head);
    // cout << endl;
    head1 = reverse(head1);
    // print(head1);
    // cout << endl;

    // add

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;

    while(head != NULL && head != NULL){
        // calulte sum
         int sum = carry + head->data + head1->data;
         int digit = sum % 10;
         carry = sum/10;

        //  crete a new node for the digit
         Node* newNode = new Node(digit);
        //  attach the newnode into the answer wali linked list
         if(ansHead == NULL){
            // firat node insert krre ho
            ansHead = newNode;
            ansTail = newNode;
         }else{
            ansTail->next = newNode;
            ansTail = newNode;
         }
         head = head->next;
         head1 = head1->next;
    }

    while(head != NULL){
        int sum = carry + head->data;
        int digit = sum % 10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head = head->next;

    }

     while(head1 != NULL){
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;

    }

    // carry
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    

    // ans revesr LL

    // print(ansHead);
    // cout << endl;

    ansHead = reverse(ansHead);
    // print(ansHead);
    // cout << endl;
    return ansHead;

}


int main(){
 
    Node* head = NULL;

    Node* tail = NULL;

    insertTail(head, tail, 2);
    insertTail(head, tail, 4);
    insertTail(head, tail ,2);

    Node* head1 = NULL;
    Node* tail1 = NULL;
    insertTail(head1 , tail1 ,2);
    insertTail(head1, tail1, 3);
    insertTail(head1, tail1 ,4);
    // insertTail(head1 , tail1 , 2);

    print(head);

    cout << endl;

    print(head1);

    cout << endl;

    Node* ans = solve(head , head1);

    print(ans);


   

    return 0;
}