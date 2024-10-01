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
    ListNode* reverseList(ListNode* head) {
        ListNode* traversalPointer = head, *prevNode = NULL;
        if(!head || !head->next)
            return head;
        
        while(traversalPointer->next) {
            ListNode* nextNode = traversalPointer->next;
            traversalPointer->next = prevNode;
            prevNode = traversalPointer;
            traversalPointer = nextNode;
        }
        traversalPointer->next = prevNode;
        
        return traversalPointer;
    }
};