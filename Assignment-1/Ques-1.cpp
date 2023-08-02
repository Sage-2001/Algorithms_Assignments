// 1. A binary string is called dense if the number of 1’s in the string is more than the
// number of 0’s. For example 1, 101,110101 are dense, but 10, 1001,100001 are not
// dense.
// Given a binary string of length n, design an O(n log n) time algorithm to compute
// the number of dense sub-strings of the given string. For example, given 10101, the
// answer is 6.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//using single pass two pointer O(N) complexity

int solve(vector<int>& arr){
    int ans = 0;
    int count_zero = 0, count_one = 0;

    for(int i = 0;i < arr.size();i++){
        if(arr[i] == 0){
            count_zero++;
        }
        else{
            count_one++;
        }
        if(count_one > count_zero){
            ans += count_one;
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    int n;
    cout<<"INPUT THE SIZE OF THE ARRAY"<<endl;
    cin>>n;
    cout<<"INPUT THE ARRAY"<<endl;
    for(int i = 0;i < n;i++){
        int x ;
        cin>>x;
        arr.push_back(x);
    }

    cout<<endl<<"Ans is "<<solve(arr)<<endl;
    return 0;
}