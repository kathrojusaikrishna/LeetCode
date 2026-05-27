// Problem: Building BST from sorted array
// Difficulty: Medium
// Approach: Recursion
// Time: O(n)
// Space: O(1)

class Solution {
  public:
  
    Node* build(vector<int>& arr, int left, int right){
        
        int mid  = left + (right-left)/2;
        
        if(left > right)return nullptr;
        
        Node* root = new Node(arr[mid]);
        root->left = build(arr,left,mid-1);
        root->right = build(arr,mid+1,right);
        
        return root;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        

        Node* root = build(arr,0,arr.size()-1);
        
        return root;
    }
};