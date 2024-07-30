#include<bits/stdc++.h>
using namespace std;

int findPivotEle(vector<int> v){
    int s = 0;
    int e = v.size() - 1;
    int m = s +(e-s)/2;

    while (s <= e)
    {
        if(s == e){
            // singal elment 
            return s;
        }
        if(v[m] > v[m+1] && m<= e){
            return m;
        }
        if(v[m-1] > v[m] && m-1 >= s){
            return m-1;
        }
        if(v[s] > v[m]){
            e = m - 1;
        }else{
            s = m + 1;
        }
        m = s + (e-s)/2;
    }
    return -1;
    
}

int main(){
    vector<int> v{9,10,13};
    int ans = findPivotEle(v);

    if(ans == -1){
        cout << "no found" << endl;
    }else{
        cout << "index : " << ans << endl;
        cout << "element : " << v[ans] << endl;
    }
    return 0;
}