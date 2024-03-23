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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head1 = list1, *head2 = list2, *del;
        b -= a-1;
        
        while(a-- > 1) {
            list1 = list1->next;
        }
        del = list1->next;
        list1->next = list2;
        while(list2->next){
            list2 = list2->next;
        }
        while(b--) {
            del = del->next;
        }
        list2->next = del;
        
        return head1;
        
    }
};