// Problem: Minimum Toggle to partition
// Difficulty: Easy
// Approach: checking no.of wrongs at each index for both left and right
// Time: O(n)
// Space: O(n) 

class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>left(n+1,0);
        vector<int>right(n+1,0);
        
        for(int i=1;i<=n;i++){
            left[i] = left[i-1] + (arr[i-1]==1);
        }
        
        for(int i=n-1;i>=0;i--){
            right[i] = right[i+1] + (arr[i]==0);
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<=n;i++){
            ans = min(ans, left[i]+right[i]);
        }
        
        return ans;
    }
    
};