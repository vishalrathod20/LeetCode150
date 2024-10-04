class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int m = matrix.size();        // Number of rows
    int n = matrix[0].size();     // Number of columns

    // Step 1: Binary Search on Rows
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if target is within the range of the selected row
        if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
            // Step 2: Linear Search on the selected row
            for (int j = 0; j < n; ++j) {
                if (matrix[mid][j] == target) {
                    return true;
                }
            }
            return false;
        } else if (matrix[mid][0] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return false;
}
};
