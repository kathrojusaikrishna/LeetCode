// Problem: Majority Element 1
// Difficulty: Easy
// Approach: Simple Iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter =0;
        int element;
        int final_counter=0;

        for(int i=0;i<nums.size();i++){
            if(counter==0){
                counter=1;
                element = nums[i];
            }
            else if(nums[i] == element){
                counter++;
            }
            else{
                counter--;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==element){
                final_counter++;
            }
        }

        if(final_counter > nums.size()/2){
            return element;
        }

        return -1;
    }
};