/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return nullptr;
        }
        unordered_map<Node*, Node*> copy;
        Node* curr = head;
        Node* newHead = new Node(curr->val);
        Node* newCurr = newHead;
        copy[head] = newHead;
        curr = curr->next;
        while(curr!=nullptr)
        {
            Node* newNode = new Node(curr->val);
            newCurr->next = newNode;
            copy[curr] = newNode;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        curr = head;
        newCurr = newHead;
        while(curr!=nullptr)
        {
            if(curr->random!=nullptr)
            {
            newCurr->random = copy[curr->random];
            }
            else
            {
                newCurr->random = nullptr;
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};