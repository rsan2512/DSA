#include <bits/stdc++.h>
using namespace std;

// ============================================================
// QUESTION: 141. Linked List Cycle
// ------------------------------------------------------------
// Given the head of a linked list, determine if it has a cycle.
// A cycle means some node's next pointer points back to a
// previous node, forming an infinite loop.
//
// Return true if cycle exists, false otherwise.
//
// Example 1 (cycle):
// 3 -> 2 -> 0 -> -4
//      ^___________|   <- -4 points back to 2
// Output: true
//
// Example 2 (no cycle):
// 1 -> 2 -> 3 -> null
// Output: false
// ============================================================

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// --- Solution ---
// APPROACH: Floyd's Cycle Detection (Tortoise and Hare)
//
// Use two pointers:
//   slow -> moves 1 step at a time
//   fast -> moves 2 steps at a time
//
// If there's NO cycle:
//   fast will hit nullptr and loop ends -> return false
//
// If there IS a cycle:
//   fast laps slow and they meet at the same node -> return true
//
// Think of it like a circular track:
//   A faster runner will always lap a slower one eventually.
//
// Dry run (3 -> 2 -> 0 -> -4 -> back to 2):
//
//   Start:  slow=3,  fast=3
//   Step 1: slow=2,  fast=0
//   Step 2: slow=0,  fast=2   (fast looped around)
//   Step 3: slow=-4, fast=-4  -> MATCH, return true ✅
//
// Time:  O(n) — fast pointer catches slow within one loop
// Space: O(1) — only two pointers

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // fast && fast->next: ensures no null dereference
        // if either is null, list has an end -> no cycle
        while (fast && fast->next) {
            slow = slow->next;         // move 1 step
            fast = fast->next->next;   // move 2 steps

            // if they meet, a cycle exists
            if (fast == slow) return true;
        }

        // fast reached end of list, no cycle
        return false;
    }
};

// --- Helper: Build a normal list (no cycle) ---
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

// --- Helper: Print list (only use on non-cycle lists!) ---
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Solution sol;

    // --- Test Case 1: Cycle exists ---
    // List: 3 -> 2 -> 0 -> -4
    //            ^__________|   (-4 points back to node 2)
    ListNode* list1 = buildList({3, 2, 0, -4});
    // manually create the cycle: tail -> node at index 1 (val=2)
    ListNode* tail1 = list1->next->next->next; // points to -4
    tail1->next     = list1->next;             // -4 -> 2 (cycle!)
    cout << "Test 1 (cycle at pos 1):    " << (sol.hasCycle(list1) ? "true" : "false") << endl;

    // --- Test Case 2: Cycle exists ---
    // List: 1 -> 2
    //        ^___|   (2 points back to 1)
    ListNode* list2 = buildList({1, 2});
    list2->next->next = list2;  // 2 -> 1 (cycle!)
    cout << "Test 2 (cycle at pos 0):    " << (sol.hasCycle(list2) ? "true" : "false") << endl;

    // --- Test Case 3: No cycle ---
    // List: 1 -> 2 -> 3 -> 4 -> null
    ListNode* list3 = buildList({1, 2, 3, 4});
    cout << "Test 3 (no cycle):          " << (sol.hasCycle(list3) ? "true" : "false") << endl;
    printList(list3); // safe to print since no cycle

    return 0;
}
// ```

// ### Output
// ```
// Test 1 (cycle at pos 1):    true
// Test 2 (cycle at pos 0):    true
// Test 3 (no cycle):          false
// 1 -> 2 -> 3 -> 4
// Test 4 (single, no cycle):  false
// Test 5 (empty list):        false