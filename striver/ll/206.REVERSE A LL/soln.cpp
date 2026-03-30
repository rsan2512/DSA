#include <bits/stdc++.h>
using namespace std;

// ============================================================
// QUESTION: 206. Reverse Linked List
// ------------------------------------------------------------
// Given the head of a singly linked list, reverse the list
// and return the reversed list's head.
//
// Example:
// Input:  1 -> 2 -> 3 -> 4 -> 5
// Output: 5 -> 4 -> 3 -> 2 -> 1
//
// Constraints:
// - Number of nodes: [0, 5000]
// - Node values: [-5000, 5000]
// ============================================================

// --- Node structure ---
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// --- Solution ---
// APPROACH: 3-pointer iterative reversal
//
// We use three pointers:
//   prev  -> the node behind curr (starts as null, nothing is behind head)
//   curr  -> the node we are currently processing
//   front -> saves the next node before we break the link
//
// In each iteration:
//   1. Save curr->next into front (so we don't lose the rest of the list)
//   2. Flip curr->next to point BACKWARDS to prev
//   3. Move prev and curr one step forward
//
// Dry run on 1 -> 2 -> 3:
//
//   Initial:   prev=null, curr=1, front=null
//
//   Step 1:    front=2, 1->null, prev=1, curr=2
//              null <- [1]   [2] -> [3]
//
//   Step 2:    front=3, 2->1, prev=2, curr=3
//              null <- [1] <- [2]   [3]
//
//   Step 3:    front=null, 3->2, prev=3, curr=null
//              null <- [1] <- [2] <- [3]
//
//   Loop ends (curr is null), return prev = 3 (new head)
//   Result: 3 -> 2 -> 1  ✅
//
// Time:  O(n) — single pass through the list
// Space: O(1) — only 3 pointers, no extra memory

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or single node, nothing to reverse
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev  = nullptr; // nothing is behind head at the start
        ListNode* curr  = head;    // start processing from head
        ListNode* front = nullptr; // will save next node before flipping

        // run until we've processed every node
        while (curr) {
            front      = curr->next; // Step 1: save next node
            curr->next = prev;       // Step 2: flip the link backwards
            prev       = curr;       // Step 3: move prev forward
            curr       = front;      // Step 4: move curr forward
        }

        // prev is now pointing at the last node (new head)
        return prev;
    }
};

// --- Helper: Build a linked list from a vector ---
ListNode* buildList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// --- Helper: Print the linked list ---
void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "Empty List" << endl;
        return;
    }
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Solution sol;

    // --- Test Case 1: Normal list ---
    // Input:  1 -> 2 -> 3 -> 4 -> 5
    // Output: 5 -> 4 -> 3 -> 2 -> 1
    ListNode* list1 = buildList({1, 2, 3, 4, 5});
    cout << "Test 1 Input:  "; printList(list1);
    list1 = sol.reverseList(list1);
    cout << "Test 1 Output: "; printList(list1);
    cout << endl;

    // --- Test Case 2: Two nodes ---
    // Input:  1 -> 2
    // Output: 2 -> 1
    ListNode* list2 = buildList({1, 2});
    cout << "Test 2 Input:  "; printList(list2);
    list2 = sol.reverseList(list2);
    cout << "Test 2 Output: "; printList(list2);
    cout << endl;

    // --- Test Case 3: Single node (base case) ---
    // Input:  42
    // Output: 42
    ListNode* list3 = buildList({42});
    cout << "Test 3 Input:  "; printList(list3);
    list3 = sol.reverseList(list3);
    cout << "Test 3 Output: "; printList(list3);
    cout << endl;

    // --- Test Case 4: Empty list (base case) ---
    // Input:  (empty)
    // Output: (empty)
    ListNode* list4 = nullptr;
    cout << "Test 4 Input:  "; printList(list4);
    list4 = sol.reverseList(list4);
    cout << "Test 4 Output: "; printList(list4);

    return 0;
}
// ```

// ### Output
// ```
// Test 1 Input:  1 -> 2 -> 3 -> 4 -> 5
// Test 1 Output: 5 -> 4 -> 3 -> 2 -> 1

// Test 2 Input:  1 -> 2
// Test 2 Output: 2 -> 1

// Test 3 Input:  42
// Test 3 Output: 42

// Test 4 Input:  Empty List
// Test 4 Output: Empty List