// Problem: Minimum number of vertices to reach all nodes
// Difficulty: Medium
//platform: Leetcode
// Approach: Check the indegree
// Time: O(V+E)
// Space: O(V)

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int>ans;
        vector<int>indegree(n,0);

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            indegree[v]++;
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0)ans.push_back(i);
        }
        return ans;
    }
};