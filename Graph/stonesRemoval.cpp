// Problem: Most stones removed with same row or column
// Difficulty: Medium
//platform: Leetcode
// Approach: DSU - each row and col as node connected them find connected components
// Time: O(n)
// Space: O(1)

class Solution {
    unordered_set<int>used;
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
            parent[pv]=pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        unordered_set<int>st;

        makeset(20002);
        for(auto& stone : stones){

            int x = stone[0];
            int y = 10001 + stone[1];

            solveUnion(x,y);

            used.insert(x);
            used.insert(y);
        }

        for(int node : used){
            st.insert(find(node));
        }


        return n - st.size();


    }
};