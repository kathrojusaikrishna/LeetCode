// Problem: N Queens
// Difficulty: Hard
//platform: Leetcode
// Approach: using recursion + backtracking
// Time: O(N! * N^2)
// Space: O(n) 

class Solution {
public:
    vector<string> board;
    vector<vector<string>>ans;
    bool check(int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Q') {
                    int prow = i;
                    int pcol = j;

                    if (pcol == col || abs(pcol - col) == abs(prow - row)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void solve(int row, int n) {

        if (row == n){
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(row, i, n)) {
                board[row][i] = 'Q';
                solve(row + 1, n);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));

        solve(0,n);

        return ans;
    }
};