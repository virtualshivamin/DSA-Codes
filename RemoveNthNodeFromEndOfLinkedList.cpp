/*

19. Remove Nth Node From End of List
Solved
Medium
Topics
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class with the core logic
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Find the length of the linked list
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2: If we need to remove the first node (head)
        if (n == length) {
            ListNode* newHead = head->next;
            delete head; // free memory
            return newHead;
        }

        // Step 3: Move to the (length - n - 1)th node
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        // Step 4: Delete the next node (nth from end)
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete; // free memory

        // Step 5: Return the modified list
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example: Input: head = [1, 2, 3, 4, 5], n = 2
    int arr[] = {1, 2, 3, 4, 5};
    int n = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    ListNode* head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    // Call the solution
    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "After Removing " << n << "th Node From End: ";
    printList(head);

    return 0;
}
