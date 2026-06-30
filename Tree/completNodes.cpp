// Problem: Count the complete nodes
// Difficulty: Easy
//platform: Leetcode
// Approach: using bottom-up dfs
// Time: O(n)
// Space: O(1)

class Solution {
public:

    int solve(TreeNode* root){
        if(!root)return 0;

        return 1+ solve(root->left)+solve(root->right);
        
    }

    int countNodes(TreeNode* root) {

        if(!root)return 0;
        int counter = solve(root);
        return counter;
    }
};