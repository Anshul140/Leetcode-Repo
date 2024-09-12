class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
public:
    int sz;
    int ctr;
    Node* first = new Node(-1, -1);
    Node* last = new Node(-1, -1);
    map<int, Node*> mp;

    void add(Node* cur){
        Node* temp = first->next;

        // first <-> cur
        first->next = cur;
        cur->prev = first;

        // cur <-> temp
        cur->next = temp;
        temp->prev = cur;
        mp[cur->key] = cur;
    }

    void update(int key, int val){
        Node* old = mp[key];
        Node* oldPrev = old->prev;
        Node* oldNext = old->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    void remove(){
        Node* end = last->prev;
        Node* prevEnd = end->prev;
        prevEnd->next = last;
        last->prev = prevEnd;
        mp.erase(end->key);
    }

    LRUCache(int capacity) {
        sz = capacity;
        first->next = last;
        last->prev = first;
        mp.clear();
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* cur = mp[key];
        Node* prevCur = cur->prev;
        prevCur->next = cur->next;
        cur->next->prev = prevCur;

        add(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            if(mp.size() == sz) remove();

            Node* cur = new Node(key, value);
            add(cur);
        } else {
            Node* cur = mp[key];
            Node* prevCur = cur->prev;
            prevCur->next = cur->next;
            cur->next->prev = prevCur;

            cur->val = value;
            add(cur);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */