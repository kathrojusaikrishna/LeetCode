// Problem: Vertical Sum
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: iteration through level order
// Time: O(nlogn)
// Space: O(n) 

class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        
        vector<int>ans;
        if(!root)return ans;
        
        
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                
                auto p = q.front();
                q.pop();
                
                Node* temp = p.first;
                int vertical = p.second.first;
                int level = p.second.second;
                
                nodes[vertical][level].insert(temp->data);
                
                if(temp->left){
                    q.push({temp->left,{vertical-1,level+1}});
                }
                
                if(temp->right){
                    q.push({temp->right,{vertical+1,level+1}});
                }
                
            }
        }
        
        for(auto vertical : nodes){
            int sum=0;
            for(auto level : vertical.second){
                
                for(auto value : level.second){
                    sum += value;
                }
                
            }
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};