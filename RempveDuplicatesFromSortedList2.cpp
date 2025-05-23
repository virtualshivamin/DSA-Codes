/*


Leetcode Question 
82. Remove Duplicates from Sorted List II
Solved
Medium
Topics
Companies
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.


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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node before the head to handle edge cases
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* current = head;  // Pointer to traverse list
        ListNode* prev = temp;     // Pointer to track node before the duplicate group

        while (current) {
            bool duplicate = false;

            // Check for duplicates
            while (current->next && current->val == current->next->val) {
                current = current->next;
                duplicate = true;
            }

            if (duplicate) {
                // Skip all duplicates
                prev->next = current->next;
            } else {
                // Move prev forward only if no duplicate was found
                prev = prev->next;
            }

            current = current->next; // Move current forward
        }

        return temp->next; // Return the real head of the modified list
    }
};

// Helper function to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print the linked list
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

    // Example 1: Input: [1,2,3,3,4,4,5]
    vector<int> input1 = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head1 = createList(input1);
    ListNode* result1 = sol.deleteDuplicates(head1);
    cout << "Output 1: ";
    printList(result1); // Expected: 1 -> 2 -> 5

    // Example 2: Input: [1,1,1,2,3]
    vector<int> input2 = {1, 1, 1, 2, 3};
    ListNode* head2 = createList(input2);
    ListNode* result2 = sol.deleteDuplicates(head2);
    cout << "Output 2: ";
    printList(result2); // Expected: 2 -> 3

    return 0;
}
