class TrieNode{
    public:
    unordered_map<char,TrieNode*>children;
    bool isEndword;

    TrieNode(){
        isEndword = false;

    }
};
class Trie {
    
    TrieNode*  root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(char c : word){
            if(!node->children.count(c)){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndword = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        
        for(char c : word){
            if(!node->children.count(c)){
                return false;
            }
            node = node->children[c];
        }
        return node->isEndword ;
    }
    
    bool startsWith(string prefix) {
       TrieNode* node = root;
        
        for(char c : prefix){
            if(!node->children.count(c)){
                return false;
            }
            node = node->children[c];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
