// Problem: Max frequency with at most k increments 
// Difficulty: Medium
// Platform: Geeksforgeeks
// Approach: sliding window
// Time: O(nlogn)
// Space: O(1)

class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        
        sort(arr.begin(),arr.end());
        int left=0;
        int ans=0;
        
        int wsum=0;
        
        for(int right = 0;right<arr.size();right++){
            wsum += arr[right];
            
        
            while(arr[right]*(right-left+1) - wsum > k){
                wsum -= arr[left];
                left++;
            }
            
            ans = max(ans, right-left+1);
        }
        
        return ans;
        
    }
};