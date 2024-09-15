class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result; // To store the starting indices of valid substrings
        if (s.empty() || words.empty()) return result; // Return empty result if input is invalid

        int word_len = words[0].size(); // Length of each word
        int word_count = words.size(); // Number of words
        int concat_len = word_len * word_count; // Total length of the concatenated substring

        if (s.size() < concat_len) return result; // If the string is shorter than the concatenated length, return empty result

        unordered_map<string, int> word_freq; // Map to store the frequency of each word
        for (const string& word : words) {
            word_freq[word]++; // Count the occurrences of each word in the words vector
        }

        // Iterate over all possible starting positions (0 to word_len - 1)
        for (int i = 0; i < word_len; ++i) {
            unordered_map<string, int> seen; // Map to track the words seen in the current window
            int left = i; // Left boundary of the sliding window
            int count = 0; // Number of valid words in the current window

            // Sliding window iteration over the string
            for (int j = i; j <= s.size() - word_len; j += word_len) {
                string word = s.substr(j, word_len); // Extract the current word
                if (word_freq.find(word) != word_freq.end()) { // Check if the word is in the word_freq map
                    seen[word]++; // Increment the count of the seen word
                    count++; // Increment the number of valid words seen

                    // While the count of the current word exceeds the frequency in the word_freq map
                    while (seen[word] > word_freq[word]) {
                        string left_word = s.substr(left, word_len); // Extract the word at the left boundary
                        seen[left_word]--; // Decrement the count of the left word
                        count--; // Decrement the number of valid words
                        left += word_len; // Move the left boundary of the sliding window
                    }

                    // If the number of valid words matches the number of words
                    if (count == word_count) {
                        result.push_back(left); // Add the starting index to the result
                    }
                } else {
                    // If the current word is not in word_freq, reset the sliding window
                    seen.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        return result; // Return the result containing starting indices of valid substrings
    }
};
