// Problem: N Queens II
// Difficulty: Hard
//platform: Leetcode
// Approach: using recursion + backtracking
// Time: O(N! * N)
// Space: O(n) 

class Solution {
public:
    vector<int>queens;

    bool check(int row, int col, int n){
        for(int i=0;i<row;i++){
            int prow = i;
            int pcol = queens[i];

            if(pcol==col || abs(prow-row)==abs(pcol-col)){
                return false;
            }
        }
        return true;
    }

    int solve(int row, int n){

        if(row==n)return 1;

        int ans=0;

        for(int i=0;i<n;i++){
            if(check(row,i,n)){
                queens[row]=i;
                ans += solve(row+1,n);

                queens[row] = -1;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        queens.resize(n,-1);
        return(solve(0,n));
    }
};