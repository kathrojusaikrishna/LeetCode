// Problem: Find perimeter
// Difficulty: Easy
// Platform : Geeksforgeeks
// Approach: simple iteration and adding total then removing comming boundaries
// Time: O(n*m)
// Space: O(1)

class Solution {
	public:
	int findPerimeter(vector<vector<int>> &mat) {
		// code here
		
		int n = mat.size();
		int m = mat[0].size();
		
		int ans = 0;
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				
				if (mat[i][j] == 1) {
					ans += 4;
					
					int dr[] = {1, -1, 0, 0};
					int dc[] = {0, 0, -1, 1};
					
					for (int k = 0; k<4; k++) {
						int nr = i + dr[k];
						int nc = j + dc[k];
						
						if (nr >= 0 && nr<n && nc >= 0 && nc<m && mat[nr][nc] == 1) {
							ans -= 1;
						}
					}
				}
			}
		}
		
		return ans;
	}
};
