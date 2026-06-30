// Problem: Largest BST
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using botton-up dfs
// Time: O(n)
// Space: O(h) 

class Solution {
  public:
  struct info{
        int minVal;
        int maxVal;
        bool isBST;
        int size;
    };
    
    info dfs(Node* root){
        if(!root){
            return {INT_MAX,INT_MIN,true,0};
        }
        
        info left = dfs(root->left);
        info right = dfs(root->right);
        
        if(left.isBST && right.isBST && left.maxVal < root->data && root->data < right.minVal){
            return {
                min(root->data,left.minVal), max(root->data,right.maxVal),
                true,1+left.size+right.size
            };
        }
        
        return {
            INT_MAX,INT_MIN,false,max(left.size,right.size)
        };
    }
  
    int largestBst(Node *root) {
        // code here
        
        return dfs(root).size;
 
    }
};