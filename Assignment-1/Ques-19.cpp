// 19. Given a sequence of n numbers and an integer k, design a linear time algorithm to
// compute the length of the maximum sum sub array , whos length is exactly k.


#include<bits/stdc++.h>
using namespace std;

int maxsub(vector<int> &arr, int k) {
    int max_ans = INT_MIN;
    int maxcur = 0;
    
    for (int j = 0; j < k; j++) {
        maxcur += arr[j];
    }
    
    for (int j = k; j < arr.size(); j++) {
        max_ans = max(max_ans, maxcur);
        maxcur = maxcur - arr[j - k] + arr[j];
    }
    
    // Compare one last time for the last window
    max_ans = max(max_ans, maxcur);
    
    return max_ans;
}

int main() {
    vector<int> arr = {7, -1, -5, 3, 6, -4};
    int k = 2;
    int maxPro = maxsub(arr, k);
    cout << "Max subarray sum of length " << k << " is: " << maxPro << endl;
}

