// Problem: Course Schedule
// Difficulty: Medium
//platform: Leetcode
// Approach: connected components + cycle detection
// Time: O(V(V+E))
// Space: O(V)

class Solution {
public:
    bool dfs(int course, vector<bool>& vis, vector<bool>& pathVis, vector<vector<int>>& adj){

        vis[course]=true;
        pathVis[course]=true;

        for(auto &nextCourse : adj[course]){
            if(!vis[nextCourse]){
                if(dfs(nextCourse,vis,pathVis,adj)){
                    return true;
                }
            }
            else if(pathVis[nextCourse]){
                return true;
            }
        }

        pathVis[course]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>vis(numCourses,false);
        vector<bool>pathVis(numCourses,false);

        if(prerequisites.empty())return true;

        for(auto& prerequisite : prerequisites){
            int course1 = prerequisite[0];
            int course2 = prerequisite[1];

            adj[course2].push_back(course1); 
        }

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)){
                    return false;
        }
            }
        }

        return true;
    }
};