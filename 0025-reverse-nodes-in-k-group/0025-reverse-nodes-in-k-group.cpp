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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        ListNode* groupHead = head;
        //outer loop
        while(true)
        {
            ListNode* check = groupHead;
            //inner loop to count k nodes
            for(int i=0; i<k; i++)
            {
                if (!check) return dummy.next;
                check = check->next;
            }
            //reverse
            ListNode* prev = nullptr;
            ListNode* curr = groupHead;
            for (int i = 0; i < k; i++)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            prevGroupTail->next = prev;   //new head of group
            groupHead->next = curr;       //tail points to next group

            //move pointers forward
            prevGroupTail = groupHead;
            groupHead = curr;

        }
    }
};