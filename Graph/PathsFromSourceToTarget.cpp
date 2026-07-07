// Problem: Paths from source to target
// Difficulty: Medium
//platform: Leetcode
// Approach: DFS traversal + backtracking
// Time: O(V+E)
// Space: O(v)

class Solution {
public:
    void dfs(vector<vector<int>>& graph , vector<int>path, vector<vector<int>>& ans, int source, int destination){

        path.push_back(source);

        if(source==destination){
            ans.push_back(path);
        }

        for(auto& v : graph[source]){
            dfs(graph, path, ans, v, destination);
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int>path;
        int n = graph.size();
        vector<vector<int>>ans;
        dfs(graph,path,ans,0,n-1);
        return ans;
    }
};