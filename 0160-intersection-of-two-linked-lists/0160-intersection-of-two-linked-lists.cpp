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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> locations;
        ListNode *curr = headA;
        while(curr) {
            locations.insert(curr);
            curr = curr->next;
        }
        curr = headB;
        while(curr) {
            if(locations.find(curr) != locations.end())
                return curr;
            curr = curr->next;
        }
        return NULL;
    }
};