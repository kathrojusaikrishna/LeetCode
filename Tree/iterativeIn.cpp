// Problem: Iterative In order
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: using stack
// Time: O(n)
// Space: O(n) -> for stack

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        
        vector<int>ans;
        if(!root)return ans;
        
        Node* curr = root;
        
        stack<Node*>st;
        
        while(1){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                if(st.empty()==true)break;
                curr = st.top();
                st.pop();
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};