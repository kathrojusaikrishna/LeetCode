// Problem: Count odd numbers in a range
// Difficulty: Easy
// Approach: if-else
// Time: O(1)
// Space: O(1)

class Solution {
public:
    int countOdds(int low, int high) {

        if(low %2 ==0){
            if(high%2 ==0){
                return (high - low)/2;
            }
            else{
                return (high - low +1)/2;
            }

        }else{
            if(high %2 ==0){
                return (high - low +1)/2;
            }
            else{
                return (high - low )/2 +1;
            }
        }


        // 7 - 3 = 4 elements => 4/2 = 3 (odds)
        // 6 - 3 = 4 elements => 4/2 (2 odds)


        //7 - 4 = 3+1/2 = 2
        //8 - 4 = 4/2 =2 
        
    }
};