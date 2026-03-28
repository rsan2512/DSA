#include <bits/stdc++.h>
using namespace std;

// ============================================================
// QUESTION: 237. Delete Node in a Linked List
// ------------------------------------------------------------
// You are given a node in a singly linked list (not the head).
// Delete that node from the list.
// You do NOT have access to the head of the list.
// The node to delete is guaranteed to NOT be the tail.
//
// Input:  The node to delete (only this, not head)
// Output: void (modify the list in-place)
// ============================================================

// --- Node structure ---
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// --- Solution ---
// INSIGHT: We can't reach the previous node, so we can't do a normal delete.
// TRICK: Copy next node's value into current node, then skip the next node.
// This effectively makes the current node "become" the next node.
void deleteNode(ListNode* node) {
    // Step 1: Copy the value of the next node into current node
    node->val = node->next->val;

    // Step 2: Bypass the next node (delete it from the chain)
    node->next = node->next->next;
}

// --- Helper: Print the linked list ---
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // --- Build the list: 4 -> 5 -> 1 -> 9 ---
    ListNode* head = new ListNode(4);
    head->next     = new ListNode(5);
    head->next->next     = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List: ";
    printList(head); // 4 -> 5 -> 1 -> 9

    // --- We want to delete node with value 5 ---
    // In a real scenario, this node pointer would be given to you directly.
    // We simulate that by grabbing head->next (which is the node with val=5)
    ListNode* nodeToDelete = head->next; // points to node [5]

    cout << "Node to delete: " << nodeToDelete->val << endl;

    // --- Call the solution ---
    deleteNode(nodeToDelete);

    cout << "List after deletion: ";
    printList(head); // 4 -> 1 -> 9

    return 0;
}


// ### Output
// ```
// Original List: 4 -> 5 -> 1 -> 9
// Node to delete: 5
// List after deletion: 4 -> 1 -> 9
// ```

// ### What's happening step by step
// ```
// Start:   [4] -> [5] -> [1] -> [9]
//                  ^
//            nodeToDelete

// Step 1 - copy next val:
//          [4] -> [1] -> [1] -> [9]

// Step 2 - skip next node:
//          [4] -> [1] -> [9]