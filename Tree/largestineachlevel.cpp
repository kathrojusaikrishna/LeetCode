// Problem: Find Largest in each level
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: using queue
// Time: O(n)
// Space: O(h) -> for queue

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        
        vector<int>ans;
        if(!root)return ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            int maxi = INT_MIN;
            
            for(int i=0;i<size;i++){
                
                Node* temp = q.front();
                q.pop();
                
                maxi = max(maxi,temp->data);
                
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                
            }
            
            ans.push_back(maxi);
        }
        
        return ans;
        
    }
};