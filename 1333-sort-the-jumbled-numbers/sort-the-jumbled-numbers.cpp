class Solution {
public:
    string getMapp(string &num, vector<int>& mapp){
        string mapedNum="";
        for(int i=0;i< num.size();i++){
            char ch = num[i];
            int intCh=ch -'0';
            mapedNum += to_string(mapp[intCh]);

        }
        return mapedNum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n= nums.size();

        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            string numStr = to_string(nums[i]);
            string mapoStr = getMapp(numStr, mapping);

            int mappedNum = stoi(mapoStr);

            vec.push_back({mappedNum,i});
        }
        sort(begin(vec), end(vec));
        vector<int> res;
        for(auto &i:vec){
            int org=i.second;
            res.push_back(nums[org]);
        }
        return res;
    }
};