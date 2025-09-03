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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr= head;

        ListNode* small= new ListNode(0);
         ListNode* smallptr= small;

        ListNode* large= new ListNode(-1);
        ListNode* largeptr=large;
                while(curr!= NULL){
            if(curr->val<x){
                smallptr->next=curr;
                smallptr=smallptr->next;
            }
            else{
            largeptr->next=curr;
            largeptr=largeptr->next;
            }
            curr=curr->next;

        }
        smallptr->next=large->next;
        largeptr->next=NULL;
        return small->next;

        
    }
};