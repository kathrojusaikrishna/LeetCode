// Problem: Number of provinces
// Difficulty: Medium
//platform: Leetcode
// Approach: connected components
// Time: O(n*n)
// Space: O(n)

class Solution {
public:

    void dfs(int city, vector<bool>& vis, vector<vector<int>>& isConnected){

        vis[city]=true;

        for(int next=0;next<isConnected.size();next++){
            if(isConnected[city][next]==1 && !vis[next]){
                dfs(next,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<bool>vis(n,false);
        int provinces=0;

        for(int city=0;city<n;city++){
            if(!vis[city]){
                provinces++;
                dfs(city,vis,isConnected);
            }
        }

        return provinces;
    }
};