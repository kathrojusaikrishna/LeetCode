// Problem: Image Overlap
// Difficulty: Medium
// Platform: Leetcode
// Approach: bruteforce
// Time: O(n^4)
// Space: O(1)

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();
        int ans=0;

        for(int dr = -(n-1); dr<=n-1;dr++){
            for(int dc = -(n-1); dc<=n-1;dc++){
                
                int overlap=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){

                        int nr = i+dr;
                        int nc = j + dc;

                        if(nr<0 || nr>=n || nc<0 || nc>=n)continue;
                        if(img1[i][j]==1 && img2[nr][nc]==1){
                            overlap++;
                        }
                    }
                }

                ans = max(ans,overlap);
            }
        }

        return ans;
    }
};