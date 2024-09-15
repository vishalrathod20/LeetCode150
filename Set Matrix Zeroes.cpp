void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<bool> zeroRows(rows, false);
    vector<bool> zeroCols(cols, false);

    // Step 1: Identify which rows and columns need to be set to 0
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = true;  // Mark the entire row to be zeroed
                zeroCols[j] = true;  // Mark the entire column to be zeroed
            }
        }
    }

    // Step 2: Set the marked rows to 0
    for (int i = 0; i < rows; ++i) {
        if (zeroRows[i]) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Set the marked columns to 0
    for (int j = 0; j < cols; ++j) {
        if (zeroCols[j]) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}


**************************************************************************************************************************************************
TC(N*M) AND SC(1)

class Solution {
public:
void setZeroes(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    bool zeroFirstRow = false;
    bool zeroFirstCol = false;
    
    // Determine if first row and first column need to be zeroed
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            zeroFirstCol = true;
            break;
        }
    }
    
    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            zeroFirstRow = true;
            break;
        }
    }
    
    // Use the first row and first column to mark zeroes
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Zero out cells based on the markers in the first row and first column
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Zero out the first row if needed
    if (zeroFirstRow) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
    
    // Zero out the first column if needed
    if (zeroFirstCol) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
}
};
