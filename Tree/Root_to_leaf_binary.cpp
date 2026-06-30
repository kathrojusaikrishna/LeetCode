// Problem: Sum of root to leaf binary numbers
// Difficulty: Easy
// Approach: Recursion
// Time: O(n)
// Space: O(1)


class Solution {
public:

    void solve(TreeNode* root, int currVal, int &ans){
        if(!root)return;

        currVal = currVal*10+root->val;

        if(!root->left && !root->right){
            ans+=currVal;
            currVal/=10;
            return;
        }

        solve(root->left,currVal,ans);
        solve(root->right,currVal,ans);
        
    }

    int sumNumbers(TreeNode* root) {

        int ans=0;
        if(!root)return ans;

        solve(root, 0,ans);

        return ans;
    }
};