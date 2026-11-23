// Problem: Product of k last numbers
// Difficulty: Medium
//platform: Leetcode
// Approach: prefix product
// Time: O(1)
// Space: O(1) 

class ProductOfNumbers {
public:
    vector<int>nums;
    int size=0;
    ProductOfNumbers() {
        nums.push_back(1);
        size=0;
    }
    
    void add(int num) {
        if(num==0){
            nums = {1};
            size=0;
        }else{
            nums.push_back(nums[size]*num);
            size++;
        }
    }
    
    int getProduct(int k) {

        if(k > size)return 0;
        return nums[size]/nums[size-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */