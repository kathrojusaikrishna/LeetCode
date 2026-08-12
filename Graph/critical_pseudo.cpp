// Problem: Find the critical and pseudo critical edges in the graph
// Difficulty: Hard
//platform: Leetcode
// Approach: kruskal + checking cases
// Time: O(E^2)
// Space: O(V+E)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    bool solveUnion(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        return true;
    }
};

class Solution {
private:
    int kruskal(int n, vector<vector<int>>& edges, int force, int skip) {

        DSU A(n);
        int edgeCount = 0;
        int cost = 0;

        if(force != -1){
            auto &e = edges[force];
            A.solveUnion(e[0],e[1]);
            cost += e[2];
            edgeCount ++;
        }

        for (int i=0;i<edges.size();i++) {

            if(i==skip || i==force)continue;
            if (A.solveUnion(edges[i][0], edges[i][1])) {
                cost += edges[i][2];
                edgeCount++;
                if(edgeCount == n-1)break;
            }
        }
        if(edgeCount != n-1)return INT_MAX;

        return cost;
    }

public:
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans(2);
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int baseCost = kruskal(n, edges, -1, -1);

        for (int i = 0; i < edges.size(); i++) {
            int without = kruskal(n, edges, -1, i);
            if (without > baseCost)
                ans[0].push_back(edges[i][3]);
            else{
                int with = kruskal(n,edges,i,-1);
                if(with == baseCost){
                    ans[1].push_back(edges[i][3]);
                }
            }    
        }

        return ans;
    }
};