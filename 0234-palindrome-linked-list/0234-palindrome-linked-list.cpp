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
    ListNode* reverseLinkedList(ListNode *head) {
        ListNode *temp = head, *nxt = head->next, *prev = NULL;
        while(temp) {
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *hare = head, *turtle = head;
        while(hare && hare->next) {
            hare = hare->next->next;
            turtle = turtle->next;
        }
        ListNode *reverseHead = reverseLinkedList(turtle);
        while(head && reverseHead) {
            if(head->val != reverseHead->val)
                return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
};