// Problem: Valid sudoku
// Difficulty: Medium
// Approach: iteration, set
// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        set<char> row[9], col[9], box[9];
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='.')continue;

                char ch = board[i][j];
                int index = (i/3)*3 + (j/3);

                if(row[i].count(ch) || col[j].count(ch) || box[index].count(ch))return false;

                row[i].insert(ch);
                col[j].insert(ch);
                box[index].insert(ch);
            }
        }

        return true;
    }
};