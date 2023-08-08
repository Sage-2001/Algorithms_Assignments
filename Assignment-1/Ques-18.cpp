// 18. Given a sequence of n numbers design a linear time algorithm to compute the length
// of the maximum sum sub array.


#include<bits/stdc++.h>
using namespace std;

int maxsub(vector<int> &arr) {
    int maxcur = 0;
    int n = arr.size();
    int max_ans = INT_MIN;

    for (int i = 0; i < n ; i++) {
        maxcur = maxcur + arr[i];
        if(maxcur > max_ans){
            max_ans = maxcur;
        }
        if(maxcur < 0){
            maxcur = 0;
        }
    }
    
    return max_ans;
}

int main() {
    vector<int> arr = {7,-1,-5,3,6,-4};
    int maxPro = maxsub(arr);
    cout << "Max subarray is: " << maxPro << endl;
}
