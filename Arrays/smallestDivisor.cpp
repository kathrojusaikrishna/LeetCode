// Problem: Smallest divisible digit product I 
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(answer - n+1 * log(n))
// Space: O(1)

class Solution {
public:
    long long solve(int n ){
        long long ans=1;
        while(n>0){
            int digit = n%10;
            ans *=digit;
            n /=10;
        }

        return ans;
    }
    int smallestNumber(int n, int t) {
        
        int ans=-1;
        while(true){
            if(solve(n)%t==0){
                ans=n;
                break;
            }
            n++;
        }

        return ans;
    }
};