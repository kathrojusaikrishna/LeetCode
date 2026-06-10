// problem : Binary searchable
// Level : Medium
//platform: Geeksforgeeks
// Time complexity : O(n)
// space complexity : O(1)


class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        // code here
        int n = arr.size();
        int counter=0;
        
        for(int i=0;i<n;i++){
            
            int low = 0;
            int high = n-1;
            
            while(low<= high){
                int mid = low+(high-low)/2;
                
                if(arr[mid]==arr[i]){
                    counter++;
                    break;
                }
                else if(arr[mid] < arr[i]){
                    low = mid+1;
                }else{
                    high= mid-1;
                }
            }
        }
        
        return counter;
        
    }
};