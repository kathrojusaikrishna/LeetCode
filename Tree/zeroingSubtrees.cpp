// Problem: Maximizing score after zeroing the subtrees
// Difficulty: Medium
//platform: Leetcode
// Approach: bottom up
// Time: O(n)
// Space: O(n) 

class Solution {
public:

    vector<int> op;
    vector<vector<int>>adj;
    vector<int> score;
    
    int dfs(int u){

        int total = score[u];
        int nm = INT_MAX;

        for(auto& v : adj[u]){

            int child = dfs(v);

            total += child;
            nm = min(nm,child);
        }

        if(nm==INT_MAX){
            return score[u];
        }

        if(op[u]==0){
            return total - min(0,nm);
        }
        else{
            return total - nm;
        }
        
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {

        int n = parent.size();
        vector<vector<int>>adj(n);

        this->op = op;
        this->score = score;

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }

        this->adj = adj;

        return dfs(0);

        
    }
};