// Problem: Minimum cost to connect all points
// Difficulty: Medium
//platform: Leetcode
// Approach: for every point , check with every other point which is not visited - Prim
// Time: O(n^2logn)
// Space: O(n^2) - min heap


class Solution{
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool>vis(n,false);

        pq.push({0,0});

        int cost=0;

        while(!pq.empty()){

            auto top = pq.top();
            pq.pop();

            int w = top.first;
            int node = top.second;

            if(vis[node])continue;

            vis[node]=true;
            cost += w;

            for(int next=0;next<n;next++){

                if(!vis[next]){
                    int nextWeight = abs(points[node][0]-points[next][0]) + abs(points[node][1]-points[next][1]);

                    pq.push({nextWeight,next});
                }

            }
        }

        return cost;
    }
};