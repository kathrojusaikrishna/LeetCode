// Problem: Complete Binary Tree Traversal with Array Input
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Level order traversal and min heap
// Time: O(nlogn)
// Space: O(n)

class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        
        vector<vector<int>>ans;
        
        int n = arr.size();
        if(n==0)return ans;
        
        queue<pair<int,int>>q;
        q.push({arr[0],0});
        
        while(!q.empty()){
            int size = q.size();
            priority_queue< int, vector<int>, greater<int>>pq;
            vector<int>temp;
            
            while(size--){
                
                int node = q.front().first;
                int index = q.front().second;
                q.pop();
                
                pq.push(node);
                
                if(index*2+1 < n)q.push({arr[index*2+1],index*2+1});
                if(index*2+2 < n)q.push({arr[index*2+2], index*2+2});
            }
            
            while(!pq.empty()){
                int node = pq.top();
                pq.pop();
                
                temp.push_back(node);
            }
            
            ans.push_back(temp);
            
            
        }
        
        
        return ans;
    }
};
