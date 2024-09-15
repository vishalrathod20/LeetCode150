class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream stream(s);
        vector<string> words;
        string word;
         while (stream >> word) {
        words.push_back(word);
    }
     // Check if the lengths match
    if (pattern.length() != words.size()) {
        return false;
    }
     unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;

      for (int i = 0; i < pattern.length(); ++i) {
        char c = pattern[i];
        string w = words[i];
        
        if (charToWord.find(c) != charToWord.end()) {
            // Check if current character is mapped to a different word
            if (charToWord[c] != w) {
                return false;
            }
        } else {
            charToWord[c] = w;
        }
        
        if (wordToChar.find(w) != wordToChar.end()) {
            // Check if current word is mapped to a different character
            if (wordToChar[w] != c) {
                return false;
            }
        } else {
            wordToChar[w] = c;
        }
    }
    
    return true;
    }
};
