// Problem: Minimum cost to connect all points - type 2
// Difficulty: Medium
//platform: Leetcode
// Approach: Prim type 2 using minDist array for dense connections
// Time: O(n^2)
// Space: O(n) - min dist array

class Solution{
public:
    int minCostConnectPoints(vector<vector<int>>& points){

        int n = points.size();
        vector<bool>vis(n,false);

        vector<int>minDist(n,INT_MAX);
        minDist[0]=0;

        int ans=0;

        for(int i=0;i<n;i++){
            int node = -1;

            for(int j=0;j<n;j++){
                if(!vis[j] && (node==-1 || minDist[j] < minDist[node])){
                    node=j;
                }
            }

            vis[node]=true;
            ans += minDist[node];

            for(int next=0;next<n;next++){
                if(vis[next])continue;

                int d = abs(points[node][0]-points[next][0]) + abs(points[node][1]-points[next][1]);

                minDist[next] = min(minDist[next],d);
            }
        }

        return ans;
    }
};