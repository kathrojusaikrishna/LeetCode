// Problem: Minimum Spanning tree
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Sort + DSU
// Time: O(ElogE)
// Space: O(V)


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
        
        return parent[node]= find(parent[node]);
    }
    
    void solveUnion(int u, int v){
        int pu = find(u);
        int pv = find(v);
        
        if(pu==pv)return;
        
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu] +=size[pv];
        }else{
            parent[pu] =pv;
            size[pv] +=size[pu];
        }
    }
};

class Solution {
  public:
    int kruskalsMST(int n, vector<vector<int>> &edges) {
        // code here
        
        int cost=0;
        DSU A(n);
        sort(edges.begin(), edges.end(), [](const vector<int>&a,const vector<int>&b){
            return a[2] <b[2];
        });
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            if(A.find(u)!=A.find(v)){
                A.solveUnion(u,v);
                cost += wt;
            }
        }
        
        return cost;
        
        
    }
};