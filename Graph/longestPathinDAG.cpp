// Problem: Longest path in a directed acyclic graph
// Difficulty: Hard
//platform: Geeksforgeeks
// Approach: topo to find the order and for each node find the max dist to all other neighbors
// Time: O(V+E)
// Space: O(V+E)

class Solution {
  public:
    vector<int> maxDistance(int n, int src, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<pair<int,int>>>adj(n);
        queue<int>q;
        vector<int>indegree(n,0);
        for(auto& e : edges){
            int u = e[0];
            int v =e[1];
            int w = e[2];
            
            adj[u].push_back({v,w});
            indegree[v]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>topo;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto& [v,w] : adj[node]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        
        vector<int>dist(n,INT_MIN);
        dist[src]=0;
        
        for(auto& u : topo){
            
            if(dist[u]==INT_MIN)continue;
            
            for(auto& [v,w] : adj[u]){
                dist[v] = max(dist[v],dist[u]+w);
            }
        }
        
        return dist;
    }
};