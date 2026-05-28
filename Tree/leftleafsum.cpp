// Problem: Sum of left leaves
// Difficulty: Easy
//platform: Leetcode
// Approach: recursion
// Time: O(n)
// Space: O(h) 

class Solution {
public:

    
    void solve(TreeNode* root, int &sum){

        if(!root)return;

        if(root->left && !root->left->left && !root->left->right)sum+=root->left->val;
        solve(root->left,sum);
        solve(root->right,sum);

    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum=0;

        solve(root,sum);

        return sum;
    }
};