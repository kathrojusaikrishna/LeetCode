// Problem: Remove duplicates from an unsorted linked list
// Difficulty: Medium
//platform: takeUfarword
// Approach: haspmap
// Time: O(n)
// Space: O(n)

class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        // Your code goes here

        ListNode* temp = head;
        ListNode* ans=nullptr;
        ListNode* tail = nullptr;

        unordered_map<int,int>mp;

        while(temp){
            mp[temp->val]++;
            temp = temp->next;
        }

        temp = head;

        while(temp){

            if(mp[temp->val]==1){
                            if(!ans){
                ans = temp;
                tail =temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
            }

            temp = temp->next;
        }

        if(tail){
            tail->next = nullptr;
        }

        return ans;


    }
};