// Problem: Root equals sum of children
// Difficulty: Easy
//platform: Leetcode
// Approach: simple inequality
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return (root->val == root->left->val+root->right->val);
    }
};