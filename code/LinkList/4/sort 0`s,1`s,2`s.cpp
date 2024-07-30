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

void sortZeroOneTwo(Node* &head){
    int zero = 0;
    int one = 0;
    int two = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zero++;
        }else if(temp->data == 1){
            one++;
        }else{
            two++;
        }
        temp = temp->next;
    }

    temp = head;
   
        while(zero--){
            temp->data = 0;
            temp = temp->next;
        }

        while(one--){
            temp->data = 1;
            temp = temp->next;
        }

        while(two--){
            temp->data = 2;
            temp = temp->next;
        }
    
}

Node* sort2(Node* &head){

    if(head == NULL){
        cout << "LL is empty" << endl;
        return NULL;
    }

    if(head->next == NULL){
        return head;
    }
    
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            // zero node sepret
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            zeroTail->next = temp;
            zeroTail = temp;

        }
        else if(curr->data == 1){

            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            oneTail->next = temp;
            oneTail = temp;

        }
        else if(curr->data == 2){
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            twoTail->next = temp;
            twoTail = temp;

        }
    }

    // join link list
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    if(oneHead != NULL){
        zeroTail->next = oneHead;
        if(twoHead != NULL){
            oneTail->next = twoHead;
        }
    }else{
        if(twoHead != NULL){
            zeroTail->next = twoHead;
        }
    }

    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;
    

    // remove dumi node

    // return head

    return zeroHead;


}

int main(){
 
    Node* head = NULL;

    Node* tail = NULL;

    insertTail(head, tail, 1);
    insertTail(head, tail, 0);
    insertTail(head, tail ,2);
    insertTail(head , tail ,1);
    insertTail(head, tail, 0);
    insertTail(head, tail ,1);
    insertTail(head , tail , 2);

    print(head);

    cout << endl;

    // sortZeroOneTwo(head);
    head = sort2(head);

 
    print(head);
   

    return 0;
}