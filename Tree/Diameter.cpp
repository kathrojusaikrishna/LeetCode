// Problem: Diameter of a tree
// Difficulty: Easy
// Approach: Recursion
// Time: O(n)
// Space: O(1)


class Solution {
public:
    int depth(TreeNode* root, int &diameter){

        if(!root)return 0;

        int left = depth(root->left,diameter);
        int right = depth(root->right,diameter);

        diameter = max(diameter,left+right);

        return 1+ max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter=0;
        int ans = depth(root,diameter);

        return diameter;
    }
};