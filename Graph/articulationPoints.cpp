// Problem: Articulation points
// Difficulty: Hard
//platform: Geeksforgeeks
// Approach: Standard articulation points algorithm
// Time: O(V+E)
// Space: O(V+E)

class Solution {
  private:
    
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,int& timer,unordered_set<int>& mark){
        
        disc[node] = low[node] = timer++;
        
        int children=0;
        
        for(auto& v : adj[node]){
            if(v==parent)continue;
            
            if(disc[v]==-1){
                
                dfs(v,node,adj,disc,low,timer,mark);
                
                low[node] = min(low[v],low[node]);
                
                if(low[v] >= disc[node] && parent!= -1){
                    mark.insert(node);
                }
                
                children++;
            }else{
                
                low[node] = min(low[node],disc[v]);
            }
        }
        
        if(children > 1 && parent==-1){
            mark.insert(node);
        }
    }
  public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // code here
        
        vector<int>disc(n,-1),low(n,0);
        vector<vector<int>>adj(n);
        unordered_set<int>mark;
        vector<int>ans;
        int timer=0;
        
        for(auto& e : edges){
            int u = e[0];
            int v= e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                dfs(i,-1,adj,disc,low,timer,mark);
            }
        }
        
        for(auto& x : mark){
            ans.push_back(x);
        }
        
        if(mark.size()==0)return {-1};
        else return ans;
        
    }
};