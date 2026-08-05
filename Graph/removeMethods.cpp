// Problem: Remove methods from project
// Difficulty: Medium
//platform: Leetcode
// Approach: Simple Dfs 
// Time: O(V+E)
// Space: O(V+E) 

class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<bool>& threat, int node){
        threat[node]=true;

        for(auto& v : adj[node]){
            if(!threat[v]){
                dfs(adj,threat,v);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<bool>threat(n,false);
        vector<vector<int>>adj(n);
        vector<int>ans;
        bool Remove = false;

        for(auto& e : invocations){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
        }

        dfs(adj,threat,k);

        for(auto& e : invocations){
            int u = e[0];
            int v = e[1];

            if(!threat[u] && threat[v]){
                Remove=true;
                break;
            }
        }

        if(Remove){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }else{
            for(int i=0;i<n;i++){
                if(!threat[i])ans.push_back(i);
            }
        }

        return ans;
    }
};
