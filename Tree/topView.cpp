// Problem: Top view
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using queue
// Time: O(n)
// Space: O(h) -> for queue


class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        
        vector<int>ans;
        if(!root)return ans;
        
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            int size= q.size();
            
            for(int i=0;i<size;i++){
                
                auto [temp, vertical] = q.front();
                q.pop();
                
                if(mp.find(vertical)== mp.end()) mp[vertical]=temp->data;
                
                if(temp->left)q.push({temp->left,vertical-1});
                if(temp->right)q.push({temp->right,vertical+1});
            }
        }
        
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};