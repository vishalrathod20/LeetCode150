LINK = https://leetcode.com/problems/text-justification/?envType=study-plan-v2&envId=top-interview-150

SOLUTION = 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
    int n = words.size();
    int i = 0;
    
    while (i < n) {
        int lineLength = 0;
        int start = i;
        // Calculate how many words can fit in the current line
        while (i < n && lineLength + words[i].length() + (i - start) <= maxWidth) {
            lineLength += words[i].length();
            i++;
        }
        
        string line = "";
        int gaps = i - start - 1;
        // If it's the last line or there's only one word in the line
        if (i == n || gaps == 0) {
            for (int j = start; j < i; j++) {
                line += words[j];
                if (j < i - 1) line += " ";
            }
            line += string(maxWidth - line.length(), ' '); // Fill remaining spaces
        } else {
            int spaces = (maxWidth - lineLength) / gaps;
            int extraSpaces = (maxWidth - lineLength) % gaps;
            
            for (int j = start; j < i; j++) {
                line += words[j];
                if (j < i - 1) {
                    line += string(spaces + (extraSpaces > 0 ? 1 : 0), ' ');
                    extraSpaces--;
                }
            }
        }
        
        result.push_back(line);
    }
    
    return result;

    }
};
