// Problem: Concatinate non zero digits and multiply by sum 1
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple computaion
// Time: O(n)

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        long long sum=0;

        string temp = to_string(n);
        for(auto ch : temp){
            if(ch-'0' !=0){
                sum += (long long)ch-'0';
                ans = (ans *10)+(long long)ch-'0';
            }
        }

        return ans*sum ;


    }
};