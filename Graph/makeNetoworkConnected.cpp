// Problem: Number of operations to make network connected
// Difficulty: Medium
//platform: Leetcode
// Approach: we can use DFS || Disjoint set union to find the connected components
// Time: O(E+n)
// Space: O(n)

class Solution {
    vector<int>parent,size;
public:
   
    void makeset(int n){
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
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu]=pv;
            size[pv] += size[pu];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edges = connections.size();
        if(edges < n-1)return -1;


        makeset(n);
        unordered_set<int>st;

        for(auto& connection : connections){
            int u = connection[0];
            int v = connection[1];

            solveUnion(u,v);
        }

        for(int i=0;i<n;i++){
            st.insert(find(i));
        }

        return st.size()-1;


    }
};