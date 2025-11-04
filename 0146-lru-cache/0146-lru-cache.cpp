class LRUCache {
    //setting the struct for linked list
    struct ListNode{
        int key;
        int value;
        ListNode* prev;
        ListNode* next;

        ListNode(int k, int v)
        {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    //defining variables, nodes, and map
    unordered_map <int, ListNode*> LRU;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
          //if key not found, return -1
        if(!LRU.count(key))
        {
            return -1;
        }
        //initializing current node
        ListNode* node = LRU[key];
        //if node is already at tail, just return value
        if(node==tail)
        {
            return node->value;
        }
        //removing node from current position
        //if node is not head
        if(node->prev!=nullptr)
        {
            node->prev->next = node->next;
        }
        //if node is head
        else
        {
            head = node->next;
        }
        //if node is not tail
        if(node->next!=nullptr)
        {
            node->next->prev = node->prev;
        }
        //adding node to end
        node->prev = tail;
        node->next = nullptr;
        //if list is not empty
        if(tail!=nullptr)
        {
            tail->next = node;
        }
        tail = node;
        //if list is empty
        if(head == nullptr)
        {
            head = node;
        }
        return node->value;
    }
    
    void put(int key, int value) {
        //if key exists, update value and call get() to reposition node
        if(LRU.count(key))
        {
            LRU[key]->value = value;
            get(key);
        }
        //if key doesn't exist, create new node at the end of list and add to map
        else
        {
            ListNode* temp = new ListNode(key, value);
            LRU[key] = temp;
            //if list is empty, set head and tail as new node
            if(tail==nullptr)
            {
                head = temp;
                tail = temp;
            }
            //if list is non empty, add node to end
            else
            {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            }
        }
        //if capacity exceeds, erase key from map, remove head node
        if(LRU.size()>cap)
        {
            LRU.erase(head->key);
            head = head->next;
            if(head)
            {
            head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */