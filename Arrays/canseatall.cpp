// Problem: Seating Arrangement
// Difficulty: Easy
// Approach: simple iteration
//platform: Geeksforgeeks
// Time: O(n)
// Space: O(1)

class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        
        int n = seats.size();
        
        for(int i=0;i<n && k>0;i++){
            
            if(seats[i]==1)continue;
            
            bool left = (i==0 || seats[i-1]==0);
            bool right = (i==n-1 || seats[i+1]==0);
            
            if(left && right){
                seats[i]=1;
                k--;
            }
        }
        
        return k<=0;
    }
};