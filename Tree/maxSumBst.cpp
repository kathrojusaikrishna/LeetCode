// Problem: Maximum sum BST in Binary tree
// Difficulty: Hard
//platform: Leetcode
// Approach: Tree DP & Bottom-up dfs
// Time: O(n)
// Space: O(1) 

class Solution {
public:

    int ans=0;
    struct info{
        int minVal;
        int maxVal;
        int sum;
        bool isBst;
    };

    info dfs(TreeNode* root){
        if(!root){return{INT_MAX,INT_MIN,0,true};}

        info left = dfs(root->left);
        info right = dfs(root->right);

        if(left.isBst && right.isBst && left.maxVal < root->val && root->val<right.minVal){
            int tempSum = root->val + left.sum+right.sum;
            ans = max(ans,tempSum);
            return {min(left.minVal,root->val), max(right.maxVal,root->val), root->val+left.sum+right.sum,true};
        }

        return {INT_MAX,INT_MIN,0,false};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};