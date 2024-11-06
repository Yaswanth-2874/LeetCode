/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //Follow up
    //Since all elements are positive, i will make them negative in the first traversal
    //When i traverse the second linkedlist, i try to find a negative and return the first negative
    void changeAllSigns(ListNode* head) {
        ListNode *curr = head;
        while(curr) {
            curr->val *= -1;
            curr = curr->next;
        }
    }    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        changeAllSigns(headA);
        ListNode* requiredNode = NULL;
        ListNode* curr = headB;
        
        while(curr) {
            if(curr->val < 0) {
                requiredNode = curr;
                break;
            }
            curr = curr->next;
        }
        
        changeAllSigns(headA);
    
        return requiredNode;
    }
};