/*
    数据结构：
        minFre
        node(key, value, fre)
        key -> List:iterator keyMap
        Frequency -> List 方便删除 和 更新，top是最久未使用， tail是最近使用
    put:
        if key in keyMap:
            修改keyMap value Frequency
            原Frequency删掉，如果空并且为minFre，删除并更新minFre = minFre + 1
            新Frequency添加
            更新keyMap
        else:
            if size == capacity:
                删除minFre的头部
            新增node
            add to Frequency 尾部
            add to keyMap
            minFre = 1
    get:
        if key in keyToVal:
            get node, 修改Frequency
            原Frequency删掉，如果空并且为minFre，删除并更新minFre = minFre + 1
            新Frequency添加
            更新keyMap
        else:
            return -1;
*/
struct Node {
    int key;
    int value;
    int fre;
    Node(): key(0), value(0), fre(0) {};
    Node(int key, int value, int fre): key(key), value(value), fre(fre) {};
};
class LFUCache {
private:
    int minFre;
    int size;
    int capacity;
    unordered_map<int, list<Node>::iterator> keyMap;
    unordered_map<int, list<Node>> freMap;
public:
    LFUCache(int capacity): capacity(capacity), minFre(0), size(0) {
        freMap.clear();
        keyMap.clear();
    }
    
    int get(int key) {
        if (keyMap.count(key)) {
            list<Node>::iterator node = keyMap[key];
            int val = node->value;
            updateNode(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyMap.count(key)) {
            list<Node>::iterator node = keyMap[key];
            node->value = value;
            updateNode(node);
        } else {
            if (size == capacity) {
                auto it = freMap[minFre].back();
                keyMap.erase(it.key);
                freMap[minFre].pop_back();
                if (freMap[minFre].size() == 0) {
                    freMap.erase(minFre);
                }
                size--;
            }
            minFre = 1;
            freMap[1].push_front(Node(key, value, minFre));
            keyMap[key] = freMap[1].begin();
            size++;
        }
    }
    void updateNode(list<Node>::iterator node) {
        int key = node->key;
        int fre = node->fre;
        freMap[fre + 1].push_front(Node(node->key, node->value, fre + 1));
        keyMap[node->key] = freMap[fre + 1].begin();
        freMap[fre].erase(node);
        if (freMap[fre].size() == 0) {
            freMap.erase(fre);
            if (minFre == fre) minFre = minFre + 1;
        } 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
