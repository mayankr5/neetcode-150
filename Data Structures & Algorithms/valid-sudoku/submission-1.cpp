class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    for(int k = 0; k < j; k++){
                        if(board[i][k] == board[i][j])
                            return false;
                    }
                    for(int k = 0; k < i; k++){
                        if(board[k][j] == board[i][j])
                            return false;
                    }
                    for(int k = (i/3)*3; k < (i/3)*3 + 3; k++){
                        for(int l = (j/3)*3; l < (j/3)*3 + 3; l++){
                            if((k != i && l != j) && board[k][l] == board[i][j])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
