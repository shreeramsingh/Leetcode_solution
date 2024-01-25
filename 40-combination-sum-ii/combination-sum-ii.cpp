class Solution {
public:
    void combo(int i, int target, vector<int>& candidates,vector<int>& ds,set<vector<int>>&ans){
        // if(i>=candidates.size()){
            
            if(target==0){
                // sort(ds.begin(),ds.end());
                ans.insert(ds);
                return;
            }
            
        // }
        if(target<0)
            return;
        for(int it=i; it<candidates.size() && candidates[it]<=target;it++){
        //if(candidates[i]<=target){
            if(it==i || candidates[it]!=candidates[it-1]){
            ds.push_back(candidates[it]);
            combo(it+1,target-candidates[it],candidates,ds,ans);
            ds.pop_back();
            }
        //}
        }
        //combo(i+1,target,candidates,ds,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        vector<int>ds;
        combo(0,target,candidates,ds,ans);
        return {ans.begin(),ans.end()};
    }
};