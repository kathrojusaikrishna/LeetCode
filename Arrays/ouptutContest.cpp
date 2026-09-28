// Problem: Output contest matches
// Difficulty: Medium
// Platform: takeUfarword
// Approach: iteration
// Time: O(nlogn)
// Space: O(n)

class Solution {
public:
    string findContestMatch(int n) {
        // Your code goes here

        vector<string>team;

        for(int i=1;i<=n;++i){
            team.push_back(to_string(i));
        }

        while(team.size()>1){
            vector<string>nextRound;
            int m = team.size();

            for(int i=0;i<m/2;++i){
                nextRound.push_back(
                    "(" + team[i]+","+team[m-i-1]+")"
                );
            }

            team = nextRound;
        }

        return team[0];
    }
};