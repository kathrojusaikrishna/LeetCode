// Problem: Network Pathways
// Difficulty: Hard
//platform: Leetcode
// Approach: using binary search + (topo sort || dijkstras algo)
// Time: O((V+E)logW))


class Solution {
public:

    long long solve(int n,vector<vector<int>>& edges, int mid,vector<bool>& online){

        vector<vector<pair<int,int>>>adj(n);
        vector<int>indegree(n,0);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(w>=mid){
                adj[u].push_back({v,w});
                indegree[v]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>topo;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for(auto &[v,w] : adj[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }


        const long long INF = LLONG_MAX/2;
        vector<long long>dist(n,INF);

        dist[0]=0;

        for(int u:topo){

            if(dist[u]==INF)continue;

            if(u!=0 && u!=n-1 && !online[u])continue;

            for(auto &[v,w]: adj[u]){

                if(v!=n-1 && !online[v])continue;

                dist[v] = min(dist[v],dist[u]+w);
            }
        }

        return dist[n-1];
    }

    int mini(vector<vector<int>>& edges){
        int ans=INT_MAX;
        for(int i=0;i<edges.size();i++){
            ans = min(ans,edges[i][2]);
        }
        return ans;
    }

    int maxi(vector<vector<int>>& edges){
        int ans=INT_MIN;
        for(int i=0;i<edges.size();i++){
            ans = max(ans,edges[i][2]);
        }
        return ans;
    }


    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        if(edges.empty())return -1;
        
        int low = mini(edges);
        int high = maxi(edges);
        int n = online.size();
        int ans=-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(solve(n,edges,mid,online)<=k){
                ans=mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return ans;
    }
};