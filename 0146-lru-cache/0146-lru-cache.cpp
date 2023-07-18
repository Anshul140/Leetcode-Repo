class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* front;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
            front = NULL;
        }
};

class LRUCache {
public:
    unordered_map<int, Node*> cache;
    Node* first = new Node(-1, -1);
    Node* last = new Node(-1, -1);
    int sz;

    LRUCache(int capacity) {
        sz = capacity;
        first->next = last;
        last->front = first;
    }
    
    void deleteNode(Node* t) {
        Node* f = t->front;
        Node* n = t->next;
        f->next = n;
        n->front = f;
    }
    
    void addNode(Node* t) {
        Node* s = first->next;
        first->next = t;
        t->front = first;
        t->next = s;
        s->front = t;
    }
    
    int get(int key) {
        // key not found
        if(!cache.count(key)) return -1;
        
        // key-found, hence update its location in doubly linked-list
        Node* t = cache[key];
        deleteNode(t);
        addNode(t);
        cache[key] = first->next;
        return first->next->val;
    }
    
    void put(int key, int value) {
        // if key-value already exists
        if(cache.count(key)) {
            Node* t = cache[key];
            deleteNode(t);
            cache.erase(t->key);
        }
        
        if(cache.size() == sz) {
            // delete LRU key
            cache.erase(last->front->key);
            deleteNode(last->front);
        } 
        
        // add new key-value pair
        Node* newNode = new Node(key, value);
        addNode(newNode);
        cache[key] = first->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */