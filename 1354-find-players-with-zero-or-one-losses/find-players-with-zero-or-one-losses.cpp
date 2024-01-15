class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> l;
        for (auto m : matches)
        {
            if (!l.count(m[0])) l[m[0]] = 0;
            l[m[1]]++;
        }
        
        vector<int> z, o;
        for (auto[k,l] : l)
        {
            if (l == 0) z.push_back(k);
            if (l == 1) o.push_back(k);
        }
        
        return {z,o};
    }
};