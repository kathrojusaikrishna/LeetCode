// Problem: Majority Element 2
// Difficulty: Medium
// Approach: iteration
// Time: O(n)
// Space: O(n) - for returning solution

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int counter1=0;
        int counter2=0;
        int element1=INT_MIN;
        int element2 = INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(counter1 ==0 && element2 != nums[i]){
                counter1 =1;
                element1 = nums[i];
            }
            else if(counter2 ==0 && element1 != nums[i]){
                counter2 =1;
                element2 = nums[i];
            }
            else if(nums[i]==element1){
                counter1++;
            }
            else if(nums[i]==element2){
                counter2++;
            }
            else{
                counter1--;
                counter2--;
            }
        }

        counter1 =0,
        counter2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==element1){
                counter1++;
            }
            if(nums[i]==element2){
                counter2++;
            }
        }
        vector<int>ans;

        if(counter1 > nums.size()/3)ans.push_back(element1);
        if(counter2 > nums.size()/3 && element2 != element1)ans.push_back(element2);

        return ans;
        
    }
};