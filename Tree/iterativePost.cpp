// Problem: Iterative Post order
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using stack
// Time: O(n)
// Space: O(n) -> for stack

class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        
        vector<int>ans;
        if(!root)return ans;
        
        stack<Node*>st1;
        stack<Node*>st2;
        
        st1.push(root);
        
        while(!st1.empty()){
            
            Node* temp = st1.top();
            st1.pop();
            
            st2.push(temp);
            if(temp->left)st1.push(temp->left);
            if(temp->right)st1.push(temp->right);
        }
        
        
        while(!st2.empty()){
            Node* temp = st2.top();
            st2.pop();
            
            ans.push_back(temp->data);
        }
        
        return ans;
    }
};