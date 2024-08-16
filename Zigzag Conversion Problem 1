#Zigzag Conversion
#CODE :- 
class Solution {
public:
   string convert(string s, int numRows) {
    if (numRows == 1 || s.size() <= numRows) {
        return s;
    }

    vector<string> rows(numRows);
    int currRow = 0;
    bool goingDown = false;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        rows[currRow] += c;
        
        // Change direction when reaching the top or bottom row
        if (currRow == 0 || currRow == numRows - 1) {
            goingDown = !goingDown;
        }
        
        // Move to the next row
        if (goingDown) {
            currRow++;
        } else {
            currRow--;
        }
    }

    // Concatenate all rows to get the final result
    string result;
    for (int i = 0; i < rows.size(); i++) {
        result += rows[i];
    }
    return result;
}

};
