// Problem: Shortest path in 1-2 graph
// Difficulty: Hard
//platform: Geeksforgeeks
// Approach: Standard Dijkstras algo
// Time: O((V+E)logV)
// Space: O(V+E) - for adjancency list distance vector

class Solution {
  public:
    int shortestPath(int n, int src, int dest, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        for(auto& e: edges){
            int u = e[0];
            int v = e[1];
            
            int w = e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        dist[src]=0;
        pq.push({0,src});
        
        
        while(!pq.empty()){
            
            auto &vec = pq.top();
            
            int cost = vec[0];
            int node = vec[1];
            
            pq.pop();
            
            if(cost > dist[node])continue;
            
            for(auto& [nextNode, nextCost] : adj[node]){
                
                if(dist[node] + nextCost < dist[nextNode]){
                    dist[nextNode] = dist[node]+nextCost;
                    
                    pq.push({dist[nextNode],nextNode});
                }
            }
        }
        
        if(dist[dest]==INT_MAX)return -1;
        else return dist[dest];
    }
};