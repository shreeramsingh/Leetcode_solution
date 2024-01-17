class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        unordered_set<int>s;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int mp=m.size();
        for(auto it:m)
        {
            s.insert(it.second);
        }
        int st=s.size();
        if(mp==st)
        return true;
        else
        return false;

    }
};