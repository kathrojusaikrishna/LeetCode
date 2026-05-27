// Problem: Build BST from preorder
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: iteration through pre order
// Time: O(n)
// Space: O(n) -> for queue

class Solution {
  public:
    
    
    Node* build(Node* root, int val){
        
        if(!root) return new Node(val);
        
        if(val < root->data){
            root->left = build(root->left, val);
        }else{
            root->right = build(root->right, val);
        }
        
        return root;
    }
    Node* preToBST(vector<int>& pre) {
        // code here
        
        Node* root = nullptr;
        
        for(int i=0;i<pre.size();i++){
            root = build(root,pre[i]);
        }
        
        return root;
    }
 
};