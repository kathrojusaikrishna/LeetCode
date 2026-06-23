// problem : Max people defeated
// Level : Medium
//platform: Geeksforgeeks
// Time complexity : O(logn)
// space complexity : O(1)

class Solution {
  public:
  
    long long solve(int n){
        return (n*(n+1)*(2*n+1))/6;
    }
    int maxPeopleDefeated(int p) {
        // Code Here
        
        long long low=1;
        long long high=1000;
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            
            if(solve(mid)<=p){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        return (int)high;
    }
};
