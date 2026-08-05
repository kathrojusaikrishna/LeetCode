// Problem: FInd eventual safe states
// Difficulty: Medium
//platform: Leetcode
// Approach: reverse + topological
// Time: O(V+E)
// Space: O(V+E) 

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int>topo;
        vector<bool>safe(n,false);
        vector<int>inDegree(n,0);
        queue<int>q;

        vector<vector<int>>rev(n);

        for(int i=0;i<n;i++){
            for(auto&v : graph[i]){
                rev[v].push_back(i);
                inDegree[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe[node]=true;
            for(auto&v : rev[node]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(safe[i])topo.push_back(i);
        }

        return topo;
    }
};