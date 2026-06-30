class Solution {
public:
    int find(vector<int>& parent, int x) {
        return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
    }
    void Union(vector<int>& parent, vector<long long>& size, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (size[a] >= size[b]) {
            size[a] += size[b];
            parent[b] = a;
        } else {
            size[b] += size[a];
            parent[a] = b;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<long long> size(26, 1);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for(auto &st:equations){
            if(st[1]=='='){
                Union(parent,size,st[0]-'a',st[3]-'a');
            }
        }
        for(auto &st:equations){
            if(st[1]=='!'){
                if(find(parent,st[0]-'a')==find(parent,st[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};