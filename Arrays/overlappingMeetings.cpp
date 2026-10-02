// Problem: Overlapping meetings
// Difficulty: Easy
// Platform: takeUfarword
// Approach: sort and check
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // Your code goes here

        sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < intervals[i-1][1])return false;
        }

        return true;
    }
};