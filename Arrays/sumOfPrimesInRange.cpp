// Problem: Sum of primes in range
// Difficulty: Medium
// Approach: simple iteration
// Time: O(max-min * sqrt(n))
// Space: O(1)

class Solution {
public:
    
    bool isPrime(int num){
        if(num <=1)return false;
        for(int i=2; i*i<=num;i++){
            if(num%i==0)return false;
        }

        return true;
    }

    int reverse(int num){
        int ans=0;

        while(num){
            int digit = num%10;

            ans = ans*10+digit;

            num /=10;
        }

        return ans;
    }
    int sumOfPrimesInRange(int n) {

        int sum=0;
        int rev = reverse(n);
        int start = min(n,rev);
        int end = max(n,rev);
        for(int i=start;i<=end;i++){
            if(isPrime(i))sum +=i;
        }

        return sum;
    }
};