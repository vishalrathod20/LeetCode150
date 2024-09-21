class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool isEndword;

    TrieNode(){
        isEndword = false;

    }
};
class WordDictionary {
    TrieNode* root;

    bool searchInNode(const string&word, TrieNode* node, int index){
        if(index == word.size()){
           return node->isEndword;
        }
        char ch = word[index];
        if (ch == '.') {
            // If the character is '.', check all possible children
            for (auto& child : node->children) {
                if (searchInNode(word, child.second, index + 1)) {
                    return true;
                }
            }
            return false; // No match found
        } else {
            // Normal character, check if it exists in children
            if (node->children.find(ch) != node->children.end()) {
                return searchInNode(word, node->children[ch], index + 1);
            } else {
                return false; // Character not found
            }
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for(char ch : word){
            if(node->children.find(ch) == node->children.end()){
                node->children[ch] = new TrieNode;
            }
            node = node->children[ch]; 
        }
         node->isEndword = true;
    }
    
    bool search(string word) {
        return searchInNode(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
