// Problem: GCD of odd and even sum
// Difficulty: Easy
// Approach: Simple iteration and GCD calculation
// Time: O(log(min(oddSum,evenSum)))
// Space: O(1)

class Solution {
public:
    int gcd(int a, int b){
        while( a>0 && b>0){
            if(a > b)a = a%b;
            else b= b%a;
        }

        if(a==0)return b;
        return a;
    }
    int gcdOfOddEvenSums(int n) {

        int oddSum = n*n;
        int evenSum = n*(n+1);

        return gcd(oddSum,evenSum);
    }
};