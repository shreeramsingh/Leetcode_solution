class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        unordered_map<int,int>um;
        for(auto it:arr){
            um[it]++;
        }
        multimap<int,int>mm;
        for(auto it:um){
            mm.insert({it.second,it.first});
        }
        int cnt=0;
        for(auto it=mm.begin();it !=mm.end(); it++){
            k-=it->first;
            if(k<0) return mm.size()-cnt;

            cnt++;
        }
        return 0;
    }
};