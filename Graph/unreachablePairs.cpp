// Problem: Count unreachable pairs of nodes in an undirected graph
// Difficulty: Medium
//platform: Leetcode
// Approach: simple dfs - connected components
// Time: O(V+E)
// Space: O(V+E) 

class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& mp, vector<bool>& vis, int source,long long &count){
        vis[source]=true;
        count++;

        for(auto &v : mp[source]){
            
                if(!vis[v]){
                    dfs(mp,vis,v,count);
                }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>>mp;
        vector<bool>vis(n,false);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        long long ans = (long long)n * (n-1)/2;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long count=0;
                dfs(mp,vis,i,count);
                ans -= count*(count-1)/2;
            }
        }

        return ans;
    }
};