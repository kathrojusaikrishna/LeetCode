
// Problem: Minimum swaps to arrange a binary grid
// Difficulty: Medium
// Approach: Iteration
// Time: O(n^2)
// Space: O(n)


class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<int> maxRight(n, -1);

        
        for(int i = 0; i < n; i++){
            for(int j = m - 1; j >= 0; j--){
                if(grid[i][j] == 1){
                    maxRight[i] = j;
                    break;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; ++i){
            int j = i;

            while(j < n && maxRight[j] > i) j++;

            if(j == n) return -1;

            while(j > i){
                swap(maxRight[j], maxRight[j - 1]);
                j--;
                ans++;
            }
        }

        return ans;
    }
};