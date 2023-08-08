// 20. Given a sequence of n numbers and an integer k, design a linear time algorithm to
// compute the length of the maximum sum sub array , whos length is atleast k.


#include<bits/stdc++.h>
using namespace std;

int maxsub(vector<int> &arr,int k) {
    int maxcur = 0;
    int n = arr.size();
    int max_ans = INT_MIN;

    for (int i = 0; i < n ; i++) {
        maxcur = maxcur + arr[i];
        if(i+1 >=k){
            if(max_ans < maxcur){
                max_ans = maxcur;
            }
        }
        if(maxcur < 0){
            maxcur = 0;
        }
    }
    
    return max_ans;
}

int main() {
    vector<int> arr = {7,-1,-5,3,6,-4};
    int k = 2;
    int maxPro = maxsub(arr,k);
    cout << "Max subarray is: " << maxPro << endl;
}
