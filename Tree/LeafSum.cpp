// Problem: Sum of leaves
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: recursion
// Time: O(n)
// Space: O(1) 
class Solution {
  public:
  
    void solve(Node* root, int &sum){
        if(!root)return;
        if(!root->left && !root->right){
            sum += root->data;
        }
        
        solve(root->left,sum);
        solve(root->right,sum);
    }
    int leafSum(Node* root) {
        // code here
        int sum=0;
        if(!root)return sum;
        
        solve(root, sum);
        
        return sum;
    }
};