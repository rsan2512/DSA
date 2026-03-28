#include <iostream>
using namespace std;

// ─────────────────────────────────────────
//  Node Definition
// ─────────────────────────────────────────
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// ─────────────────────────────────────────
//  Linked List Class
// ─────────────────────────────────────────
class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Destructor — free all memory
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // 1. Insert at beginning
    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at end
    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    // 3. Insert at position (0-indexed)
    void insertAt(int pos, int val) {
        if (pos == 0) { insertFront(val); return; }
        Node* newNode = new Node(val);
        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr; i++)
            curr = curr->next;
        if (!curr) { cout << "Position out of range\n"; delete newNode; return; }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // 4. Delete by value
    void deleteVal(int val) {
        if (!head) { cout << "List is empty\n"; return; }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;
        if (!curr->next) { cout << val << " not found\n"; return; }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    // 5. Delete at position (0-indexed)
    void deleteAt(int pos) {
        if (!head) { cout << "List is empty\n"; return; }
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr->next; i++)
            curr = curr->next;
        if (!curr->next) { cout << "Position out of range\n"; return; }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    // 6. Search
    bool search(int val) {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    // 7. Get length
    int length() {
        int count = 0;
        Node* curr = head;
        while (curr) { count++; curr = curr->next; }
        return count;
    }

    // 8. Reverse
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // 9. Get middle node (slow-fast pointer)
    int getMiddle() {
        if (!head) { cout << "List is empty\n"; return -1; }
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    // 10. Detect cycle (Floyd's algorithm)
    bool hasCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // 11. Print
    void print() {
        if (!head) { cout << "NULL\n"; return; }
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << " -> NULL\n";
    }
};

// ─────────────────────────────────────────
//  Driver Code
// ─────────────────────────────────────────
int main() {
    LinkedList ll;

    cout << "=== Insert at Back ===\n";
    ll.insertBack(10);
    ll.insertBack(20);
    ll.insertBack(30);
    ll.insertBack(40);
    ll.print();                          // 10 -> 20 -> 30 -> 40 -> NULL

    cout << "\n=== Insert at Front ===\n";
    ll.insertFront(5);
    ll.print();                          // 5 -> 10 -> 20 -> 30 -> 40 -> NULL

    cout << "\n=== Insert at Position 2 ===\n";
    ll.insertAt(2, 15);
    ll.print();                          // 5 -> 10 -> 15 -> 20 -> 30 -> 40 -> NULL

    cout << "\n=== Length ===\n";
    cout << "Length: " << ll.length() << "\n";   // 6

    cout << "\n=== Search ===\n";
    cout << "Search 15: " << (ll.search(15) ? "Found" : "Not Found") << "\n";
    cout << "Search 99: " << (ll.search(99) ? "Found" : "Not Found") << "\n";

    cout << "\n=== Middle Element ===\n";
    cout << "Middle: " << ll.getMiddle() << "\n";  // 20

    cout << "\n=== Delete by Value (20) ===\n";
    ll.deleteVal(20);
    ll.print();                          // 5 -> 10 -> 15 -> 30 -> 40 -> NULL

    cout << "\n=== Delete at Position 0 ===\n";
    ll.deleteAt(0);
    ll.print();                          // 10 -> 15 -> 30 -> 40 -> NULL

    cout << "\n=== Reverse ===\n";
    ll.reverse();
    ll.print();                          // 40 -> 30 -> 15 -> 10 -> NULL

    cout << "\n=== Cycle Detection ===\n";
    cout << "Has cycle: " << (ll.hasCycle() ? "Yes" : "No") << "\n";  // No

    return 0;
}
