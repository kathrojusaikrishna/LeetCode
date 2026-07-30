// Problem: Number of provinces - DSU
// Difficulty: Medium
//platform: Leetcode
// Approach: Disjoint set union
// Time: O(n*n)
// Space: O(n)

class Solution {
        vector<int>parent,size;
public:

    void makeset(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int node){
        if(parent[node]==node)return node;
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
            size[pv] += size[pu];
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        unordered_set<int>st;

        makeset(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    solveUnion(i,j);
                }
            }
        }

        for(int i=0;i<n;i++){
            st.insert(find(i));
        }

        return st.size();
    }
};