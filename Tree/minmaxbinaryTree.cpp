// Problem: Min and Max in Binary tree
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: recursion
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    int findMax(Node *root) {
        // code here
        
        if(!root)return INT_MIN;
        
        return max(root->data, max(findMax(root->left), findMax(root->right)));
    }

    int findMin(Node *root) {
        
        // code here
        
        if(!root)return INT_MAX;
        
        return min(root->data, min(findMin(root->left),findMin(root->right)));
    }
};