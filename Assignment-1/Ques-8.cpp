// 8. Design a linear time algorithm to decide if a given sequence of numbers 
// is a stack sequence.

#include<bits/stdc++.h>
using namespace std;

bool isStackSequence(vector<int>& arr){
    stack<int> s;
    int n = arr.size();
    int j = 0;

    for(int i = 1; i <= n; i++){
        s.push(i);
        while(!s.empty() && j < n && s.top() == arr[j]){
            s.pop();
            j++;
        }
    }

    return s.empty();
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

    if(isStackSequence(arr)){
        cout << "This is a Stack Sequence"<<endl;
    } else {
        cout << "This is not a Stack Sequence"<<endl;
    }
    return 0;
}
