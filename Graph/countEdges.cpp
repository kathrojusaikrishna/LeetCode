// Problem: Count edges
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: simple iteration
// Time: O(v+e)
// Space: O(1) 

class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
        // code here
        int n =adj.size();
        int count=0;
        for(int i=0;i<n;i++){
            count += adj[i].size();
        }
        
        return count/2;
    }
};