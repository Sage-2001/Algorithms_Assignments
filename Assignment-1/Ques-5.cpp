// 5. Write a linear time iterative algorithm to reverse a linked list.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next = NULL;

    // Constructor
    Node(int val) : data(val), next(NULL) {}

};

// Linear time iterative algorithm to reverse a linked list using 3 pointers 
// pre, cur, nexti which iterate through the whole linked list and reverse it,
// then return the head of the reversed list.

Node* solve(Node* head) {
    Node* pre = NULL;
    Node* cur = head;
    Node* nexti = NULL;

    while (cur != NULL) {
        nexti = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nexti;
    }

    return pre; // The new head of the reversed list
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Tell the size of the Linked List: " << endl;
    cin >> n;
    cout << "Input the Linked list: " << endl;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        // Create a new node
        Node* newNode = new Node(x);

        // If it's the first node, set it as head
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Append the new node to the end of the linked list
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = solve(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    // Clean up the linked list to avoid memory leaks
    delete head;

    return 0;
}
