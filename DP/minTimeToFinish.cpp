// Problem: Minimum time to finish the job
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: DP
// Time: O(n+m)
// Space: O(n) 

class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        int n = duration.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        
        vector<int>dp(n);
        for(auto& e : dependencies){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i] = duration[i];
            }
        }
        
        int processed=0;
        int ans = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            processed++;
            ans = max(ans, dp[node]);
            
            for(auto& v : adj[node]){
                
                dp[v] = max(dp[v], dp[node]+duration[v]);
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        
        if(processed != n)return -1;
        
        return ans;
    }
};