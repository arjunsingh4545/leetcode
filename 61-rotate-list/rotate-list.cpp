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
    ListNode* rotateRight(ListNode* head, int k) {
       if (!head || !head->next || k == 0) {
            return head; // Edge cases
        }
        // Step 1: Calculate the length of the list
        ListNode* current = head;
        int length = 1; // Start with 1 to count the head
        while (current->next) {
            current = current->next;
            length++;
        }
        // Step 2: Connect the tail to the head to make it circular
        current->next = head;
        // Step 3: Calculate the effective rotations
        k = k % length;
        if (k == 0) {
            current->next = nullptr; // Break the circular link
            return head; // No rotation needed
        }
        // Step 4: Find the new tail
        int newTailPosition = length - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < newTailPosition; i++) {
            newTail = newTail->next;
        }
        // Step 5: Set the new head and break the link
        ListNode* newHead = newTail->next;
        newTail->next = nullptr; // Break the circular link
        return newHead;
    }
};