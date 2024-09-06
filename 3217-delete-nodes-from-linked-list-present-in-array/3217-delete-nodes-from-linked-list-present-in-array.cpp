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
    unordered_set<int> numbersToBeDeleted;
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        for(int num : nums)
            numbersToBeDeleted.insert(num);
        ListNode *dummy = new ListNode(), *dummyHead = dummy;
        
        while(head) {
            while(head && numbersToBeDeleted.find(head->val) != numbersToBeDeleted.end()) {
                head = head->next;
            }
            dummy->next = head;
            dummy = dummy->next;
            if(head)
                head = head->next;
        }
        return dummyHead->next;
    }
};