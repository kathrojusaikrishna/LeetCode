// Problem: Longest bitonic sequence
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using DP
// Time: O(n*n)
// Space: O(n) -> for dp

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
       
        vector<int>lis(n,1);
        vector<int>dis(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(nums[j]<nums[i]){
                    lis[i] = max(lis[i],lis[j]+1); 
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1; j<n;j++){
                
                if(nums[j] < nums[i]){
                    dis[i] = max(dis[i], dis[j]+1);
                }
            }
        }
        
        int ans =0;
        for(int i=0;i<n;i++){
            
            if(lis[i]>1 && dis[i]>1){
                ans = max(ans, lis[i]+dis[i]-1);
            }
        }
        
        return ans;
    }
};
