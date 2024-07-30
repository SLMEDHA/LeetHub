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
    ListNode* oddEvenList(ListNode* head) {
      if (!head || !head->next) return head; // Return if the list is empty or has only one element

        ListNode *odd = head; // First node (odd)
        ListNode *even = head->next; // Second node (even)
        ListNode *evenHead = even; // Head of the even indexed list

        while (even && even->next) {
            odd->next = even->next; // Connect odd nodes
            odd = odd->next; // Move to the next odd node
            even->next = odd->next; // Connect even nodes
            even = even->next; // Move to the next even node
        }

        odd->next = evenHead; // Connect the last odd node to the head of even list
        return head; // Return the reordered list
    }
};