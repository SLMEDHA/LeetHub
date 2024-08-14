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
    void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
            return; // Edge case: the node is null or it is the last node, which should not happen according to the problem.
        }
        
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        
        // Skip over the next node by changing the next pointer
        ListNode* temp = node->next;
        node->next = node->next->next;
        
        // Optionally, delete the skipped node if you want to clean up memory
        delete temp;
    }
};