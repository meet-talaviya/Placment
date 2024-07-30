#include<bits/stdc++.h>
using namespace std;

bool checkCirculer(Node* head){
     unordered_map<Node* , bool> m;
     Node* temp = head;

     while(temp != NULL){
        if(m.find(temp) != m.end()){
            m[temp] = true;
        }else{
            return true;
        }
        temp = temp->next;
     }
     return false;
}

int main(){
    string str = "thiruvananthapuram";
    unordered_map<char , int> m;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        m[ch]++;
    }

    for(auto i : m){
        cout << i.first << "->" << i.second << endl;
    }
    return 0;
}