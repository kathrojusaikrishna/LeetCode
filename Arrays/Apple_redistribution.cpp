// Problem: Apple Redistribution into boxes
// Difficulty: Easy
// Approach: simple iteration & sorting
// Time: O(nlogn)
// Space: O(1)


class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int totalApples =0;
        int ans =0;

        for(int i=0;i<apple.size();i++){
            totalApples += apple[i];
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        for(int i=0;i<capacity.size();i++){

            if(totalApples > 0){
                totalApples -= capacity[i];
                ans+=1;
            }
        }

        return ans;
        
    }
};