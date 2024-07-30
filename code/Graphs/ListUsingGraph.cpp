#include<bits/stdc++.h>
using namespace std;
template <typename T>

class Graph{
    public:
    unordered_map<T , list<T>> adjList;

    void addEage(T u , T v, bool direction){
        // d = 0 - undirection 
        // d = 1 - dirction

        // u ---> v
        adjList[u].push_back(v);
        if(direction == 0){
            // v ---> u
            adjList[v].push_back(u);
        }
    }

    void printList(){
        for(auto node : adjList){
            cout << node.first << "->";
            for(auto neighbours : node.second){
                cout << neighbours << " ";
            }
            cout << endl;
        }
    }

    void bfs(T src ,unordered_map<T , bool>& visited){
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            for(auto neighbour : adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src , unordered_map<T , bool>& visited){
        cout << src << " ";
        visited[src] = true;

        for(auto neig : adjList[src]){
            if(!visited[neig]){
                dfs(neig , visited);
            }
        }
    }

    bool checkCyclicUsingBfs(T src ,  unordered_map<T , bool>& visited){
        queue<T> q;
        unordered_map<int , int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }else{
                    // already visited
                    if(visited[nbr] && nbr != parent[frontNode]){
                        // cycle presnt
                        return true;
                    }
                }
            }
        }
        return false;
    }

    
};

int main(){

    
    // // undirections
    // Graph g;
    // g.addEage(0,1,0);
    // g.addEage(1,2,0);
    // g.addEage(0,2,0);
  
    // cout << endl;
    // g.printList();

    // directions
    // Graph g;
    // g.addEage(0,1,1);
    // g.addEage(1,2,1);
    // g.addEage(0,2,1);
  
    // cout << endl;
    // g.printList();

    // Graph<char> g;

    // g.addEage('a' , 'b', 0);
    // g.addEage('b' , 'c', 0);
    // g.addEage('a', 'c' , 0);
    // g.printList();

    Graph <int> g;
    int n = 5; // number of nodes in graph
    g.addEage(0,1,0);
    g.addEage(1,2,0);
    g.addEage(2,3,0);
    g.addEage(3,4,0);
    g.addEage(4,0,0);
    // g.addEage(3,5,0);
    // g.addEage(7,6,0);
    // g.addEage(7,4,0);

    g.printList();

    cout << endl;

    bool ans = false;
    unordered_map<int , bool> visited;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans = g.checkCyclicUsingBfs(i , visited);

            if(ans == true){
                break;
            }
        }
    }

    if(ans){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    // unordered_map<int , bool> visited;

    // for(int i = 0; i < n; i++){
    //     if(!visited[i]){
    //         g.bfs(i , visited);
    //     }
  
    // }

    // cout << endl;
    // unordered_map<int , bool> visited2;

    // cout << "printing DFS: " << endl;
    // for(int i = 0; i < n; i++){
    //     if(!visited2[i]){
    //         g.dfs(i , visited2);
    //     }
  
    // }
    
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// class Graph{
//     public:
//     unordered_map<int , list<pair<int,int>>> adjList;

//     void addEage(int u , int v, int weight, bool direction){
//         // d = 0 - undirection 
//         // d = 1 - dirction

//         // u ---> v
//         adjList[u].push_back({v , weight});
//         if(direction == 0){
//             // v ---> u
//             adjList[v].push_back({u , weight});
//         }
//     }

//     void printList(){
//         for(auto node : adjList){
//             cout << node.first << "->";
//             for(auto neighbours : node.second){
//                 cout <<"[" << neighbours.first << "," << neighbours.second << "]" << ", " ;
//             }
//             cout << endl;
//         }
//     }
// };

// int main(){

    
//     // // undirections
//     // Graph g;
//     // g.addEage(0,1,0);
//     // g.addEage(1,2,0);
//     // g.addEage(0,2,0);
  
//     // cout << endl;
//     // g.printList();

//      // directions
//     Graph g;
//     g.addEage(0,1,5,1);
//     g.addEage(1,2,7,1);
//     g.addEage(0,2,3,1);
  
//     cout << endl;
//     g.printList();

//     return 0;
// }