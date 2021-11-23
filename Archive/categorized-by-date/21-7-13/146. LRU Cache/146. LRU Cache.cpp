/*
Number: 146
Topic: LRU Cache
Date: 2021/7/13
Rate: Medium
https://leetcode.com/problems/lru-cache/

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

* LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
* int get(int key) Return the value of the key if the key exists, otherwise return -1.
* void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Constraints:
* 1 <= capacity <= 3000
* 0 <= key <= 104
* 0 <= value <= 105
* At most 2 * 105 calls will be made to get and put.
*/

struct DoublyLinkedNode {
    int val;
    int key;
    DoublyLinkedNode* prev;
    DoublyLinkedNode* next;
    DoublyLinkedNode(int val, int key) : val(val), key(key), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DoublyLinkedNode* head;
    DoublyLinkedNode* tail;

public:
    DoublyLinkedList(DoublyLinkedNode* node) {
        this->head = node;
        this->tail = head;
    }

    void addNode(DoublyLinkedNode* node) {
        this->head->prev = node;
        node->next = this->head;
        node->prev = nullptr;
        this->head = node;
    }

    void moveToHead(DoublyLinkedNode* node) {
        if (!node->prev)
            return;
        if (node->next) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        } else {
            this->tail->prev->next = nullptr;
            this->tail = this->tail->prev;
        }
        this->head->prev = node;
        node->next = this->head;
        node->prev = nullptr;
        this->head = node;
    }

    void popTail() {
        DoublyLinkedNode* newNext = this->tail->prev;
        newNext->next = nullptr;
        delete this->tail;
        this->tail = newNext;
    }

    int getTailKey() {
        return this->tail->key;
    }

    void printList() {
        cout << "head: ";
        printList(this->head);
    }

    void printList(DoublyLinkedNode* node) {
        if (!node) {
            cout << endl;
            return;
        }
        cout << node->val << "->";
        printList(node->next);
    }

};


class LRUCache {
private:
    int count;
    int capacity;
    unordered_map<int, DoublyLinkedNode*> umap;
    DoublyLinkedList* cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->count = 0;
    }
    
    int get(int key) {
        if (umap.count(key)) {
            this->cache->moveToHead(umap[key]);
            return umap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (!umap.count(key)) {
            DoublyLinkedNode* node = new DoublyLinkedNode(value, key);
            this->umap[key] = node;

            if (count == 0) {
                this->cache = new DoublyLinkedList(node);
                count++;
            }
            else {
                this->cache->addNode(node);
                count++;
                if (this->count > this->capacity) {
                    this->umap.erase(this->cache->getTailKey());
                    this->cache->popTail();
                    count--;
                }
            }
        }
        else {
            umap[key]->val = value;
            this->cache->moveToHead(umap[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */