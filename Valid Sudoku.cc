class Solution {

    bool hasRepitionInRow(vector<vector<char>>& board, int r) {
        int mask  = 0;
        for(char ch : board[r]) {
            if (ch == '.')
            continue;
            int dig = ch - '0';
            if (mask & (1<<dig))
                return true;
             mask |= (1<<dig);      
        } 
        return false;
    }

    bool hasRepitionInCol(vector<vector<char>>& board, int c) {
          int mask  = 0;
        for( int i =0; i< board.size();i++) {
            char ch = board[i][c];
            if (ch == '.')
                continue;
            int dig = ch - '0';
            if (mask & (1<<dig))
                return true;
             mask |= (1<<dig); 
        }

        return false;
    }

    bool hasRepitionInSubBox(vector<vector<char>>& board, int r, int c) {
         int mask  = 0;
        for( int i =r; i< r+3;i++) {
            for(int j = c; j< c+3; j++) {
                char ch = board[i][j];
                if (ch == '.')
                    continue;
                int dig = ch - '0';
                if (mask & (1<<dig))
                    return true;
                mask |= (1<<dig);
            }
        }

        return false;
    }



public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i =0; i<board.size();i++) {
            if (hasRepitionInRow(board,i)) {
                return false;
            }

            if (hasRepitionInCol(board,i)) {
                return false;
            }
        }


        for(int i =0; i<board.size();i+=3) {
            for(int j =0 ; j< board[0].size();j+=3) {
                if (hasRepitionInSubBox(board,i,j)) {
                    return false;
                }
            }
        }


        return true;
    }
};
