// Problem: Graph or Tree
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: DSU for cycle detection and multiple edges
// Time: O(E)
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
        
        return parent[node] = find(parent[node]);
    }
    
    bool solveUnion(int u, int v){
        
        int pu = find(u);
        int pv = find(v);
        
        if(pu==pv)return false;
        
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu] += size[pv];
        }else{
            parent[pu]=pv;
            size[pv] += size[pu];
        }
        
        return true;
    }
};


class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &edges) {
        // code here
        
        DSU A(n);
        
        if(m != n-1)return 0;
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            
            if(!A.solveUnion(u,v))return 0;
        }
        
        return 1;
        
    }
};
