// 11. Given a array A of numbers , write a linear time algorithm to compute array B, such
// that B[i] = j, j is the largest j < i such that A[j] > A[i].B[i] = −1 if all the numbers
// to the left of A[i] are less than or equal to A[i].


#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    int size;
    cout << "Array size: ";
    cin >> size;

    int A[size];
    cout << "Enter array: ";
    for (int i = 0; i < size; ++i) {
        cin >> A[i];
    }

    int B[size];
    for (int i = 0; i < size; ++i) {
        B[i] = -1;
    }

    stack<int> s;
    int i = size - 1;

    while (i >= 0) {
        while (!s.empty() && A[i] > A[s.top()]) {
            B[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i--;
    }

    cout << "B: ";
    for (int val : B) {
        cout << val << " ";
    }

    cout<<endl;
    return 0;
}


