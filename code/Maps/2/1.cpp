#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* child[26];
    bool isTerminal;

    TrieNode(char d){
        this->data = d;
        // child = new TrieNode[26];
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }

        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root , string word){
    // cout << "Inserting : " << word << endl;
    // base case
    int size = word.size();
    if(size == 0){
        root->isTerminal = true;
        return;
    }
    
    char ch = word[0];
    int index = ch - 'a';

    TrieNode* children;

    if(root->child[index] != NULL){
        // present
        children = root->child[index];
    }else{
        // not present, create
        children = new TrieNode(ch);
        root->child[index] = children;
    }

    insertWord(children , word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* children;

    if(root->child[index] != NULL){
        children = root->child[index];
    }else{
        return false;
    }

    return searchWord(children , word.substr(1));



}

void storeSuggestion(TrieNode* curr , vector<string>& temp, string &prefix){
    if(curr->isTerminal){
        temp.push_back(prefix);
    }

    // a to z choices dedo
    for(char ch = 'a'; ch <= 'z'; ch++){
        int index = ch - 'a';

        TrieNode* next = curr->child[index];

        if(next != NULL){
            // if child exits
            prefix.push_back(ch);
            storeSuggestion(next , temp ,prefix);
            prefix.pop_back();
        }
    }

}


vector<vector<string>> getSuggestions(TrieNode* root , string input){

    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for(int i = 0; i < input.size(); i++){
        char lastch = input[i];

        int index = lastch - 'a';
        TrieNode* curr = prev->child[index];

        if(curr == NULL){
            break;
        }else{
            vector<string> temp;
            prefix.push_back(lastch);
            storeSuggestion(curr , temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
    }
    return output;
}

int main(){

    vector<string> v;

    v.push_back("love");
    v.push_back("lover");
    v.push_back("loving");
    v.push_back("last");
    v.push_back("lost");
    v.push_back("lane");
    v.push_back("lord");

    string input = "lovi";

    TrieNode* root = new TrieNode('-');

    for(int i = 0; i < v.size(); i++){
        insertWord(root , v[i]);
    }

    vector<vector<string>> ans = getSuggestions(root , input);

    cout << "printing the ans: " << endl;

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
             cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // TrieNode* root = new TrieNode('-');
    
    // insertWord(root , "CODING");
    // // insertWord(root , "MEETING");
    // insertWord(root , "CODE");
    // insertWord(root , "CODER");
    // insertWord(root , "CODEHELP");
    // insertWord(root , "BABA");
    // insertWord(root , "BABY");
    // insertWord(root , "BABBAR");
    // insertWord(root , "BABU");
    // insertWord(root , "SHONA");

    // if(searchWord(root , "CODING")){
    //     cout << "present" << endl;
    // }else{
    //     cout << "not present" << endl;
    // }

    return 0;
}