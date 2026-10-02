// Problem: Shortest subarray with sum atleast k
// Difficulty: Hard
// Platform: Leetcode
// Approach: we know how to find when sum is exaclty k uisng prefix+map, here we need to maintain deque
// Time: O(n)
// Space: O(n) 


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int>dq;
        vector<int>prefix(n+1);
        int ans = n+1;

        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        for(int i=0;i<=n;i++){

            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                ans = min(ans, i-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefix[dq.back()] >= prefix[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        if(ans==n+1)return -1;

        return ans;
    }
};