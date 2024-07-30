#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> m;

    // insertion

    pair<string , int> p = make_pair("Scorpio" , 9);
    m.insert(p);

    pair<string , int> p2("alto" , 10);
    m.insert(p2);

    m["fortuner"] = 11;

    // access
    cout << m.at("alto") << endl;
    cout << m.at("Scorpio") << endl;

    cout << m["fortuner"] << endl;

    // search

    cout << m.count("Scorpio") << endl;
    cout << m.count("inova") << endl;

    // find

    if(m.find("fortuner") != m.end()){
        cout << "found" << endl;
    }else{
        cout << "not found" << endl;
    }

    // size

    cout << m.size() << endl;

    cout << m["hummer"] << endl;

    cout << m.size() << endl;

    cout << "printing all entry : " << endl;

    for(auto i : m){
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
