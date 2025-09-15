/*

Leetcode Question : 
700. Search in a Binary Search Tree
Solved
Easy

You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107

*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) { 
        // Recursion Method 
        while(root != NULL) {
            if(root->val == val)
                return root;
            else if(val < root->val)
                return searchBST(root->left,val);
            else 
                return searchBST(root->right,val);
        }

        // Iterative Method 
        /*
        while(root != NULL){ 
            if(root->val == val) 
                return root; 
            else if (val < root->val) 
                root = root->left; 
            else 
                root = root->right; 
        }
        */
        return NULL;
    }
};

// Helper function to insert a node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Helper function to print the BST in-order (sorted order)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    
    int values[] = {4, 2, 7, 1, 3};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "In-order traversal of BST: ";
    inorder(root);
    cout << endl;

    int target = 2;
    Solution sol;
    TreeNode* result = sol.searchBST(root, target);

    if (result != NULL)
        cout << "Node with value " << target << " found." << endl;
    else
        cout << "Node with value " << target << " not found." << endl;

    return 0;
}
