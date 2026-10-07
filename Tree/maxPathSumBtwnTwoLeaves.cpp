// Problem: Max path sum between two leaves
// Difficulty: Hard
//platform: Geeksforgeeks
// Approach: Bottom-up dfs
// Time: O(n)
// Space: O(1) 

class Solution {
  public:
    int solve(Node* root,int& leaves, int& ans){
        
        if(!root)return -1e9;
        if(!root->left && !root->right){
            leaves++;
            return root->data;
            
        }
        
        int left = solve(root->left,leaves,ans);
        int right = solve(root->right,leaves,ans);
        
        ans = max(ans, left+right+root->data);
        if(root->left && root->right){
            
            return max(left,right)+root->data;
        }
        if(!root->left){
            return root->data + right;
        }
        if(!root->right){
            return root->data + left;
        }
        
        return max(left,right)+root->data;
    }
    int maxPathSum(Node *root) {
        // code here
        
        if(!root)return -1;
        int leaves=0;
        int ans = -1e9;
        
        solve(root,leaves,ans);
        if(leaves<2)return -1;
        return ans==-1e9 ? -1 : ans;
        
        
        
        
    }
};