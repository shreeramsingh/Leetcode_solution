class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;

        int i=mp[val];
        int le=v.back();
        v.back()=val;

        v[i]=le;
        mp[le]=i;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=v.size();
        int ram=rand()%n;
        return v[ram];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */