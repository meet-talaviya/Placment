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
};

void print(Node* &head){
   Node* temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   
}

int main(){
    Node* first = new Node(10);
    Node* first1 = new Node(20);
    Node* first2 = new Node(30);
    Node* first3 = new Node(40);
    Node* first4 = new Node(50);

    first->next = first1;
    first1->next = first2;
    first2->next = first3;
    first3->next = first4;
    
    cout << "Print" << endl;
    print(first);


    return 0;
}