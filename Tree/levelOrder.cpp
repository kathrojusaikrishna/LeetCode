// Problem: Level Order traversal
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: Queue
// Time: O(n)
// Space: O(n) -> for queue

class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root) {
        // code here
        
        vector<vector<int>>ans;
        if(!root)return ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int>level;
            
            for(int i=0;i<size;i++){
                
                Node* temp = q.front();
                q.pop();
                
                level.push_back(temp->data);
                
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                
                
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};