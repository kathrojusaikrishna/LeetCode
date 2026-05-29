// Problem: Minimum absolute difference in BST
// Difficulty: Easy
//platform: Leetcode
// Approach: recursion
// Time: O(n)
// Space: O(1)
class Solution {
public:

    int minDif=INT_MAX;
    void solve(TreeNode* root, TreeNode*& prev){
        
        if(!root)return;

        solve(root->left,prev);

        if(prev){
            minDif = min(minDif, abs(prev->val - root->val));
        }

        prev = root;
        solve(root->right,prev);

    }

    int getMinimumDifference(TreeNode* root) {

        TreeNode* prev = nullptr;
        solve(root, prev);

        return minDif;
    }
};