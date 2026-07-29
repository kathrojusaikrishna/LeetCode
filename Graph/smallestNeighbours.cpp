// Problem:  Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Difficulty: Medium
//platform: Leetcode
// Approach: Floyd-warshall algorithm based
// Time: O(n*n*n)
// Space: O(n*n) 

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){

                for(int j=0;j<n;j++){
                    if(dist[i][k]!= INT_MAX && dist[k][j]!=INT_MAX){

                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int counter=0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold)counter++;
            }
            mini = min(mini,counter);
        }

        for(int i=n-1;i>=0;i--){
            int counter=0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold)counter++;
            }
            if(counter==mini)return i;
        }

        return 0;
    }
};