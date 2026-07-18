// Problem: Greatest common divisor of an array
// Difficulty: Easy
// Approach: simple iteration and finding gcd
// Time: O(n)
// Space: O(1)

class Solution {
public:

    int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b)a= a%b;
            else b=b%a;
        }

        if(a>0)return a;
        else return b;
    }
    int findGCD(vector<int>& nums) {
        
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        return gcd(maxi,mini);
    }
};