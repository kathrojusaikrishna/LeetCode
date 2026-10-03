// Problem: coils in matrix
// Difficulty: Medium
// Platform: Geeksforgeeks
// Approach: Spiral approach for coil 1 and for each element in coil 1 add total+1-coil[i] to coil2
// Time: O(n*n)
// Space: O(n*n)

class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        // code here
        
        int N = 4*n;
        
        int top = 0;
        int down = N-1;
        int left=0;
        int right=N-2;
        
        int k=1;
        
        vector<vector<int>>mat(N,vector<int>(N));
        
        for(int i=top;i<N;i++){
            for(int j=left;j<N;j++){
                mat[i][j]=k;
                k++;
            }
        }
        
        vector<int>temp1;
        vector<int>temp2;
        
        vector<vector<int>>ans;
        
        while(top<=down){
            
            for(int i=top;i<=down;i++){
                temp1.push_back(mat[i][left]);
            }
            
            
            for(int i=left+1;i<=right;i++){
                temp1.push_back(mat[down][i]);
            }
            
            
            for(int i=down-1;i>=top+1;i--){
                temp1.push_back(mat[i][right]);
            }
            
            
            for(int i=right-1;i>=left+2;i--){
                temp1.push_back(mat[top+1][i]);
            }
            
            left+=2;
            right-=2;
            top+=2;
            down-=2;
        }
        
        ans.push_back(temp1);
        
        int total = N*N;
        for(int x : temp1){
            temp2.push_back(total+1-x);
        }
        
        ans.push_back(temp2);
        
        return ans;
    }
};