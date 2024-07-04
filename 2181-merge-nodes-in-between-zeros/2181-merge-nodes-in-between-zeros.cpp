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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* index = head, *traversal = head->next;
        int currentSum = 0;
        
        while(traversal) {
            if(traversal -> val) {
                currentSum += traversal->val;
            }
            else {
                index->val = currentSum;
                currentSum = 0;
                if(!traversal->next)
                    index->next = NULL;
                index = index->next;
            }
            traversal = traversal->next;
        }
        return head;
    }
};