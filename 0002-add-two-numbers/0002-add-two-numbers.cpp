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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0, sum = 0, n1, n2;
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        while(l1!=nullptr || l2!=nullptr || carry!=0)
        {
            if(l1==nullptr)
            {
                n1 = 0;
            }
            else
            {
                n1 = l1->val;
            }
            if(l2==nullptr)
            {
                n2 = 0;
            }
            else
            {
                n2 = l2->val;
            }
            sum = n1 + n2 + carry;
            carry = sum/10;
            if(l1!=nullptr)
            {
            l1 = l1->next;
            }
            if(l2!=nullptr)
            {
            l2 = l2->next;
            }
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }
        return ans->next;
    }
};