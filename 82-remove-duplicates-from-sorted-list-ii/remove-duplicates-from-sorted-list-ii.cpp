class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* temp = head;

        while (temp != NULL) {
            // If current node is the start of duplicates
            if (temp->next != NULL && temp->val == temp->next->val) {
                // Skip all nodes with same value
                while (temp->next != NULL && temp->val == temp->next->val) {
                    temp = temp->next;
                }
                // Connect prev->next to the node after duplicates
                prev->next = temp->next;
            } else {
                // No duplicate, just move prev
                prev = prev->next;
            }
            temp = temp->next;
        }

        ListNode* result = dummy->next;
        delete dummy; // Free dummy node
        return result;
    }
};
