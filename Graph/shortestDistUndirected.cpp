// Problem: Shortest Distance in an undirected graph
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using queue
// Time: O(V+E)
// Space: O(V) - using queue data structure 

class Solution {
  public:
    int shortestPath(int n, vector<vector<int>> &edges, int src, int dest) {
        // code here
        
        vector<vector<int>>adj(n);
        vector<int>dist(n,-1);
        queue<int>q;
        
        for(auto&e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        q.push(src);
        dist[src]=0;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto&v : adj[node]){
                if(dist[v]==-1){
                    dist[v] = dist[node]+1;
                    q.push(v);
                }
            }
        }
        
        return dist[dest];
        
    }
};
