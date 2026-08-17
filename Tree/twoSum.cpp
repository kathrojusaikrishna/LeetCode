// Problem: Two Sum IV - BST
// Difficulty: easy
//platform: leetcode
// Approach: inorder + two pointers
// Time: O(n)
// Space: O(n)

class Solution {
public:
    void solve(TreeNode* root, vector<int>& inorder){
        if(!root)return;

        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        vector<int>inorder;
        solve(root,inorder);

        int left=0;
        int right = inorder.size()-1;

        while(left<right){
            int sum = inorder[left]+inorder[right];
            if(sum==k)return true;
            if(sum > k)right--;
            else left++;
        }

        return false;
    }
};