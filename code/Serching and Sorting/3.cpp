#include<bits/stdc++.h>
using namespace std;

// int findNear(vector<int> v , int target){
//     int s = 0;
//     int e = v.size() - 1;
//     int m = s +(e - s)/2;

//     while(s <=e){
//         if(v[m] == target){
//             return m;
//         }
//         if(m - 1 >0 && v[m - 1] == target){
//             return m-1;
//         }
//         if(m + 1 < v.size() && v[m+1] == target){
//             return m + 1;
//         }
//         if(target > v[m]){
//             s = m + 2;
//         }else{
//             e = m - 2;
//         }
//         m = s + (e - s)/2;
//     }
//     return -1;
// }

int findAns(int div , int divisor){
    int s = 0;
    int e = abs(div);
    int m = s+ (e - s)/2;

    int ans = -1;

    while(s <=e){
        if(abs(m*divisor) == abs(div)){
            ans = m;
            break;
        }

        if(abs(m*divisor) > abs(div)){
            e = m - 1;
        }else{
            ans = m;
            s = m + 1;
        }
        m = s + (e - s)/2;
    }
    if((divisor < 0 && div < 0) || (divisor > 0 && div > 0)){
        return ans;
    }else{
        return -ans;
    }
    
}

int solve(vector<int> v){
    int s = 0;
    int e = v.size() - 1;
    int m = s + (e-s)/2;

    while(s <=e){
        if(s == e){
            return s;
        }
        if(m % 2 == 0){
            if(v[m] == v[m+1]){
                s = m + 2;
            }else{
                e = m;
            }
        }else{
            if(v[m] == v[m - 1]){
                s = m + 1;
            }else{
                e = m - 1;
            }
        }
        m = s + (e - s)/2;
    }
    return -1;
}

int main(){
    // vector<int> v{10,3,40,20,50,80,70};
    // int target = 40;

    // int ans = findNear(v, target);
    // cout << ans << endl;

    // int div = 22;
    // int divisor = 7;

    // int ans = findAns(div , divisor);
    // cout << ans << endl;

    // int precision;
    // cout << "enter the precision" << endl;
    // cin >> precision;

    // double step = 0.1;
    // double finalAns = abs(ans);
    // for(int i = 0; i < precision; i++){
    //     for(double j = finalAns; j * divisor <= div; j = j +step){
    //         finalAns = j;
    //     }
    //     step = step/10;
    // }
    // if((divisor < 0 && div < 0) || (divisor > 0 && div > 0)){
    //     cout << finalAns << endl;
    // }else{
    //     cout << -finalAns << endl;
    // }

    vector<int> v{1,1,2,2,3,3,4,4,3,600,600,4,4};
    int ans = solve(v);
    cout << ans << endl;
    return 0;
}