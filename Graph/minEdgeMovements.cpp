// Problem: Min edge movements to connect a graph
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: DSU for connected components (min of extra edges and components-1)
// Time: O(V+E)
// Space: O(n)

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
           parent[pu] = pv;
           size[pv]+= size[pu];
       }
       
       return true;
   }
};

class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        
        DSU A(n);
        unordered_set<int>st;
        int extra=0;
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            
            if(!A.solveUnion(u,v)){
                extra++;
            }
        }
        
        for(int i=0;i<n;i++){
            st.insert(A.find(i));
        }
        
        if(edges.size() < n-1)return -1;
        
        if(extra >= st.size()-1)return st.size()-1;
        
        return -1;
    }
};