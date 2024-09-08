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
    int findSize(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        
        while(temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = findSize(head);
        int segmentSize = size/k;
        int remainingSize = size % k;
        
        int current = 0;
        vector<ListNode*> splitLists;
        
        while(k--) {
            ListNode* tempHead = head;
            int iterations = segmentSize + (remainingSize-- >= 1);
            while(head && iterations-- > 1)
                 head = head->next;
            if(head) {
                ListNode *nxt = head->next;
                head->next = NULL;
                head = nxt;
            }
            splitLists.push_back(tempHead);
        }
        return splitLists;
    }
};