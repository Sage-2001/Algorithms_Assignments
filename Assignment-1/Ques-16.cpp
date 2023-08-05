// 16. Given a sequence of n numbers, representing the stock prices of a stock on different
// days, design a linear time algorithm to compute the maximum profit that you can
// make by buying and selling a stock exactly once, you can sell a stock at least k days
// after you bought it.


#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr,int k) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = arr[0];

    for (int i = 1; i < n ; i++) {
        if(i >= k){
            minPrice = min(minPrice, arr[i-k]);
        }
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int k = 2;
    int maxPro = maxProfit(arr,k);
    cout << "Max profit is: " << maxPro << endl;
}
