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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* temp = head;
        while(head && head->next) {
            ListNode* nextNode = head->next;
            int gcd = __gcd(head->val, nextNode->val);
            head->next = new ListNode(gcd, nextNode);
            head = nextNode;
        }
        
        return temp;
    }
};