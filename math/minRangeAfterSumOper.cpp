// Problem: Minimum range after sum operations
// Difficulty: Medium
// Platform: Leetcode
// Approach: math + sort
// Time: O(n(nlogn))
// Space: O(1) 

class Solution {
public:
    int minRange(int a, int b, int c) {

        vector<int>arr = {a,b,c};

        sort(arr.begin(),arr.end());


        while(arr[2] > (arr[0] + arr[1])){
            arr[2] = arr[0] + arr[1];
            sort(arr.begin(),arr.end());
        }

        sort(arr.begin(),arr.end());

        return arr[2] - arr[0];
    }
};