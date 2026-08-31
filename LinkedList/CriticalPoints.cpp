// Problem: Find the minimum and maximum number of nodes between critical points
// Difficulty: Medium
//platform: Leetcode
// Approach: Traverse and save the indices
// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 1;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        vector<int> indices;

        while (curr->next) {

            if (prev) {
                if (curr->val > prev->val && curr->val > curr->next->val) {
                    indices.push_back(i);
                }
                if (curr->val < prev->val && curr->val < curr->next->val) {
                    indices.push_back(i);
                }
            }

            prev = curr;
            curr = curr->next;
            i++;
        }
        if (i <= 2 || indices.size()==0) {
            return {-1, -1};
        }

        int mini = INT_MAX;
        int maxi = indices.back()==indices[0] ? -1 : indices.back()-indices[0];
        for(int i=0;i<indices.size()-1;i++){
            mini = min(mini,indices[i+1]-indices[i]);
        }

        mini = mini==INT_MAX ? -1 : mini;


        return {mini,maxi};
    }
};