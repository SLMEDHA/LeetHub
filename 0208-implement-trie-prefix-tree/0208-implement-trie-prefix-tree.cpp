class TrieNode {
public:
    TrieNode* children[26];  // Each node has up to 26 children (a-z)
    bool isEndOfWord;        // True if this node represents the end of a word
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Trie {
    private:
    TrieNode* root;
public:
       Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the Trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';  // Get the index corresponding to the character
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();  // Create a new node if it doesn't exist
            }
            node = node->children[index];  // Move to the next node
        }
        node->isEndOfWord = true;  // Mark the end of the word
    }
    
    /** Returns true if the word is in the Trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;  // If the path for the word doesn't exist, return false
            }
            node = node->children[index];
        }
        return node->isEndOfWord;  // Return true if it's the end of a valid word
    }
    
    /** Returns true if there is any word in the Trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;  // If the path for the prefix doesn't exist, return false
            }
            node = node->children[index];
        }
        return true;  // If we successfully traverse the prefix, return true
    }
};