// Problem: Course Schedule II
// Difficulty: Medium
//platform: Leetcode
// Approach: Topological sort - using queue
// Time: O(V+E)
// Space: O(V) - using queue data structure 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses,0);

        queue<int>q;

        for(auto& prerequisite : prerequisites){

            int course1 = prerequisite[0];
            int course2 = prerequisite[1];

            adj[course2].push_back(course1);

            inDegree[course1]++;
        }

        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)q.push(i);
        }

        vector<int>topo;

        while(!q.empty()){

            int course = q.front();
            q.pop();

            topo.push_back(course);

            for(auto& nextCourse : adj[course]){
                inDegree[nextCourse]--;

                if(inDegree[nextCourse]==0)q.push(nextCourse);
            }
        }

        if(topo.size()==numCourses)return topo;

        return {};
    }
};