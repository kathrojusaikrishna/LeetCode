// Problem: elevator requests I
// Difficulty: Easy
// Platform : Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int present=0;
        int ans=0;

        for(int i=0;i<requests.size();i++){
            if(present != requests[i]){
                ans += abs(present-requests[i]);
                present = requests[i];
            }
        }

        return ans;
    }
};