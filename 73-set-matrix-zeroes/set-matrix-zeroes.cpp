class Solution {
    void setRowsAndColsToZero(vector<vector<int>>& matrix , int row , int col) {
        //set row to zero
        for(int j=0 ; j < matrix[0].size() ; j++) {
            matrix[row][j] = 0;
        }
        for(int i=0 ; i < matrix.size() ; i++) {
            matrix[i][col] = 0; 
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int , int>> coordinatesWithZero;
        for(int i=0 ; i < matrix.size() ; i++) {
            for(int j=0 ; j < matrix[0].size() ; j++) {
                if(matrix[i][j] == 0) {
                    coordinatesWithZero.push_back({i,j});
                }
            }
        }

        for(auto& p : coordinatesWithZero) {
            setRowsAndColsToZero(matrix , p.first , p.second);
        }

    }
};