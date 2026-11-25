// Problem: Subtree size after changes
// Difficulty: Medium
//platform: Leetcode
// Approach: dfs + backtracking 
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>>adj,modified;
    vector<int>last;
    vector<int>newParent;

    int dfs(int u, vector<int>& ans){
        ans[u]=1;

        for(auto& v : modified[u]){
            ans[u] += dfs(v,ans);
        }
        return ans[u];
    }
    void findParent(int u, string& s){

        int c = s[u]-'a';
        int prev = last[c];

        if(prev!=-1){
            newParent[u] = prev;
        }
        
        last[c] = u;
        for(auto& v : adj[u]){
            findParent(v,s);
        }

        last[c] = prev;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        modified.resize(n);
        newParent = parent;

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }


        last.assign(26,-1);

        findParent(0,s);

        for(int i=1;i<n;i++){
            modified[newParent[i]].push_back(i);
        }

        vector<int>ans(n,0);

        dfs(0,ans);

        return ans;

    }
};