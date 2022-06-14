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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* newNode=NULL;
        
        while(head!=NULL)
        {
            ListNode* nxt=head->next;
            head->next=newNode;
            newNode=head;
            head=nxt;
        }
        
        return newNode;
    }
};