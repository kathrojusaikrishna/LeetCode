// Problem: Merge two paths
// Difficulty: Easy
// Platform: Geeksforgeeks
// Approach: two pointers
// Time: O(n)
// Space: O(n) 

class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        int n = arr.size();
        int left=0;
        int b=-1;
        vector<int>temp;
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                b=i-1;
                break;
            }
        }
        if(b==-1)return;
        int right = b+1;
        
        while( left<=b && right<n){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=b){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<n){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
    }
};