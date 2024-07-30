#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "aabc";
    int freq[26] = {0};

    queue<char> q;

    string ans = "";
    int n = str.size();

    for(int i = 0; i < n; i++){
        char ch = str[i];

        // inc freq
        freq[ch - 'a']++;

        q.push(ch);

        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }

    } 

    cout << ans << endl;

    return 0;
}