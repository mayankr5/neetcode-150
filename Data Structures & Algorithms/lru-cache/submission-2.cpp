class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtEnd(Node* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insertAtEnd(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->val = value;

            remove(node);
            insertAtEnd(node);

            return;
        }

        Node* node = new Node(key, value);

        mp[key] = node;
        insertAtEnd(node);

        if (mp.size() > capacity) {
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};