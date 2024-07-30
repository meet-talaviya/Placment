#include<bits/stdc++.h>
using namespace std;

//slevle algo prime find using n number

vector<bool> slevle(int n){
   vector<bool> prime(n+1, true);

   prime[0] = prime[1] = false;

   int s = sqrt(n);
   for(int i = 2; i <= s; i++){
      if(prime[i]){
        int j = i*i;
        while(j <= n){
            prime[j] = false;
            j += i;
        }
      }
   }

   return prime;
}

//wrong answeer
vector<bool> segSl(int l, int r){ 
    vector<bool> seg = slevle(sqrt(r));
    vector<int> basePrimes;
    for(int i = 0; i < seg.size(); i++){
        if(seg[i]){
            basePrimes.push_back(i);
        }
    }

    vector<bool> segz(r-l+1 , true);
    if(l == 1 || l == 0){
        segz[0] = false;
    }

    for(auto prime : basePrimes){
        int first_mul = (l / prime) * prime;
        if(first_mul < l){
            first_mul += prime;
        }
        int j = max(first_mul , prime*prime);

        while(j <= r){
            segz[j - l] = false;
            j += prime;
        }
    }
    return seg;
}

int main(){

    // vector<bool> Slevle = slevle(25);
    // for(int i = 0; i < 25; i++){
    //     if(Slevle[i]){
    //         cout << i << " ";
    //     }
    // }

    int l = 110;
    int r = 130;
    vector<bool> s = segSl(l , r);
    for(int i = 0; i < s.size(); i++){
        if(s[i]){
            cout << i + l << " ";
        }
    }

    return 0;
}