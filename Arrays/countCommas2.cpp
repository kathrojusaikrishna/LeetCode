// Problem: Count commas II
// Difficulty: Medium
// Platform: Leetcode
// Approach: iterate the 1000, add commas and increment by mult 1000 to start
// Time: O(logn)
// Space: O(1)

class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;

        long long start=1000;
        int commas=1;
        long long ans=0;

        while(start <= n){

            long long end;

            if(start > n/1000){
                end = n;
            }else{
                end = min(n,start*1000-1);
            }

            ans += (end-start+1)*commas;

            if(start > n/1000)break;
            start *= 1000;
            commas++;
        }
        return ans;

    }
};