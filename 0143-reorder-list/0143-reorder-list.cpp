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
    void reorderList(ListNode* head) {
     if (!head || !head->next) return;  // If the list is empty or has only one node, do nothing
        
        // Step 1: Find the middle of the list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = prev;  // 'prev' is now the head of the reversed second half
        
        while (second->next) {
            temp = first->next;
            first->next = second;
            first = temp;
            
            temp = second->next;
            second->next = first;
            second = temp;
        }
    }
};