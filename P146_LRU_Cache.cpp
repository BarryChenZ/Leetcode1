class LRUCache {
public:
    int cacheSize;
    map<int, int> cap;
    deque<int> dq;
    LRUCache(int capacity) {
        cap.clear();
        dq.clear();
        cacheSize = capacity;
    }
    
    int get(int key) {
        if(cap.find(key) == cap.end()){
            return -1;
        }
        else{
            //found
            deque<int>::iterator it = dq.begin();
            while(*it != key) it++;
            
            dq.erase(it);
            dq.push_front(key);
            
            return cap[key];
        }
    }
    
    void put(int key, int value) {
        if(cap.find(key) == cap.end()){
            if(dq.size() == cacheSize){
                int last = dq.back();
                dq.pop_back();
                cap.erase(last);
            }
        }
        else{
            deque<int>::iterator it = dq.begin();
            while(*it != key) it++;
            
            dq.erase(it);
            cap.erase(key);
        }
        dq.push_front(key);
        cap[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
