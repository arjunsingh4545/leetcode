/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     unsigned int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(unsigned int x) : val(x), next(nullptr) {}
 *     ListNode(unsigned int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    unsigned int listToDec2(ListNode* head) {
       ListNode* temp = head;
        stack<ListNode*> s;
        while(temp != nullptr) {
            s.push(temp);
            temp = temp->next;
        }
        unsigned int num =  0;
        while(!s.empty()) {
            num = num * 10 + s.top()->val;
            s.pop();
        }
        return num;
    }

    ListNode* DecToList(unsigned int num) {
        ListNode* head = new ListNode(num % 10);
        num /= 10;
        ListNode* temp = head;
        while(num) {
            temp->next = new ListNode(num % 10);
            num /= 10;
            temp = temp->next;
        }
        return head;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        
        ListNode* curr = dummy;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        
        if (carry == 1) {
            curr->next = new ListNode(1);
        }
        
        return dummy->next;
    }
};

