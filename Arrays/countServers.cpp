// Problem: Count the servers that communicate
// Difficulty: Medium
// Platform: Leetcode
// Approach: count total - servers with zero common server in same row and col
// Time: O(n*n)
// Space: O(n)

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int total=0;
        int counter=0;
        unordered_map<int,unordered_set<int>>row,col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    total++;
                    row[i].insert(j);
                    col[j].insert(i);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(row[i].size()==1 && col[j].size()==1){
                        total-=1;
                    }
                }
            }
        }

        return total;
    }
};