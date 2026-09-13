class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1;
        int row = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(target == matrix[mid][0]){
                return true;
            }
            if(target > matrix[mid][0]){
                l = mid + 1;
                row = mid;
            }else
                r = mid - 1;
        }
        if(row == -1)
            return false;
        
        l = 0; r = matrix[0].size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(matrix[row][mid] == target)
                return true;
            if(target > matrix[row][mid]){
                l = mid+1;
            }else
                r = mid-1;
        }
        return false;
    }
};
