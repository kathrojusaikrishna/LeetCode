// Problem: Redundant Connections
// Difficulty: Medium
//platform: Leetcode
// Approach: Disjoint Set Union
// Time: O(E)
// Space: O(n)

class Solution {
    vector<int>parent,size;
public:
    void makeset(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void solveUnion(int u, int v){

        int pu = find(u);
        int pv = find(v);

        if(pu==pv)return;

        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu] += size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        makeset(n);
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            if(find(u)==find(v))return {u,v};

            solveUnion(u,v);

        }

        return {};
    }
};