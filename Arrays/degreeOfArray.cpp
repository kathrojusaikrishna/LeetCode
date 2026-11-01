// Problem: Degree of an array
// Difficulty: Easy
// Platform : Leetcode
// Approach: hashing
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int,int> freq;
        unordered_map<int,int> first;
        unordered_map<int,int> last;

        int degree = 0;

        for(int i = 0; i < nums.size(); i++) {

            int x = nums[i];

            freq[x]++;

            if(first.find(x) == first.end()) {
                first[x] = i;
            }

            last[x] = i;

            degree = max(degree, freq[x]);
        }

        int ans = nums.size();

        for(auto& [x, f] : freq) {

            if(f == degree) {

                int len = last[x] - first[x] + 1;

                ans = min(ans, len);
            }
        }

        return ans;
    }
};