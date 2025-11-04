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
    ListNode* reverseList(ListNode* head) {
         if(head==nullptr)
        {
            return nullptr;
        }
        ListNode* after;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr!=nullptr)
        {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        head->next = nullptr;
        return prev;
    }
};