// Problem: Seperate the digits in array
// Difficulty: Easy
// Approach: simple iteration, reverse the number
// Time: O(n * log(max(nums)))
// Space: O(n) - for result

class Solution {
public:

    void reverse(int left, int right, vector<int>& result){

        while(left<right){
            swap(result[left],result[right]);
            left++;
            right--;
        }
    }

    void addToResult(int revNum, vector<int>& result){

        while(revNum){
            int digit = revNum%10;
            result.push_back(digit);
            revNum /= 10;
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>result;
        for(int i=0;i<n;i++){
            int left = result.size();
            addToResult(nums[i], result);
            int right = result.size()-1;
            reverse(left, right, result);
        }

        return result;
    }
};