// Problem: Redundant Connections 2
// Difficulty: Medium
//platform: Leetcode
// Approach: Disjoint Set Union
// Time: O(E)
// Space: O(n)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {

        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void solveUnion(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, -1);
        vector<vector<int>> temp;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (parent[v] != -1) {
                temp.push_back({parent[v], v});
                temp.push_back({u, v});
            }
            parent[v] = u;
        }

        if (temp.size() != 0) {
            DSU A(n);

            for (auto& e : edges) {
                int u = e[0];
                int v = e[1];

                if (u == temp.back()[0] && v == temp.back()[1])
                    continue;

                if (A.find(u) == A.find(v)) {
                    return temp[0];
                }
                A.solveUnion(u, v);
            }

            return temp[1];
        }else{
            DSU A(n);

            for(auto& e :  edges){
                int u = e[0];
                int v = e[1];

                if(A.find(u)==A.find(v)){
                    return {u,v};
                }
                A.solveUnion(u,v);
            }
        }
        return temp[0];
    }
};