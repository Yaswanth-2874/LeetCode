/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool cycleExists = false;
        if(!head || !head->next)
            return false;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast && slow != fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                return false;
            fast = fast->next;
        }
        
        return slow == fast;
        
    }
};