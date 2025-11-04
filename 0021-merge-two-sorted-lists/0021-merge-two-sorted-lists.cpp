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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* i;
        ListNode* j;
        ListNode* newhead;
        ListNode* prev;
        i = list1;
        j = list2;
        //edge cases if one or both lists are empty
        if(list1==nullptr && list2==nullptr)
        {
            return nullptr;
        }
        else if(list1==nullptr && list2!=nullptr)
        {
            return list2;
        }
        else if(list2==nullptr && list1!=nullptr)
        {
            return list1;
        }
        //assigning new head
        if(i->val <= j->val)
        {
            newhead = i;
            i = i->next;
        }
        else
        {
            newhead = j;
            j = j->next;
        }
        prev = newhead;
        //loop to rearrange both lists into one
        while(i!=nullptr && j!=nullptr)
        {
            if(i->val <= j->val)
            {
                prev->next = i;
                i = i->next;
                prev = prev->next;
            }
            else if(i->val > j->val)
            {
                prev->next = j;
                j = j->next;
                prev = prev->next;
            }
        }
        //if i ends and j doesn't
        if(i==nullptr && j!=nullptr)
        {
            prev->next = j;
        }
        else if(i!=nullptr && j==nullptr)
        {
            prev->next = i;
        }
        return newhead;
    }
};