// Problem: Delete nodes which are greater on right
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: reverse list, find, reverse
// Time: O(n)
// Space: O(1)

class Solution {
  public:
  
    Node* reverse(Node* head){
        
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr){
            Node* next = curr->next;
            
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    Node *compute(Node *head) {
        // code here
        
        if(!head || !head->next)return head;
        
        head = reverse(head);
        
        int mx = head->data;
        Node* curr = head;
        
        while(curr && curr->next){
            
            if(curr->next->data < mx){
                curr->next = curr->next->next;
            }else{
                curr=curr->next;
                mx = max(mx,curr->data);
            }
        }
        

        
        return reverse(head);
    }
};