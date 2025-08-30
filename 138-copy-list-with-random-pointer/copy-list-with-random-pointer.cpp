class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        if (head == NULL)
            return NULL;  // Added return NULL here for empty list case
        
        Node* curr = head;   // Move this declaration outside of if
        Node* prev = NULL;
        Node* newHead = NULL;

        while (curr) {
            Node *temp = new Node(curr->val);
            mp[curr] = temp;
            if (newHead == NULL) {
                newHead = temp;
                prev = newHead;
            }
            else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;  // Use 'curr', not 'current'
        }

        curr = head;
        Node* newCurr = newHead;
        while (curr) {
            if (curr->random == NULL) {
                newCurr->random = NULL;
            }
            else {
                newCurr->random = mp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
