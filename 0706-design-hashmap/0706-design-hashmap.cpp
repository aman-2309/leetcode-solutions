class MyHashMap {
public:
    vector<list<pair<int,int>>> v;
    MyHashMap() {
        v.resize(1000);
    }
    
    void put(int key, int value) {
        for(auto ele:v[key%1000]){
            if(ele.first==key){
                v[key%1000].remove({ele.first,ele.second});
                break;
            }
        }
        v[key%1000].push_back({key,value});
        return;
    }
    
    int get(int key) {
        for(auto ele:v[key%1000]){
            if(ele.first==key){
                return ele.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto ele:v[key%1000]){
            if(ele.first==key){
                v[key%1000].remove({ele.first,ele.second});
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */