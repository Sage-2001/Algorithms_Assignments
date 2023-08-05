// 10. Given a array A of numbers , write a linear time algorithm to compute array B, such
// that B[i] = j, j is the smallest j > i such that A[j] < A[i].B[i] = n if all the numbers
// to the right of A[i] are greater than or equal to A[i].

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
        B[i] = size;
    }

    stack<int> s;
    int i = 0;

    while (i < size) {
        while (!s.empty() && A[i] < A[s.top()]) {
            B[s.top()] = i;
            s.pop();
        }
        s.push(i);
        i++;
    }

    cout << "B: ";
    for (int val : B) {
        cout << val << " ";
    }

    cout<<endl;
    return 0;
}


