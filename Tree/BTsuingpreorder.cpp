// Problem: Binary tree using pre-order
// Difficulty: Medium
//platform: Leetcode
// Approach: recursion
// Time: O(n)
// Space: O(1)

class Solution {
public:
    
    TreeNode* insert(TreeNode* root, int min, int max, int val)
{
    if(!root)return new TreeNode(val);

    if(root->val >= min && max >= root->val){
        if(val < root->val){
            root->left = insert(root->left,min,root->val,val);
        }else{
            root->right = insert(root->right,root->val,max,val);
        }
    }

    return root;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size()==0)return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insert(root,INT_MIN,INT_MAX,preorder[i]);
        }

        return root;
    }
};