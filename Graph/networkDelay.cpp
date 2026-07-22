// Problem: Netowrk Delay
// Difficulty: Medium
//platform: Leetcode
// Approach: Dijkstras modified , find the shortest time in the graph , finally find the maximum time among them
// Time: O(ElogV)
// Space: O(V)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto& e :times){
            int u = e[0];
            int v = e[1];
            
            int time = e[2];

            adj[u].push_back({v,time});
        }

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){

            auto node = pq.top();
            pq.pop();

            int time = node.first;
            int v = node.second;

            if(time > dist[v])continue;

            for(auto& [neighbor, nextTime] : adj[v]){

                if(nextTime + dist[v] < dist[neighbor]){

                    dist[neighbor] = nextTime + dist[v];

                    pq.push({dist[neighbor], neighbor});

                }
            }
        }

        int ans = -1;

        for(int i=1;i<n+1;i++){
            
            if(dist[i] == INT_MAX)return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};