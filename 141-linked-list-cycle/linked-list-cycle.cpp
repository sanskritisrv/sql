class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // base case

        ListNode *slowptr = head;
        ListNode *fastptr = head;

        while (fastptr && fastptr->next) {
            slowptr = slowptr->next;           // 1 step
            fastptr = fastptr->next->next;     // 2 steps

            if (slowptr == fastptr) return true; // cycle found
        }

        return false; // no cycle
    }
};
