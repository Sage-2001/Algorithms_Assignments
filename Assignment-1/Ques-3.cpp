// 3. Given a binary string of length n, design a linear time algorithm to compute the
// length of the largest sub-string which contains equal number of 0’s and 1’s.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


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
        if(count_zero - count_one == 0){
            ans = max(ans,i+1);
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