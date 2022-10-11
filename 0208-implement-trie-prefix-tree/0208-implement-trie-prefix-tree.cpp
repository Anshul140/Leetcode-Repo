struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* t) {
        links[ch - 'a'] = t;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool getEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *t = root;
        for(char &ch: word) {
            if(!t->containsKey(ch)) {
                t->put(ch, new Node());
            }
            t = t->get(ch);
        }
        t->setEnd();
    }
    
    bool search(string word) {
        Node *t = root;
        for(char ch: word) {
            if(t->containsKey(ch)) {
                t = t->get(ch);
            }
            else {
                return false;
            }
        }
        
        return t->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node *t = root;
        for(char &ch: prefix) {
            if(t->containsKey(ch))
                t = t->get(ch);
            else
                return false;
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