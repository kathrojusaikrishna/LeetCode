// Problem: Binary tree cameras
// Difficulty: Hard
//platform: Leetcode
// Approach: Bottom-up dfs && Tree Dp
// Time: O(n)
// Space: O(1)

class Solution {
public:

    enum state{
        NEED,CAMERA,COVERED
    };

    state dfs(TreeNode* root,int &ans){
        if(!root)return COVERED;

        state left = dfs(root->left,ans);
        state right = dfs(root->right,ans);

        if(left==NEED || right==NEED){
            ans++;
            return CAMERA;
        }
        else if(left==CAMERA || right==CAMERA)return COVERED;

        return NEED;
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(!root)return ans;

        if(dfs(root,ans)==NEED)ans++;
        return ans;



    }
};