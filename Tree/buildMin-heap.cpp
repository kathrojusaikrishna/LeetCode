// Problem: Build min heap
// Difficulty: Medium
//platform: takeUfarword
// Approach: using recursion
// Time: O(n)
// Space: O(1)

class Solution {
public:

    void heapify(vector<int> &nums, int i, int n){
        int smallest =i;
        int left = i*2+1;
        int right = i*2+2;

        if(left<n && nums[left]<nums[smallest]){
            smallest = left;
        }

        if(right < n && nums[right]<nums[smallest]){
            smallest = right;
        }

        if(smallest != i){
            int temp = nums[smallest];
            nums[smallest] = nums[i];
            nums[i]=temp;
            heapify(nums,smallest,n);
        }
    }

    void buildMinHeap(vector<int> &nums) {
        
        int n = nums.size();

        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }
    }
};