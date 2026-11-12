// Problem: Close in BST
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: simple iteration and global variable
// Time: O(h)
// Space: O(h)

class Solution {
  public:
    int minDiff(Node *root, int k) {
        // code here
        Node* curr = root;
        int ans=INT_MAX;
        
        while(curr){
            
            ans = min(ans, abs(curr->data-k));
            if(k==curr->data)return 0;
            else if(k>curr->data){
                curr=curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        
        return ans;
    }
};
