// Problem: Remove max number of edges to keep graph fully traversable
// Difficulty: Hard
//platform: Leetcode
// Approach: Union Find
// Time: O(n+m)
// Space: O(n) 

class DSU {
public:

    vector<int>parent,size;
    int components;

    DSU(int n){
        components = n;
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

    bool solveUnion(int u, int v){

        int pu = find(u);
        int pv = find(v);

        if(pu==pv)return false;

        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        components--;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU alice(n);
        DSU bob(n);
        int removed=0;

        for(auto& e : edges){
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type==3){
                bool a = alice.solveUnion(u,v);
                bool b = bob.solveUnion(u,v);
                if(!a && !b){
                    removed++;
                }
            }
        }
        for(auto& e : edges){
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type==2){
                bool b = bob.solveUnion(u,v);
                if(!b){
                    removed++;
                }
            }
        }
        for(auto& e : edges){
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type==1){
                bool a = alice.solveUnion(u,v);
                if(!a){
                    removed++;
                }
            }
        }

        if(alice.components != 1 || bob.components !=1)return -1;

        return removed;
    }
};