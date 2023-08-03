// 4. Given a binary string S of length n, design a linear time algorithm to compute k,
// such that the number of 0’s in S[0..k] is equal to number of 1’s in S[k+1..n-1].

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& arr){
    int count_one = -1;

    for(int i = 0;i < arr.size();i++){
        if(arr[i] == 1){
            count_one++;
        }
    }
    return count_one;
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