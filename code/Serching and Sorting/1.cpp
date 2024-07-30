#include <bits/stdc++.h>
using namespace std;

// int binarySerch(int arr[] , int size, int target){
//     int start = 0;
//     int end = size - 1;
//     // int mid = (start + end)/2;  integer overflow thay
//     int mid = start + (end - start)/2;

//     while(start <= end){
//         int element = arr[mid];
//         if(element == target){
//             return mid;
//         }else if(element < target){
//             start = mid + 1;
//         }else{
//             end = mid - 1;
//         }
//         // mid = (start + end)/2;
//         mid = start + (end - start)/2;
//     }
//     return -1;
// }

int findfirstOcc(vector<int> v, int target)
{

    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start) / 2;

    int index = -1;
    while (start <= end)
    {
        if (v[mid] == target)
        {
            index = mid;
            end = mid - 1;
        }
        else if (target > v[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return index;
}

int findlastOcc(vector<int> v, int target)
{

    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start) / 2;

    int index = -1;
    while (start <= end)
    {
        if (v[mid] == target)
        {
            index = mid;
            start = mid + 1;
        }
        else if (target > v[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return index;
}

int findMissEle(vector<int> v){
    int s = 0;
    int e = v.size()  - 1;
    int m = s + (e - s)/2;

    int ans = -1;

    while (s <=e)
    {
        if(v[m] == m+1){
            ans = m + 1;
            s  = m + 1;
        }else if(v[m] != m+2){
            ans = m +2;
            e = m - 1;
        }
        m = s + (e - s)/2;
    }
    
    return ans;
}

int main()
{
    // int arr[] = {1,2,3,4,5,6,7};
    // int target = 6;
    // int size = 7;

    // int index = binarySerch(arr , size , target);
    // if(index == -1){
    //     cout << "not found" << endl;
    // }else{
    //     cout << "found" << " " << index << endl;
    // }

    //--------------inbiult function
    // vector<int> v{1,2,3,4,5,6};

    // if(binary_search(v.begin(),v.end(), 5)){
    //     cout << "found" << endl;
    // }else{
    //     cout << "not found" << endl;
    // }

    //----------find first occrence

    // int n;
    // cout << "enter the size of vector" << endl;
    // cin >> n;

    // vector<int> v(n);

    // cout << "enter the vector value" << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }

    // int target;
    // cout << "enter the target value" << endl;
    // cin >> target;

    // vector<int> v{1,2,4,4,4,4,4,5,6,7};
    // int target = 4;

    // int ans = findfirstOcc(v, target);
    // int ans1 = findlastOcc(v , target);
    // // cout << "first occurce"
    // //      << " " << ans << endl;

    // int totalOcc = (ans1 - ans) + 1;
    // cout << totalOcc << endl;

//--------inbulit function
    // auto ans1 = lower_bound(v.begin(), v.end(),target);
    // cout << ans1-v.begin() << endl;   

    vector<int> v{1,3,4,5,6,7,8,9};
    int ans = findMissEle(v);  
    cout << ans << endl;
    return 0;
}