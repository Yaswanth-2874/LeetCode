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
        ListNode* mergedNode = new ListNode(0);
        ListNode* storedNode = mergedNode;
        int currentSum = 0;
        head = head->next;
        
        while(head) {
            if(head->val) {
                currentSum += head->val;
            }
            else {
                mergedNode->next = new ListNode(currentSum);
                currentSum = 0;
                mergedNode = mergedNode->next;
            }
            head = head->next;
        }
        return storedNode->next;
    }
};

