class TrieNode{
    public:
    TrieNode* children[26];
    string word;
    TrieNode(){
        for(int i = 0; i<26; i++){
            children[i] = nullptr;
        }
        word = "";
    }
};
class Solution {
public:
    // Insert a word into Trie
    void insertWord(TrieNode* root, string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->word = word; // Mark end of the word
    }
    
    // Perform DFS to search the word in board
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return; // '#' means visited or invalid char
        
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word); // Found a word
            node->word = ""; // Avoid duplicate results
        }
        
        // Mark the current cell as visited
        board[i][j] = '#';
        
        // Explore all 4 directions (up, down, left, right)
        if (i > 0) dfs(board, i - 1, j, node, result); // Up
        if (i < board.size() - 1) dfs(board, i + 1, j, node, result); // Down
        if (j > 0) dfs(board, i, j - 1, node, result); // Left
        if (j < board[0].size() - 1) dfs(board, i, j + 1, node, result); // Right
        
        // Unmark the current cell
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        TrieNode* root = new TrieNode();
        
        // Step 1: Insert all words in Trie
        for (string word : words) {
            insertWord(root, word);
        }
        
        // Step 2: Traverse the board and use DFS to find words
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
};
