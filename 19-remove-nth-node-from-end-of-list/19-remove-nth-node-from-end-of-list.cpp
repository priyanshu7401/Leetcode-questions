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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
     ListNode*temp=head,*ptr=NULL;
     int count=0;    
     while(temp->next!=NULL)
     {
         temp=temp->next;
         count++;
         if(count==n)ptr=head;
         if(count>n)ptr=ptr->next;
             
     }
     if(ptr==NULL)
         return head->next;
     else if(ptr->next)
     {
         
         temp=ptr->next;
         ptr->next=temp->next;
         delete temp;
     }
         return head;
    }
};