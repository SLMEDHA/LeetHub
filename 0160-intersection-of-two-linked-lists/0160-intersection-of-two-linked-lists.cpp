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
    if (!headA || !headB) return NULL;

        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while (p1 != p2) {
            // If p1 reaches the end of listA, start at headB; otherwise, move to next node
            if (p1 == NULL) {
                p1 = headB;
            } else {
                p1 = p1->next;
            }
            if (p2 == NULL) {
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }
        return p1; // intersection node or NULL
    }
};