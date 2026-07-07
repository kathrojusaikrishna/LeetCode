// Problem: Keys and rooms
// Difficulty: Medium
//platform: Leetcode
// Approach: DFS traversal
// Time: O(V+E)
// Space: O(1)

class Solution {
public:

    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int source){

        vis[source] =true;

        for(auto& v : rooms[source]){
            if(!vis[v]){
                dfs(rooms,vis,v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n);

        dfs(rooms,vis,0);

        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }

        return true;


    }
};