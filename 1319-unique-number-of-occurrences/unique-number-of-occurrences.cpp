class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // unordered_map<int,int>m;
        // unordered_set<int>s;
        // int n=arr.size();
        // for(int i=0;i<n;i++)
        // {
        //     m[arr[i]]++;
        // }
        // int mp=m.size();
        // for(auto it:m)
        // {
        //     s.insert(it.second);
        // }
        // int st=s.size();
        // if(mp==st)
        // return true;
        // else
        // return false;
        /*
            Second Approch 
        */
        vector<int>v(2001,0);
        for(int &i:arr){
            v[i+1000]++;
        }
        sort(v.begin(),v.end());
        for(int i=1;i<2001;i++){
            if(v[i]!=0 && v[i]==v[i-1]){
                return false;
            }
        }
        return true;
    }
};