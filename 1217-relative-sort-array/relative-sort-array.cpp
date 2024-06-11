class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>m;
        for(int i=0;i<arr2.size();i++){
            m[arr2[i]]=i;
        }
        for(auto &num:arr1){
            if(!m.count(num)){
                m[num]=1e9;
            }
        }
        
        auto lambda =[&](int &num1, int &num2){
                if(m[num1]==m[num2]){
                    return num1 < num2;
                }
                return m[num1]< m[num2];
        };

        sort(arr1.begin(),arr1.end(),lambda);
        
        return arr1;
        
    }
};