class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> boxes[9];
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.') //skipping blank spaces
                {
                    continue;
                }
                //checking row
                if(row[i].count(board[i][j]))
                {
                    return false;
                }
                row[i].insert(board[i][j]);
                //checking column
                if(col[j].count(board[i][j]))
                {
                    return false;
                }
                col[j].insert(board[i][j]);
                //checking box
                int boxin= (i/3)*3 + (j/3);
                if(boxes[boxin].count(board[i][j]))
                {
                    return false;
                }
                boxes[boxin].insert(board[i][j]);
            }
        }
        return true;
    }
};