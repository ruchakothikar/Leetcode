class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        //putting stones in heap
        for(int i=0; i<stones.size();i++)
        {
            maxHeap.push(stones[i]);
        }
        //comparing stones
        while(maxHeap.size()!=1 && !maxHeap.empty())
        {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if(x!=y)
            {
                maxHeap.push(x-y);
            }
        }
        //returning last stone or empty
        if(maxHeap.empty())
        {
            return 0;
        }
        return maxHeap.top();
    }
};