// Problem: Topological sort
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Topological sort - using queue
// Time: O(V+E)
// Space: O(V) - using queue data structure 

class Solution {
  public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);
        queue<int>q;
        
        for(auto& e:edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)q.push(i);
        }
        
        vector<int>topo;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto& v : adj[node]){
                inDegree[v]--;
                
                if(inDegree[v]==0)q.push(v);
            }
        }
        
        if(topo.size()==n)return topo;
        
        return {};
    }

};