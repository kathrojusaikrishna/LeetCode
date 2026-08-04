// Problem: Count pairs
// Difficulty: Easy
// Approach: sort + two pointers
// Time: O(nlogn)
// Space: O(1)

class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans=0;
        
        int left=0;
        
        for(int right=0;right<n;right++){
            
            while(arr[right]-arr[left] >=k)left++;
            
            ans += right-left;
        }
        
        return ans;
    }
};