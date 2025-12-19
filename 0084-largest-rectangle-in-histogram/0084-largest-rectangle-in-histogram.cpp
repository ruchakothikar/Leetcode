class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack<int> indices;
        int area;
        int maxarea=0;
        int height, width;
        for(int i=0; i<heights.size(); i++)
        {
            while(!indices.empty() && heights[i]<heights[indices.top()])
            {
                height = heights[indices.top()];
                indices.pop();
                if(indices.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - indices.top() - 1;
                }
                area = height*width;
                maxarea = max(maxarea, area);
            }
            indices.push(i);
        }
        while(!indices.empty())
        {
            height = heights[indices.top()];
            indices.pop();
            if(indices.empty())
            {
                width = heights.size();
            }
            else
            {
                width = heights.size() - indices.top() - 1;
            }
            area = height*width;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};