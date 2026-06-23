// Problem: Maximum area between the bars
// Difficulty: Medium
// Platform: Geeksforgeks
// Approach: two-pointers
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        
        int n = height.size();
        int left=0;
        int right=n-1;

        int ans=INT_MIN;
        
        while(left < right){
            int area = min(height[left],height[right])*(right-left-1);
            ans = max(ans,area);
            if(height[left]<= height[right]){
                left++;
            }else{
                right--;
            }
        }
        
        return ans;
        
    }
};