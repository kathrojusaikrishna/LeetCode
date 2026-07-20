// Problem: Shift 2D grid
// Difficulty: Easy
// Platform: Leetcode
// Approach: rotating the indices and placing the values in result
// Time: O(n*m)
// Space: O(n*m) - for reversing the indices

class Solution {
public:
    void reverse(vector<int>& dup, int start, int end){

        while(start < end){
            int temp = dup[start];
            dup[start] = dup[end];
            dup[end] = temp;

            start++;
            end--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m, vector<int>(n,0));

        vector<int> dup(m * n, 0);
        for (int i = 0; i < m * n; i++) {
            dup[i] = i;
        }

        k = k % (n * m);

        reverse(dup, 0, n*m-k-1);
        reverse(dup, n*m-k, n * m - 1);
        reverse(dup,0, n*m-1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index = i*n +j;
                int row =  dup[index]/n;
                int col = dup[index]%n;

                ans[i][j] = grid[row][col];
            }
        }

        return ans;
    }
};