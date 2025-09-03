class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       /* if (!head) return nullptr;

        // Step 1: Find the length of the list
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Step 2: If we need to remove the head node
        if (n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Traverse to the node before the one to remove
        int steps = length - n;
        temp = head;
        ListNode* prev = nullptr;
        while (steps--) {
            prev = temp;
            temp = temp->next;
        }

        // Step 4: Remove the node
        prev->next = temp->next;
        delete temp;
        return head;
   */ 
   //1 pass approach
     ListNode* temp = head;
     for(int i=1;i<=n;i++){
        temp=temp->next;
     }

     if(temp==NULL){
        ListNode* result= head->next;
        delete(head);
        return result;
     }

     ListNode* prev= head;
     while(temp != NULL && temp->next!= NULL){
        prev=prev->next;
        temp=temp->next;
     }
     prev->next= prev->next->next;
     return head;
   
   
   
   
   
   
    }
};
