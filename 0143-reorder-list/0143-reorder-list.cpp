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
        //using slow and fast pointer to find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //setting up pointers to reverse second half of list
        ListNode* newhead = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = newhead;
        ListNode* temp = newhead;
        //reversing second half of list
        while(curr!=nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        newhead = prev;
        curr = newhead;
        //reordering nodes
        ListNode* curr1 = head;
        ListNode* temp2;
        while(curr!=nullptr)
        {
            temp = curr1->next;
            temp2 = curr->next;
            curr1->next = curr;
            curr->next = temp;
            curr1 = temp;
            curr = temp2;
        }
    }
};