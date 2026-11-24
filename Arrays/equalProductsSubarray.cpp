// Problem: Maximum subarray with equal products
// Difficulty: Easy
// Platform : Leetcode
// Approach: brute force - check for unsigned long long for the product calculation
// Time: O(n*n*logM)
// Space: O(1)

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unsigned long long product = 1;
            __int128 g = nums[i];
            __int128 l = nums[i];

            for (int j = i; j < n; j++) {
                product *= nums[j];

                g = gcd((long long)g, nums[j]);

                l = (l / gcd((long long)l, nums[j])) * nums[j];

                if (product == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};