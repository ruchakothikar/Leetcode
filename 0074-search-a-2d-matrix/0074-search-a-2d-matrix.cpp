class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int lower = 0, upper = (matrix.size() * matrix[0].size()) -1;
        int r, c;
        int mid;
        while(lower<=upper)
        {
            mid = (upper+lower)/2;
            r = mid / matrix[0].size();
            c = mid % matrix[0].size();
            if(matrix[r][c]==target)
            {
                return true;
            }
            else if(matrix[r][c]<target)
            {
                lower = mid+1;
            }
            else
            {
                upper = mid-1;
            }
        }
        return false;
    }
};