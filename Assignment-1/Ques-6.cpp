//6. Write a linear time algorithm to decide if a linked list contains a 
//cycle or not.
// 7. Given a linked list containing a cycle, write a linear time algorithm 
// to delete the cycle.

//both can be done through rabit and hare slow and fast pointer concept

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next = NULL;

    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

bool hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false; // No cycle in an empty or single-node list
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
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

    bool hasCycleFlag = hasCycle(head);
    if (hasCycleFlag) {
        cout << "The Linked List contains a cycle." << endl;
    } else {
        cout << "The Linked List does not contain a cycle." << endl;
    }

    // Clean up the linked list to avoid memory leaks
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
