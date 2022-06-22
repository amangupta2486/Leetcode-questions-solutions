/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt;
        
        while(curr)
        {
            nxt = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL)
        {
            return 1;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
       fast=reverse(slow->next);
       slow=head;
        
        while(slow && fast)
        {
            if(slow->val!=fast->val)
            {
                return 0;
            }
            
            slow=slow->next;
            fast=fast->next;
        }
        
        return 1;
    }
};