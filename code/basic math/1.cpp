#include <bits/stdc++.h>
using namespace std;

// bool isPrime(int n){
//     if(n <= 1){
//         return false;
//     }else{
//         for(int i = 2; i < n; i++){  // o(n)  naive approach
//             if(n % i == 0){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// bool isPrime(int n){
//     if(n <= 1){
//         return false;
//     }else{
//         for(int i = 2; i < sqrt(n); i++){  // o(sqrt(n))  sqrt approach
//             if(n % i == 0){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

int countPrime(int n)
{
    if (n == 0)
    {
        return 0;
    }

    vector<bool> prime(n, true);

    prime[0] = prime[1] = false;

    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            ans++;

            int j = 2 * i;
            if (j < n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }
    return ans;
}

// int powers(int a , int b){ // o(b)
//     int ans = 1;
//     for(int i = 0; i < b; i++){
//         ans = ans*a;
//     }
//     return ans;
// }

int powers(int a, int b)
{ // o(logb)
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b = b / 2;
    }
    return ans;
}

int main()
{
    // int n;
    // cin >> n;

    // int count = 0;
    // for(int i = 0;i < n; i++){
    //     if(isPrime(i)){
    //         count++;
    //     }
    // }

    // cout << count << endl;

    // int n;
    // cin >> n;

    // int count = countPrime(n);

    // cout << count << endl;

    int a, b;
    cin >> a >> b;

    cout << powers(a, b) << endl;
    return 0;
}