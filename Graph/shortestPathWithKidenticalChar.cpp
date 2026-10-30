// Problem: Shortest Path With At Most K Consecutive Identical Characters
// Difficulty: Medium
//platform: Leetcode
// Approach: Dijkstra with 2 states
// Time: O(E*Klog(V*K))
// Space: O(V*K+E) 

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));

        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(auto& e : edges){
            int u=e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
        }

        queue<pair<int,int>>q;
        pq.push({0,0,1});
        dist[0][1]=0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            int cost = p[0];
            int node = p[1];
            int iden = p[2];

            if(cost > dist[node][iden])continue;

            for(auto& [newNode, newCost] : adj[node]){

                int newK = labels[node]==labels[newNode]? iden+1 : 1;
                if(newK <= k){
                    if(cost+newCost < dist[newNode][newK]){

                        dist[newNode][newK] = cost + newCost;

                        pq.push({dist[newNode][newK],newNode,newK});
                    }
                }
            }
        }

        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
            ans = min(ans,dist[n-1][i]);
        }
        return ans==INT_MAX? -1 : ans;

    }
};