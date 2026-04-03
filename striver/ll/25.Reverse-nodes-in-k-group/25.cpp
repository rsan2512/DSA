#include <bits/stdc++.h>
using namespace std;

// ============================================================
// QUESTION: 25. Reverse Nodes in k-Group
// ------------------------------------------------------------
// Given the head of a linked list, reverse the nodes of the
// list k at a time, and return the modified list.
//
// k is a positive integer and <= length of the list.
// If the number of nodes is not a multiple of k then
// the left-out nodes at the end should remain as is.
//
// Example:
// Input:  1->2->3->4->5, k=2
// Output: 2->1->4->3->5
//
// Input:  1->2->3->4->5, k=3
// Output: 3->2->1->4->5
// ============================================================

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    // --- Reverse a linked list segment ---
    // Standard 3-pointer reversal
    // Used to reverse each k-group in place
    void reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* nex  = nullptr;
        ListNode* curr = head;
        while (curr) {
            nex        = curr->next;
            curr->next = prev;
            prev       = curr;
            curr       = nex;
        }
    }

    // --- Find the kth node from temp ---
    // Moves k-1 steps forward from temp
    // Returns nullptr if fewer than k nodes remain (incomplete group)
    // Returns the kth node if group is complete
    //
    // Why k-1? because temp is already ON the first node,
    // so we only need k-1 more moves to reach the kth node
    ListNode* find(ListNode* temp, int k) {
        for (int i = 0; i < k-1; i++) {
            temp = temp->next;
            if (!temp) return nullptr; // fewer than k nodes, incomplete group
        }
        return temp;
    }

    // --- Main function ---
    // APPROACH:
    // 1. Find the kth node of current group using find()
    // 2. If group is incomplete, attach remaining list as-is and stop
    // 3. Save the node after kthnode (nextnode) before breaking the chain
    // 4. Cut the group: kthnode->next = null
    // 5. Reverse the group
    // 6. Attach the reversed group to the previous group
    // 7. Move temp to nextnode for the next iteration
    //
    // Key pointers:
    //   temp     -> start of current group
    //   kthnode  -> end of current group (becomes new head after reverse)
    //   nextnode -> start of next group (saved before cutting)
    //   prevnode -> tail of previous reversed group (used to link groups)
    //
    // Time:  O(n) — each node is visited twice (find + reverse)
    // Space: O(1) — only pointers, no extra memory
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp     = head;
        ListNode* nextnode = nullptr;
        ListNode* prevnode = nullptr;

        while (temp) {
            // Step 1: find the kth node of this group
            ListNode* kthnode = find(temp, k);

            // Step 2: if group is incomplete, attach as-is and stop
            if (!kthnode) {
                if (prevnode) prevnode->next = temp;
                break;
            }

            // Step 3: save the start of the next group
            nextnode = kthnode->next;

            // Step 4: cut this group from the rest of the list
            kthnode->next = nullptr;

            // Step 5: reverse this group
            // after reverse: kthnode is new head, temp is new tail
            reverse(temp);

            // Step 6: attach reversed group to the rest of the list
            if (temp == head) {
                // first group: update the actual head
                head = kthnode;
            } else {
                // subsequent groups: link previous tail to new head
                prevnode->next = kthnode;
            }

            // Step 7: temp is now the tail of reversed group
            // prevnode moves to temp for next iteration
            prevnode = temp;
            temp     = nextnode; // move to next group
        }

        return head;
    }
};

// --- Helper: Build linked list from vector ---
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

// --- Helper: Print linked list ---
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Solution sol;

    // Test 1: k=2, list length 5 (odd length, last node stays)
    // Expected: 2->1->4->3->5
    ListNode* list1 = buildList({1, 2, 3, 4, 5});
    cout << "Test 1 Input:  "; printList(list1);
    list1 = sol.reverseKGroup(list1, 2);
    cout << "Test 1 Output: "; printList(list1);
    cout << endl;

    // Test 2: k=3, list length 5 (last 2 nodes stay as-is)
    // Expected: 3->2->1->4->5
    ListNode* list2 = buildList({1, 2, 3, 4, 5});
    cout << "Test 2 Input:  "; printList(list2);
    list2 = sol.reverseKGroup(list2, 3);
    cout << "Test 2 Output: "; printList(list2);
    cout << endl;

    // Test 3: k=1 (no change)
    // Expected: 1->2->3->4->5
    ListNode* list3 = buildList({1, 2, 3, 4, 5});
    cout << "Test 3 Input:  "; printList(list3);
    list3 = sol.reverseKGroup(list3, 1);
    cout << "Test 3 Output: "; printList(list3);
    cout << endl;

    // Test 4: k equals list length (reverse entire list)
    // Expected: 5->4->3->2->1
    ListNode* list4 = buildList({1, 2, 3, 4, 5});
    cout << "Test 4 Input:  "; printList(list4);
    list4 = sol.reverseKGroup(list4, 5);
    cout << "Test 4 Output: "; printList(list4);
    cout << endl;

    // Test 5: single node
    // Expected: 1
    ListNode* list5 = buildList({1});
    cout << "Test 5 Input:  "; printList(list5);
    list5 = sol.reverseKGroup(list5, 2);
    cout << "Test 5 Output: "; printList(list5);

    return 0;
}