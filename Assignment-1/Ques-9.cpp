// 9. You are given an array of integers, there is a sliding window of size at most k which
// is moving from left to right. You can only see at most k numbers in the window.
// Each time the sliding window moves right by one position. Design an linear time
// algorithm to compute the maximum in each window.

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,vector<int>& ans,int k){
    deque<int> d;

    for(int i = 0; i<arr.size();i++){
        if(!d.empty() and d.front() == i-k){
            d.pop_front();
        }

        while(!d.empty() and arr[d.back()] < arr[i]){
            d.pop_back();
        }

        d.push_back(i);
        if(i >= k-1) ans.push_back(arr[d.front()]);
    }
    return;
}

int main(){
    vector<int> arr;
    int n;
    cout << "INPUT THE SIZE OF THE ARRAY" << endl;
    cin >> n;
    cout << "INPUT THE ARRAY" << endl;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int k =0 ;
    cout << "INPUT THE WINDOW SIZE" << endl;
    cin >> k;

    vector<int> ans;
    solve(arr,ans,k);
    cout<<endl<<"Ans is"<<endl;

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
