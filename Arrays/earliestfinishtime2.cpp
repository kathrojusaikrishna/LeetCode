// Problem: Find the earliest finish time 2
// Difficulty: Medium
// Platform : Leetcode
// Approach: simple iteration
// Time: O(n+m)
// Space: O(1)

class Solution {
public:

    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2, vector<int>& duration2){

        int finish1 = INT_MAX;
        for(int i=0;i<start1.size();i++){
            finish1 = min(finish1, start1[i]+duration1[i]);
        }

        int finish2 = INT_MAX;
        for(int i=0;i<start2.size();i++){
            finish2 = min(finish2, max(finish1,start2[i])+ duration2[i]);
        }

        return finish2;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        

        int land_water = solve(landStartTime,landDuration,waterStartTime,waterDuration);

        int water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(land_water, water_land);
    }
};