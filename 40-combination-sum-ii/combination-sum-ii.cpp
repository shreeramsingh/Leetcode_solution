class Solution {
public:
    // void combo(int i, int target, vector<int>& candidates,vector<int>& ds,set<vector<int>>&ans){
    //     // if(i>=candidates.size()){
            
    //         if(target==0){
    //             // sort(ds.begin(),ds.end());
    //             ans.insert(ds);
    //             return;
    //         }
            
    //     // }
    //     if(target<0)
    //         return;
    //     for(int it=i; it<candidates.size() && candidates[it]<=target;it++){
    //     //if(candidates[i]<=target){
    //         if(it==i || candidates[it]!=candidates[it-1]){
    //         ds.push_back(candidates[it]);
    //         combo(it+1,target-candidates[it],candidates,ds,ans);
    //         ds.pop_back();
    //         }
    //     //}
    //     }
    //     //combo(i+1,target,candidates,ds,ans);
    // }
    //striver
    void comboination(int ind,int target,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            comboination(i+1,target-candidates[i],candidates,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       // set<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        comboination(0,target,candidates,ans,ds);
        //return {ans.begin(),ans.end()};
        return ans;
    }
};