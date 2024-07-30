#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "enter thr number of nodes:" << endl;
    cin >> n;

    vector<vector<int> > adj (n , vector<int>(n ,0));

    int e;
    cout << "enter the number of edges:" << endl;
    cin >> e;
  
     cout << "enter the edges: " << endl;
    for(int i = 0; i < e; i++){
        int u , v;
       
        cin >> u >> v;

        adj[u][v] = 1;
    }
   
    cout << "printing : " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}