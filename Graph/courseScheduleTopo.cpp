// Problem: Course Schedule
// Difficulty: Medium
//platform: Leetcode
// Approach: Topological sort - using queue
// Time: O(V+E)
// Space: O(V) - using queue data structure 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        queue<int>q;

        for(auto& prerequisite : prerequisites){

            int course1 = prerequisite[0];
            int course2 = prerequisite[1];

            adj[course2].push_back(course1);
            indegree[course1]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<int>topo;

        while(!q.empty()){

            int course = q.front();
            q.pop();

            topo.push_back(course);

            for(auto& nextCourse : adj[course]){
                indegree[nextCourse]--;

                if(indegree[nextCourse]==0)q.push(nextCourse);
            }
        }

        return topo.size()==numCourses;

    }
};