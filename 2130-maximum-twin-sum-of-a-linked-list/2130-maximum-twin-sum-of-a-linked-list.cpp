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
    int pairSum(ListNode* head) 
    {
    ListNode*slow=head,*fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode*present=slow->next,*future;
    while(future)
    {
        future=present->next;
        present->next=slow;
        slow=present;
        if(future==NULL)
            break;
        present=future;
    }
    int ans=0;
    while(1)
    {
        ans=max(ans,head->val+present->val);
        head=head->next;
        if(head==present)
            return ans;
        present=present->next;
    }
    return ans;
    }
};