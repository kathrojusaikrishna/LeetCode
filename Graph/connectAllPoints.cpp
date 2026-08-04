// Problem: Minimum cost to connect all points
// Difficulty: Medium
//platform: Leetcode
// Approach: generate cost for each edge and apply kruskals algo
// Time: O(n^2logn)
// Space: O(n^2) - Generating edges

class DSU{
public:
    vector<int>parent,size;

    DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);

        for(int i=0;i<n;i++){
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
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        DSU A(n);
        int cost=0;
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j)continue;

                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1]-points[j][1]);

                edges.push_back({i,j,w});
            }
        }

        sort(edges.begin(), edges.end(), [](const vector<int>&a, const vector<int>&b){
            return a[2]<b[2];
        });

        int edgesUsed=0;
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(A.find(u)!=A.find(v)){
                A.solveUnion(u,v);
                cost += w;
                edgesUsed++;

                if(edgesUsed==n-1)break;
            }
        }

        return cost;
    }
};